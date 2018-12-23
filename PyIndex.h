#pragma once

class PyIndex : public PyLSObject
{
public:
	PyIndex() = default;
	PyIndex(LSOBJECT& ls_object);

};