#pragma once

class py_string : public ls_object
{
public:
	py_string() = default;
	~py_string() = default;
	py_string(const py_string& other) = default;
	py_string(py_string&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_string(const LSOBJECT& other);
	py_string& operator=(const py_string& other);
	py_string& operator=(py_string&& other) noexcept;
	std::string get_value();
	std::string mid(const unsigned int& position, const unsigned int& length);
	std::string left(const int& num_chars);
	std::string right(const int& num_chars);
	int64_t find(const std::string& substring);
	int64_t get_length();
	std::string get_upper();
	std::string get_lower();
	int compare(const std::string& text);
	int compare_cs(const std::string& text);
	bool equal(const std::string& text);
	bool not_equal(const std::string& text);
	bool equal_cs(const std::string& text);
	bool not_equal_cs(const std::string& text);
	int count(const std::string& text);
	std::string token(const signed int& token_number, const std::string& separator);
	std::string escape();
	std::string escape_quotes();
	std::string replace(const std::string& formula);
	std::string get_at(const unsigned int& char_at);
	std::wstring get_unicode_string();
	std::string url_encode();
	bool not_null_or_empty();
};