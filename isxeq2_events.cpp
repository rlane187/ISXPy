#include "ISXPyPCH.h"
#include "ISXPy.h"

boost::python::object eq2_actor_spawned_channel = boost::python::object();
boost::python::object eq2_actor_despawned_channel = boost::python::object();
boost::python::object eq2_on_quest_offered_channel = boost::python::object();

void initialize_eq2_events()
{	
	setup_event("isxeq2", "eq2_actor_spawned_channel", eq2_actor_spawned_channel, "EQ2_ActorSpawned", eq2_actor_spawned);
	setup_event("isxeq2", "eq2_actor_despawned_channel", eq2_actor_despawned_channel, "EQ2_ActorDespawned", eq2_actor_despawned);
	setup_event("isxeq2", "eq2_on_quest_offered_channel", eq2_on_quest_offered_channel, "EQ2_onQuestOffered", eq2_on_quest_offered);
}

void shutdown_eq2_events()
{
	stop_event(eq2_actor_spawned_channel, "EQ2_ActorSpawned", eq2_actor_spawned);
	stop_event(eq2_actor_despawned_channel, "EQ2_ActorDespawned", eq2_actor_despawned);
	stop_event(eq2_on_quest_offered_channel, "EQ2_onQuestOffered", eq2_on_quest_offered);
}

void eq2_actor_spawned(int argc, char* argv[], PLSOBJECT p_lsobject)
{
	if (argc < 4)
		return;
	channel c(eq2_actor_spawned_channel);
	if (Py_IsInitialized())
	{
		eq2_actor_spawned_args actor_spawned_args;
		tasklet t;
		actor_spawned_args.set_id(boost::lexical_cast<unsigned int>(argv[0]));
		actor_spawned_args.set_name(std::string(argv[1]));
		actor_spawned_args.set_level(boost::lexical_cast<unsigned int>(argv[2]));
		actor_spawned_args.set_type(std::string(argv[3]));
		boost::python::list args_list;
		args_list.append(actor_spawned_args);
		const boost::python::tuple args(args_list);
		if (t.bind_ex(eq2_actor_spawned_channel.attr("send"), args))
			t.run();
	}
}

void eq2_actor_despawned(int argc, char* argv[], PLSOBJECT p_lsobject)
{
	if (argc < 2)
		return;
	channel c(eq2_actor_despawned_channel);
	if (Py_IsInitialized())
	{
		eq2_actor_despawned_args actor_despawned_args;
		tasklet t;
		actor_despawned_args.set_id(boost::lexical_cast<unsigned int>(argv[0]));
		actor_despawned_args.set_name(std::string(argv[1]));
		boost::python::list args_list;
		args_list.append(actor_despawned_args);
		const boost::python::tuple args(args_list);
		if (t.bind_ex(eq2_actor_despawned_channel.attr("send"), args))
			t.run();
	}
}

void eq2_on_quest_offered(int argc, char* argv[], PLSOBJECT p_lsobject)
{
	if (argc < 4)
		return;
	eq2_on_quest_offered_args on_quest_offered_args;
	tasklet t;
	on_quest_offered_args.set_name(std::string(argv[0]));
	on_quest_offered_args.set_description(std::string(argv[1]));
	on_quest_offered_args.set_level(boost::lexical_cast<unsigned int>(argv[2]));
	on_quest_offered_args.set_status_reward(boost::lexical_cast<unsigned int>(argv[3]));
	boost::python::list args_list;
	args_list.append(on_quest_offered_args);
	const boost::python::tuple args(args_list);
	if (t.bind_ex(eq2_on_quest_offered_channel.attr("send"), args))
		t.run();
}