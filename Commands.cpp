#include "ISXPy.h"
#include <Python.h>
#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

using namespace boost::python;

int CMD_Py(int argc, char *argv[])
{
	printf("Running Py...");
	//wchar_t *program = Py_DecodeLocale(argv[0], NULL);
	//if (program == NULL) {
	//	fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
	//	exit(1);
	//}
	//Py_SetProgramName(program);  /* optional but recommended */

	//Py_SetPythonHome(path.c_str());
	Py_Initialize();
	//PyRun_SimpleString("from time import time,ctime\n"
	//	"print('Today is', ctime(time()))\n");
	//if (Py_FinalizeEx() < 0) {
	//	exit(120);
	//}
	//PyMem_RawFree(program);
	return 0;
}