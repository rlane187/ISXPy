#pragma once

bool initialize_directx_hooks();
bool shutdown_directx_hooks();

typedef struct isxpy_log
{
	ImGuiTextBuffer buf;
	char input_buffer[256] = { 0 };	
	bool scroll_to_bottom;
	int  history_pos = -1;    // -1: new line, 0..History.Size-1 browsing history.
	ImVector<char*> history;
	ImVector<char*> items;
	ImVector<const char*> commands;

	static int   Stricmp(const char* str1, const char* str2) { int d; while ((d = toupper(*str2) - toupper(*str1)) == 0 && *str1) { str1++; str2++; } return d; }
	static int   Strnicmp(const char* str1, const char* str2, int n) { int d = 0; while (n > 0 && (d = toupper(*str2) - toupper(*str1)) == 0 && *str1) { str1++; str2++; n--; } return d; }
	static char* Strdup(const char *str) { size_t len = strlen(str) + 1; void* buff = malloc(len); return (char*)memcpy(buff, (const void*)str, len); }
	
	void clear()
	{
		buf.clear();
	}

	void add_log(const char* fmt, ...) IM_PRINTFARGS(2)
	{
		va_list args;
		va_start(args, fmt);
		buf.appendfv(fmt, args);
		va_end(args);
		scroll_to_bottom = true;
	}

	void exec_command(const char* command_line)
	{
		add_log("# %s\n", command_line);
		// Insert into history. First find match and delete it so it can be pushed to the back. This isn't trying to be smart or optimal.
		history_pos = -1;
		for (int i = history.Size - 1; i >= 0; i--)
			if (Stricmp(history[i], command_line) == 0)
			{
				free(history[i]);
				history.erase(history.begin() + i);
				break;
			}
		history.push_back(Strdup(command_line));
		// Process command
		if (Stricmp(command_line, "CLEAR") == 0)
		{
			clear();
		}
		else if (Stricmp(command_line, "HELP") == 0)
		{
			add_log("Commands:");
			for (int i = 0; i < commands.Size; i++)
				add_log("- %s", commands[i]);
		}
		else if (Stricmp(command_line, "HISTORY") == 0)
		{
			for (int i = history.Size >= 10 ? history.Size - 10 : 0; i < history.Size; i++)
				add_log("%3d: %s\n", i, history[i]);
		}
		else
		{
			add_log("Unknown command: '%s'\n", command_line);
		}
	}
	
	static int TextEditCallbackStub(ImGuiTextEditCallbackData* data) // In C++11 you are better off using lambdas for this sort of forwarding callbacks
	{
		isxpy_log* console = (isxpy_log*)data->UserData;
		return console->TextEditCallback(data);
	}
	
	int TextEditCallback(ImGuiTextEditCallbackData* data)
	{
		//add _log("cursor: %d, selection: %d-%d", data->CursorPos, data->SelectionStart, data->SelectionEnd);
		switch (data->EventFlag)
		{
		case ImGuiInputTextFlags_CallbackCompletion:
		{
			// Example of TEXT COMPLETION
			// Locate beginning of current word
			const char* word_end = data->Buf + data->CursorPos;
			const char* word_start = word_end;
			while (word_start > data->Buf)
			{
				const char c = word_start[-1];
				if (c == ' ' || c == '\t' || c == ',' || c == ';')
					break;
				word_start--;
			}
			// Build a list of candidates
			ImVector<const char*> candidates;
			for (int i = 0; i < commands.Size; i++)
				if (Strnicmp(commands[i], word_start, (int)(word_end - word_start)) == 0)
					candidates.push_back(commands[i]);
			if (candidates.Size == 0)
			{
				// No match
				add_log("No match for \"%.*s\"!\n", (int)(word_end - word_start), word_start);
			}
			else if (candidates.Size == 1)
			{
				// Single match. Delete the beginning of the word and replace it entirely so we've got nice casing
				data->DeleteChars((int)(word_start - data->Buf), (int)(word_end - word_start));
				data->InsertChars(data->CursorPos, candidates[0]);
				data->InsertChars(data->CursorPos, " ");
			}
			else
			{
				// Multiple matches. Complete as much as we can, so inputing "C" will complete to "CL" and display "CLEAR" and "CLASSIFY"
				int match_len = (int)(word_end - word_start);
				for (;;)
				{
					int c = 0;
					bool all_candidates_matches = true;
					for (int i = 0; i < candidates.Size && all_candidates_matches; i++)
						if (i == 0)
							c = toupper(candidates[i][match_len]);
						else if (c == 0 || c != toupper(candidates[i][match_len]))
							all_candidates_matches = false;
					if (!all_candidates_matches)
						break;
					match_len++;
				}
				if (match_len > 0)
				{
					data->DeleteChars((int)(word_start - data->Buf), (int)(word_end - word_start));
					data->InsertChars(data->CursorPos, candidates[0], candidates[0] + match_len);
				}
				// List matches
				add_log("Possible matches:\n");
				for (int i = 0; i < candidates.Size; i++)
					add_log("- %s\n", candidates[i]);
			}
			break;
		}
		case ImGuiInputTextFlags_CallbackHistory:
		{
			// Example of HISTORY
			const int prev_history_pos = history_pos;
			if (data->EventKey == ImGuiKey_UpArrow)
			{
				if (history_pos == -1)
					history_pos = history.Size - 1;
				else if (history_pos > 0)
					history_pos--;
			}
			else if (data->EventKey == ImGuiKey_DownArrow)
			{
				if (history_pos != -1)
					if (++history_pos >= history.Size)
						history_pos = -1;
			}
			// A better implementation would preserve the data on the current input line along with cursor position.
			if (prev_history_pos != history_pos)
			{
				data->CursorPos = data->SelectionStart = data->SelectionEnd = data->BufTextLen = (int)snprintf(data->Buf, (size_t)data->BufSize, "%s", (history_pos >= 0) ? history[history_pos] : "");
				data->BufDirty = true;
			}
		}
		}
		return 0;
	}
	
	void draw(const char* title, bool* p_opened = NULL)
	{
		ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_FirstUseEver);
		ImGui::Begin(title, p_opened);
		if (ImGui::Button("Clear")) clear();
		ImGui::SameLine();
		bool copy = ImGui::Button("Copy");
		ImGui::Separator();
		ImGui::BeginChild("scrolling");
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 1));
		if (copy) ImGui::LogToClipboard();
		ImGui::TextUnformatted(buf.begin());
		if (scroll_to_bottom)
			ImGui::SetScrollHere(1.0f);
		scroll_to_bottom = false;
		ImGui::PopStyleVar();
		ImGui::EndChild();
		ImGui::Separator();
		ImGui::BeginChild("console");
		if (ImGui::InputText("Input", input_buffer, IM_ARRAYSIZE(input_buffer), ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackCompletion | ImGuiInputTextFlags_CallbackHistory, &TextEditCallbackStub, (void*)this))
		{
			char* input_end = input_buffer + strlen(input_buffer);
			while (input_end > input_buffer && input_end[-1] == ' ') input_end--; *input_end = 0;
			if (input_buffer[0])
				exec_command(input_buffer);
			strcpy(input_buffer, "");
		}
		// Demonstrate keeping auto focus on the input box
		if (ImGui::IsItemHovered() || (ImGui::IsAnyWindowFocused() && !ImGui::IsAnyItemActive() && !ImGui::IsMouseClicked(0)))
			ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget

		
		ImGui::End();
	}

	isxpy_log()
	{
		clear();
		commands.push_back("HELP");
		commands.push_back("HISTORY");
		commands.push_back("CLEAR");
		commands.push_back("CLASSIFY");  // "classify" is here to provide an example of "C"+[tab] completing to "CL" and displaying matches.
		add_log("Welcome to ISXPY!");
	}

	~isxpy_log()
	{
		clear();
		for (int i = 0; i < history.Size; i++)
			free(history[i]);
	}
	
} ISXPY_LOG, *P_ISXPY_LOG;

extern ISXPY_LOG logger;