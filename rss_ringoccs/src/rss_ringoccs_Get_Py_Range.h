#ifndef __RSS_RINGOCCS_GET_PY_RANGE_H__
#define __RSS_RINGOCCS_GET_PY_RANGE_H__

/*  To avoid compiler warnings about deprecated numpy stuff.                  */
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION

/*  The following are NON-STANDARD header files that MUST BE IN YOUR PATH.    *
 *  If you installed python using anaconda then Python.h should automatically *
 *  be included in your path. Also, if you are using the setup.py script      *
 *  provided then inclusion of these files should be done for you.            */
#include <Python.h>
#include <rss_ringoccs/include/rss_ringoccs_reconstruction.h>

void rssringoccs_Get_Py_Range(rssringoccs_TAUObj *tau, PyObject *rngreq);

#endif
