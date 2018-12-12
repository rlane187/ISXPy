#include "ISXPy.h"
#include <Python.h>
#include "globals.h"
#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

using namespace boost::python;

int CMD_Py(int argc, char *argv[])
{
	Py_Initialize();
	PyObject *moduleMainString = PyUnicode_FromString("__main__");
	PyObject *moduleMain = PyImport_Import(moduleMainString);

	PyRun_SimpleString(
		"def mul(a, b):                                 \n"\
		"   return a * b                                \n"\
	);

	PyObject *func = PyObject_GetAttrString(moduleMain, "mul");
	PyObject *args = PyTuple_Pack(2, PyFloat_FromDouble(3.0), PyFloat_FromDouble(4.0));

	PyObject *result = PyObject_CallObject(func, args);

	printf("mul(3,4): %.2f\n", PyFloat_AsDouble(result)); // 12
	Py_Finalize();

	return 0;
}