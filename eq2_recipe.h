#pragma once

class eq2_recipe : public ls_object
{
public:
	eq2_recipe() = default;
	~eq2_recipe() = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_recipe(const ls_object& other);
	eq2_recipe(const eq2_recipe& other) = default;
	eq2_recipe(eq2_recipe&& other) noexcept = default;
	eq2_recipe& operator=(const ls_object& other) override;
	eq2_recipe& operator=(ls_object&& other) noexcept override;
	ls_string get_name();
};