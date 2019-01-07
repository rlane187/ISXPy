#pragma once

void redirect_output_to_console();
void adjust_path();
int quit_script();
int get_frame_count();
void setup_event(const char* module_name, const char* channel_name, boost::python::object& channel_object,
                 const char* event_name, fLSEventTarget callback);
