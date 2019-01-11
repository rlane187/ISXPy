#pragma once

class ls_string : public ls_object
{
public:
	ls_string() = default;
	~ls_string() = default;
	ls_string(const ls_string& other) = default;
	ls_string(ls_string&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	ls_string(const LSOBJECT& other);
	ls_string& operator=(const ls_string& other);
	ls_string& operator=(ls_string&& other) noexcept;
	std::string get_value();
	bool get_is_valid() const;

	bool operator==(const std::string& other);
	bool operator!=(const std::string& other);
	

	// ReSharper disable once CppNonExplicitConversionOperator
	operator std::string() { return this->get_value(); }


	friend
		std::ostream& operator<<(std::ostream& s, const ls_string& str) { return s << ls_string(str).get_value(); }
};

bool operator==(const std::string& lhs, const ls_string& rhs);
bool operator!=(const std::string& lhs, const ls_string& rhs);