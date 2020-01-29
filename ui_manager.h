#pragma once

bool initialize_directx_hooks();
bool shutdown_directx_hooks();

typedef struct isxpy_log
{
	ImGuiTextBuffer     buf;
	bool                scroll_to_bottom;

	void    clear() { buf.clear(); }

	void    add_log(const char* fmt, ...) IM_PRINTFARGS(2)
	{
		va_list args;
		va_start(args, fmt);
		buf.appendfv(fmt, args);
		va_end(args);
		scroll_to_bottom = true;
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
		ImGui::End();
	}
} ISXPY_LOG, *P_ISXPY_LOG;

extern ISXPY_LOG logger;