#ifndef __RSS_RINGOCCS_VECTOR_H__
#define __RSS_RINGOCCS_VECTOR_H__
#include "librssringoccs_exports.h"

#include <rss_ringoccs/include/rss_ringoccs_bool.h>

typedef struct rssringoccs_Vector {
    double *data;
    unsigned long length;
    rssringoccs_Bool error_occurred;
    char *error_message;
} rssringoccs_Vector;

RSS_RINGOCCS_EXPORT extern rssringoccs_Vector* rssringoccs_Create_Vector_From_Data(double *v, unsigned long length);

RSS_RINGOCCS_EXPORT extern rssringoccs_Vector* rssringoccs_Create_Empty_Vector(unsigned long length);

RSS_RINGOCCS_EXPORT extern rssringoccs_Vector* rssringoccs_Create_Zero_Vector(unsigned long length);

RSS_RINGOCCS_EXPORT extern void rssringoccs_Destroy_Vector(rssringoccs_Vector *v);

RSS_RINGOCCS_EXPORT extern void rssringoccs_Vector_Add(rssringoccs_Vector *v,
                                   rssringoccs_Vector *u,
                                   rssringoccs_Vector *sum);

#endif
