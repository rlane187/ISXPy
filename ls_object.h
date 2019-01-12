#pragma once

class ls_object
{
public:
	ls_object();
	ls_object(const ls_object& other);
	ls_object(ls_object&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	ls_object(const LSOBJECT& other);
	virtual ~ls_object();
	ls_object& operator=(const ls_object& other);
	ls_object& operator=(ls_object&& other) noexcept;	
	void execute_method(const char* method, int argc = 0, char* argv[] = nullptr);
	bool get_bool_from_lso();
	int get_byte_from_lso();
	float get_float_from_lso();
	int get_int_from_lso();
	int64_t get_int64_from_lso();
	const LSOBJECT& get_lso() const;
	ls_object get_member(const char* member, int argc = 0, char* argv[] = nullptr);
	std::string get_string_from_lso();
	std::string get_mutable_string_from_lso();
	unsigned int get_uint_from_lso();
	template <class T>
	int get_list_from_index_method(const char* method, const char* index_type, const char* query, boost::python::list& python_list);
protected:
	LSOBJECT lsobject_;
private:	
	bool has_inherited_member(const char* member) const;
	bool has_inherited_method(const char* method) const;
	bool has_member(const char* member) const;
	bool has_method(const char* method) const;
};