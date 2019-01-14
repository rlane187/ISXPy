#pragma once

class eq2_item : public ls_object
{
public:
	eq2_item();
	~eq2_item();
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_item(const ls_object& other);
	eq2_item(const eq2_item& other);
	eq2_item(eq2_item&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_item(const LSOBJECT& other);
	eq2_item& operator=(const eq2_item& other);
	eq2_item& operator=(eq2_item&& other) noexcept;
	ls_string get_name();
};