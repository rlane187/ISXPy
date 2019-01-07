#pragma once

void initialize_eq2_events();
void shutdown_eq2_events();
void eq2_actor_spawned(int argc, char* argv[], PLSOBJECT p_lsobject);
void eq2_actor_despawned(int argc, char* argv[], PLSOBJECT p_lsobject);
void eq2_on_quest_offered(int argc, char* argv[], PLSOBJECT p_lsobject);