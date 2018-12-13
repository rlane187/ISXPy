#pragma once
#define Py_NO_ENABLE_SHARED
#include <stdlib.h>
#include <stdarg.h>
#include <pyconfig.h>
#ifdef _DEBUG
#undef Py_DEBUG
#endif
#include <Python.h>
#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <list>