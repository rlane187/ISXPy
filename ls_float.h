#pragma once

class ls_float : public ls_object
{
public:
	ls_float() = default;
	~ls_float() = default;
	ls_float(const ls_float& other) = default;;
	ls_float(ls_float&& other) noexcept = default;;
	explicit ls_float(const LSOBJECT& other);
	ls_float& operator=(const ls_float& other);
	ls_float& operator=(ls_float&& other) noexcept;
	float get_value();
	
};