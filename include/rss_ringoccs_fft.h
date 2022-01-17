/*  Include guard to prevent including this file twice.                       */
#ifndef _RSS_RINGOCCS_FFT_H_
#define _RSS_RINGOCCS_FFT_H_
#include "librssringoccs_exports.h"

/*  Booleans defined here. Needed for the FFT routines.                       */
#include <rss_ringoccs/include/rss_ringoccs_bool.h>
#include <rss_ringoccs/include/rss_ringoccs_complex.h>

RSS_RINGOCCS_EXPORT extern rssringoccs_ComplexDouble* rssringoccs_Complex_FFT_Cooley_Tukey(rssringoccs_ComplexDouble *in,
                                     unsigned long N, rssringoccs_Bool inverse);

RSS_RINGOCCS_EXPORT extern rssringoccs_ComplexDouble* rssringoccs_Complex_FFT_Bluestein_Chirp_Z(rssringoccs_ComplexDouble *in,
                                          unsigned long N,
                                          rssringoccs_Bool inverse);

RSS_RINGOCCS_EXPORT extern rssringoccs_ComplexDouble* rssringoccs_Complex_FFT(rssringoccs_ComplexDouble *in,
                        unsigned long N, rssringoccs_Bool inverse);

#endif
