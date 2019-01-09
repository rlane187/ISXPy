#pragma once

class py_bool : public py_lsobject
{
public:
	py_bool() = default;
	~py_bool() = default;
	py_bool(const py_bool& other) = default;
	py_bool(py_bool&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_bool(const LSOBJECT& other);
	py_bool& operator=(const py_bool& other);
	py_bool& operator=(py_bool&& other) noexcept;
	bool get_value();
	void toggle();
	void set(const std::string& formula);
	bool operator!();

	// ReSharper disable once CppNonExplicitConversionOperator
	operator bool() { return this->get_value(); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator int() { return int(this->get_value()); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator long() { return long(this->get_value()); }

	friend	std::ostream& operator<<(std::ostream& s, const py_bool& b)
	{
		if (py_bool(b).get_value())
			return s << "True";
		return s << "False";
	}
};