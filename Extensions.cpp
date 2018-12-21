#include "ISXPyPCH.h"
#include "ISXPy.h"

BOOST_PYTHON_MODULE(pyisxeq2)
{
	using namespace boost::python;

	class_<TLOBase>("TLOBase", no_init);

	class_<LSObject>("LSObject", no_init);

	class_<PyISXEQ2, bases<TLOBase>>("isxeq2")
		.add_property("version", &PyISXEQ2::get_version)
		.add_property("api_version", &PyISXEQ2::get_api_version)
		.add_property("is_ready", &PyISXEQ2::get_is_ready)
		.def("popup", &PyISXEQ2::popup);

	class_<PyEffectInfo, bases<LSObject>>("effect_info")
		.add_property("description", &PyEffectInfo::get_description)
		.add_property("name", &PyEffectInfo::get_name)
		.add_property("type", &PyEffectInfo::get_type);

	class_<PyEffect, bases<LSObject>>("effect")
		.add_property("back_drop_icon_id", &PyEffect::get_back_drop_icon_id)
		.add_property("current_increments", &PyEffect::get_current_increments)
		.add_property("duration", &PyEffect::get_duration)
		.add_property("effect_info", &PyEffect::get_effect_info)
		.add_property("id", &PyEffect::get_id)
		.add_property("is_effect_info_available", &PyEffect::get_is_effect_info_available)
		.add_property("main_icon_id", &PyEffect::get_main_icon_id)
		.add_property("max_duration", &PyEffect::get_max_duration)
		.add_property("back_drop_icon_id", &PyEffect::get_back_drop_icon_id);

	class_<PyMaintained, bases<LSObject>>("maintained")
		.add_property("concentration_cost", &PyMaintained::get_concentration_cost)
		.add_property("current_increments", &PyMaintained::get_current_increments)
		.add_property("damage_remaining", &PyMaintained::get_damage_remaining)
		.add_property("duration", &PyMaintained::get_duration)
		.add_property("is_beneficial", &PyMaintained::get_is_beneficial)
		.add_property("max_duration", &PyMaintained::get_max_duration)
		.add_property("name", &PyMaintained::get_name)
		.add_property("target", &PyMaintained::get_target)
		.add_property("target_type", &PyMaintained::get_target_type)
		.add_property("uses_remaining", &PyMaintained::get_uses_remaining);

	class_<PyActor, bases<LSObject>>("actor")
		.add_property("name", &PyActor::get_name);

	class_<PyCharacter, bases<LSObject>>("character")
		.add_property("archetype", &PyCharacter::get_archetype)
		.add_property("at_char_select", &PyCharacter::get_at_char_select)
		.add_property("base_strength", &PyCharacter::get_base_strength)
		.add_property("breath", &PyCharacter::get_breath)
		.add_property("char_class", &PyCharacter::get_class)
		.add_property("copper", &PyCharacter::get_copper)
		.add_property("current_health", &PyCharacter::get_current_health)
		.add_property("current_power", &PyCharacter::get_current_power)
		.add_property("effective_level", &PyCharacter::get_effective_level)
		.add_property("exp_bubble", &PyCharacter::get_exp_bubble)
		.add_property("exp_current", &PyCharacter::get_exp_current)
		.add_property("exp_debt_current", &PyCharacter::get_exp_debt_current)
		.add_property("exp_next_level", &PyCharacter::get_exp_next_level)
		.add_property("exp_percent", &PyCharacter::get_exp_percent)
		.add_property("gender", &PyCharacter::get_gender)		
		.add_property("gold", &PyCharacter::get_gold)
		.add_property("heading", &PyCharacter::get_heading)
		.add_property("health_regen", &PyCharacter::get_health_regen)
		.add_property("in_game_world", &PyCharacter::get_in_game_world)
		.add_property("is_moving", &PyCharacter::get_is_moving)
		.add_property("level", &PyCharacter::get_level)
		.add_property("max_conc", &PyCharacter::get_max_conc)
		.add_property("max_health", &PyCharacter::get_max_health)
		.add_property("max_power", &PyCharacter::get_max_power)
		.add_property("name", &PyCharacter::get_name)
		.add_property("platinum", &PyCharacter::get_platinum)
		.add_property("power_regen", &PyCharacter::get_power_regen)
		.add_property("race", &PyCharacter::get_race)
		.add_property("silver", &PyCharacter::get_silver)
		.add_property("strength", &PyCharacter::get_strength)
		.add_property("subclass", &PyCharacter::get_subclass)
		.add_property("ts_archetype", &PyCharacter::get_ts_archetype)
		.add_property("ts_class", &PyCharacter::get_ts_class)
		.add_property("ts_level", &PyCharacter::get_ts_level)
		.add_property("ts_subclass", &PyCharacter::get_ts_subclass)
		.add_property("ts_vitality", &PyCharacter::get_ts_vitality)
		.add_property("ts_vitality_lower_marker", &PyCharacter::get_ts_vitality_lower_marker)
		.add_property("ts_vitality_overflow_marker", &PyCharacter::get_ts_vitality_overflow_marker)
		.add_property("ts_vitality_upper_marker", &PyCharacter::get_ts_vitality_upper_marker)
		.add_property("used_conc", &PyCharacter::get_used_conc)
		.add_property("water_depth", &PyCharacter::get_water_depth)
		.add_property("vitality", &PyCharacter::get_vitality)
		.add_property("vitality_lower_marker", &PyCharacter::get_vitality_lower_marker)
		.add_property("vitality_overflow_marker", &PyCharacter::get_vitality_overflow_marker)
		.add_property("vitality_upper_marker", &PyCharacter::get_vitality_upper_marker)
		.add_property("x", &PyCharacter::get_x)
		.add_property("y", &PyCharacter::get_y)
		.add_property("z", &PyCharacter::get_z)
		.def("check_collision", &PyCharacter::check_collision)
		.def("get_beneficial_effects", &PyCharacter::get_beneficial_effects)
		.def("get_detrimental_effects", &PyCharacter::get_detrimental_effects)
		.def("get_effects", &PyCharacter::get_effects)
		.def("get_maintained", &PyCharacter::get_maintained)
		.def("heading_to", &PyCharacter::heading_to)
		.def("heading_to_as_compass_bearing", &PyCharacter::heading_to_as_compass_bearing);
}

void Initialize_Module_PyISXEQ2()
{
	PyImport_AppendInittab("pyisxeq2", PyInit_pyisxeq2);
}

void Shutdown_Module_PyISXEQ2()
{

}