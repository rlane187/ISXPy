#pragma once
#include <cstdlib>
#include <cstdarg>
#include <cmath>
#include <pyconfig.h>
#ifdef _DEBUG
#undef Py_DEBUG
#endif
#include <Python.h>
#include "stackless_api.h"
#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <list>
#include <queue>
#pragma comment(lib, "d3d9.lib")
//#pragma comment(lib, "d3dx9.lib")
#include <d3d9.h>
//#include <d3dx9.h>