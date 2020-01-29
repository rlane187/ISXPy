#include "ISXPyPCH.h"
#include "ISXPy.h"
#include <Psapi.h>
#include <cstdint>

struct pattern_byte
{
	struct pattern_nibble
	{
		unsigned char data;
		bool wildcard;
	} nibble[2];
};

static string format_pattern(string pattern_text)
{
	string result;
	const size_t len = pattern_text.length();
	for (size_t i = 0; i < len; i++)
		if (pattern_text[i] == '?' || isxdigit(pattern_text[i]))
			result += toupper(pattern_text[i]);  // NOLINT(bugprone-string-integer-assignment)
	return result;
}

static int hex_ch_to_int(const char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	else if (ch >= 'A' && ch <= 'F')
		return ch - 'A' + 10;
	else if (ch >= 'a' && ch <= 'f')
		return ch - 'a' + 10;
	return 0;
}

static bool transform_pattern(string pattern_text, std::vector<pattern_byte> & pattern)
{
	pattern.clear();
	pattern_text = format_pattern(pattern_text);
	auto len = pattern_text.length();
	if (!len)
		return false;

	if (len % 2) // not a multiple of 2
	{
		pattern_text += '?';
		len++;
	}

	pattern_byte new_byte{};
	for (size_t i = 0, j = 0; i < len; i++)
	{
		if (pattern_text[i] == '?') // wildcard
		{
			new_byte.nibble[j].wildcard = true; // match anything
		}
		else //hex
		{
			new_byte.nibble[j].wildcard = false;
			new_byte.nibble[j].data = hex_ch_to_int(pattern_text[i]) & 0xF;
		}

		j++;
		if (j == 2) // two nibbles = one byte
		{
			j = 0;
			pattern.push_back(new_byte);
		}
	}
	return true;
}

static bool match_byte(const unsigned char byte, const pattern_byte & pattern_byte)
{
	auto matched = 0;

	const unsigned char n1 = (byte >> 4) & 0xF;
	if (pattern_byte.nibble[0].wildcard)
		matched++;
	else if (pattern_byte.nibble[0].data == n1)
		matched++;

	const unsigned char n2 = byte & 0xF;
	if (pattern_byte.nibble[1].wildcard)
		matched++;
	else if (pattern_byte.nibble[1].data == n2)
		matched++;

	return (matched == 2);
}

size_t find_pattern(const char* module, const char* pattern_text, const size_t offset, const int occurrence)
{
	const HANDLE h_process = GetCurrentProcess();
	const HMODULE h_module = GetModuleHandle(module);
	MODULEINFO module_info;
	GetModuleInformation(h_process, h_module, &module_info, sizeof(module_info));

	const auto data_begin = reinterpret_cast<unsigned char*>(h_module);
	const auto data_end = data_begin + module_info.SizeOfImage;
	const std::vector<unsigned char> data(data_begin, data_end);

	
	// Build vectored pattern..
	std::vector<pattern_byte> pattern_data;
	if (!transform_pattern(pattern_text, pattern_data))
		return -1;

	// The result count for multiple results..
	auto result_count = 0;
	auto scan_start = data.begin();

	while (true)
	{
		// Search for the pattern..
		auto ret = search(scan_start, data.end(), pattern_data.begin(), pattern_data.end(), match_byte);

		// Did we find a match..
		if (ret != data.end())
		{
			// If we hit the usage count, return the result..
			if (occurrence == 0 || result_count == occurrence)
				return size_t(h_module) + distance(data.begin(), ret) + offset;

			// Increment the found count and scan again..
			result_count++;
			scan_start = ++ret;
		}
		else
			break;
	}

	return -1;
}
