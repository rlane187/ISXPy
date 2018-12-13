#include "ISXPyPCH.h"
#include "ISXPy.h"
#include "globals.h"

int CMD_Py(int argc, char *argv[])
{
	printf(PythonHome);
	//Py_Initialize();
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
	//Py_Finalize();

	return 0;
}

int CMD_HelloWorld(int argc, char *argv[])
{
	using namespace boost::python;
	try
	{
		object main_module = import("__main__");
		object main_namespace = main_module.attr("__dict__");
		import("output");
		std::string stdOut = 
		   "import sys\n\
			import output\n\
			outputHandler = output.OutputHandler()\n\
			sys.stdout = outputHandler\n\
			print(\'Hello World\')\n\
			";
		PyRun_SimpleString(stdOut.c_str());
		return 0;
	}
	catch (const error_already_set&)
	{
		PyErr_Print();
		return 1;
	}
}