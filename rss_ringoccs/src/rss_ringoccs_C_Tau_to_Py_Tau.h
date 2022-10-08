#ifndef __RSS_RINGOCCS_C_TAU_TO_PY_TAU_H__
#define __RSS_RINGOCCS_C_TAU_TO_PY_TAU_H__

/* To avoid seg faults due to numpy, this must be defined before any numpy    *
 *  includes and must be also defined in any other linked *.c files that      *
 *  that utilize numpy functions.                                             */
#define NO_IMPORT_ARRAY
#define PY_ARRAY_UNIQUE_SYMBOL DIFFREC_ARRAY_API

#include "rss_ringoccs_py_api.h"
#include <rss_ringoccs/include/rss_ringoccs_reconstruction.h>

/*  This function frees the memory allocated to a pointer by malloc when the  *
 *  corresponding variable is destroyed at the Python level. Without this you *
 *  will have serious memory leaks, so do not remove!                         */
static void capsule_cleanup(PyObject *capsule);

static void __set_var(PyObject **py_ptr, double **ptr, unsigned long len);

static void __set_cvar(PyObject **py_ptr, rssringoccs_ComplexDouble **ptr,
                       unsigned long len);

void rssringoccs_C_Tau_to_Py_Tau(PyDiffrecObj *py_tau,
                                 rssringoccs_TAUObj *tau);

#endif
