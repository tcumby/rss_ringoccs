#ifndef __RSS_RINGOCCS_PY_DLP_TO_C_DLP_H__
#define __RSS_RINGOCCS_PY_DLP_TO_C_DLP_H__

/* To avoid seg faults due to numpy, this must be defined before any numpy    *
 *  includes and must be also defined in any other linked *.c files that      *
 *  that utilize numpy functions.                                             */
#define NO_IMPORT_ARRAY
#define PY_ARRAY_UNIQUE_SYMBOL DIFFREC_ARRAY_API

#include "rss_ringoccs_py_api.h"
#include <numpy/ndarraytypes.h>
#include <numpy/ufuncobject.h>


/*  Macro for raising the appropriate python error if the DLP instance is     *
 *  missing an attribute. This is equivalent to the following in python       *
 *      if not hasattr(tauin, attr_name):                                     *
 *          raise AttributeError(                                             *
 *              """                                                           *
 *              Error message                                                 *
 *              """                                                           *
 *          )                                                                 *
 *      else:                                                                 *
 *          pass                                                              *
 *  It then checks that the variable is a numpy array using numpy's API. This *
 *  is equivalent to the following:                                           *
 *      if not isinstance(varname, numpy.ndarray):                            *
 *          raise TypeError(                                                  *
 *              """                                                           *
 *              Error message                                                 *
 *              """                                                           *
 *          )                                                                 *
 *      else:                                                                 *
 *          pass                                                              *
 *  Next we try to convert the numpy array to an array of double, which is    *
 *  equivalent to using the astype method of the ndarray numpy object:        *
 *      arr = arr.astype(float)                                               *
 *  Finally, we check that the array is one dimensional and that it has the   *
 *  same number of elements as the input rho_km_vals array. If this passes,   *
 *  we pointer the pointer ptr to the data of the array.                      */
static double *__extract_data(rssringoccs_DLPObj *dlp, PyObject *py_dlp,
                              const char *var_name)
{
    PyObject *tmp;
    PyObject *arr;
    unsigned long len;

    if (dlp == NULL)
        return NULL;

    if (dlp->error_occurred)
        return NULL;

    if (!PyObject_HasAttrString(py_dlp, var_name))
    {
        dlp->error_occurred = rssringoccs_True;
        dlp->error_message = (char*)malloc(sizeof(*dlp->error_message) * 256);
        sprintf(
            dlp->error_message,
            "\n\rError Encountered: rss_ringoccs\n"
            "\r\tdiffrec.DiffractionCorrection\n\n"
            "\rInput DLP Instance is missing the following attribute:\n"
            "\r\t%s\n\n",
            var_name
        );
        return NULL;
    }
    else
        tmp = PyObject_GetAttrString(py_dlp, var_name);

    if (!PyArray_Check(tmp))
    {
        dlp->error_occurred = rssringoccs_True;
        dlp->error_message = (char*)malloc(sizeof(*dlp->error_message) * 256);
        sprintf(
            dlp->error_message,
            "\n\rError Encountered: rss_ringoccs\n"
            "\r\tdiffrec.DiffractionCorrection\n\n"
            "\r%s must be a numpy array.\n",
            var_name
        );
        return NULL;
    }
    else
        arr = PyArray_FromObject(tmp, NPY_DOUBLE, 1, 1);

    len = (unsigned long)PyArray_DIMS((PyArrayObject *)arr)[0];

    /*  If PyArray_FromObject failed arr should be NULL. If so, raise error.  */
    if (!arr)
    {
        dlp->error_occurred = rssringoccs_True;
        dlp->error_message = (char*)malloc(sizeof(*dlp->error_message) * 256);
        sprintf(
            dlp->error_message,
            "\n\rError Encountered: rss_ringoccs\n"
            "\r\tdiffrec.DiffractionCorrection\n\n"
            "\r%s must be a numpy array.\n",
            var_name
        );
        return NULL;
    }

    /*  Currently we only allow for one dimensional inputs.                   */
    else if (PyArray_NDIM((PyArrayObject *)arr) != 1)
    {
        dlp->error_occurred = rssringoccs_True;
        dlp->error_message = (char*)malloc(sizeof(*dlp->error_message) * 256);
        sprintf(
            dlp->error_message,
            "\n\rError Encountered: rss_ringoccs\n"
            "\r\tdiffrec.DiffractionCorrection\n\n"
            "\r%s must be a one-dimensional numpy array.\n",
            var_name
        );
        return NULL;
    }

    /*  arr should have the same number of elements as rho_km_vals.           */
    else if (len != dlp->arr_size)
    {
        dlp->error_occurred = rssringoccs_True;
        dlp->error_message = (char*)malloc(sizeof(*dlp->error_message) * 256);
        sprintf(
            dlp->error_message,
            "\n\rError Encountered: rss_ringoccs\n"
            "\r\tdiffrec.DiffractionCorrection\n\n"
            "\r%s and rho_km_vals have a different number of elements.\n",
            var_name
        );
        return NULL;
    }

    /*  If every passed, set ptr to point to the data inside the array arr.   */
    return (double *)PyArray_DATA((PyArrayObject *)arr);
}

rssringoccs_DLPObj *rssringoccs_Py_DLP_to_C_DLP(PyObject *py_dlp);

#endif
