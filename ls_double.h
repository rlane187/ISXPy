#pragma once

class ls_double : public ls_object
{
public:
	ls_double() = default;
	~ls_double() = default;
	ls_double(const ls_double& other) = default;;
	ls_double(ls_double&& other) noexcept = default;;
	explicit ls_double(const LSOBJECT& other);
	ls_double& operator=(const ls_double& other);
	ls_double& operator=(ls_double&& other) noexcept;
	double get_value();
};