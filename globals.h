#pragma once

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

EXTERN_C char DllPath[MAX_PATH];
EXTERN_C wchar_t DllPathW[MAX_PATH];
EXTERN_C char PythonScriptPath[MAX_PATH];
EXTERN_C wchar_t PythonPathW[MAX_VARSTRING];

EXTERN_C unsigned int frame_count;

EXTERN_C std::map<std::string, tasklet*> tasklet_map;

EXTERN_C boost::python::object pulse_channel;

EXTERN_C boost::python::object eq2_actor_spawned_channel;
EXTERN_C boost::python::object eq2_actor_despawned_channel;
EXTERN_C boost::python::object eq2_on_quest_offered_channel;