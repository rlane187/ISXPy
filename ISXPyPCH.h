#pragma once
#include <stdlib.h>
#include <stdarg.h>

#include <pyconfig.h>
#ifdef _DEBUG
#undef Py_DEBUG
#endif

#include <Python.h>

//#define BOOST_PYTHON_STATIC_LIB

//#include <boost/python.hpp>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <list>

//#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
//#include <boost/python/suite/indexing/map_indexing_suite.hpp>