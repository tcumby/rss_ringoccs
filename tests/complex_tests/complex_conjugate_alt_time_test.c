/******************************************************************************
 *                                 LICENSE                                    *
 ******************************************************************************
 *  This file is part of rss_ringoccs.                                        *
 *                                                                            *
 *  rss_ringoccs is free software: you can redistribute it and/or modify it   *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation, either version 3 of the License, or         *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  rss_ringoccs is distributed in the hope that it will be useful,           *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with rss_ringoccs.  If not, see <https://www.gnu.org/licenses/>.    *
 ******************************************************************************
 *  Author:     Ryan Maguire, Wellesley College                               *
 *  Date:       December 22, 2020                                             *
 ******************************************************************************/

/*  rss_ringoccs complex routines found here.                                 */
#include <rss_ringoccs/include/rss_ringoccs_complex.h>

/*  C99 complex functions found here. Note, your compiler must support        *
 *  complex variables to run this test.                                       */
#include <complex.h>

/*  The comparison functions are found here.                                  *
 *  NOTE:                                                                     *
 *      You will need to compile rss_ringoccs_compare_funcs.c. This file and  *
 *      the functions found in rss_ringoccs_compare_funcs.h are NOT found in  *
 *      librssringoccs. We can compile via:                                   *
 *                                                                            *
 *          gcc -O3 -pedantic -Wall -Wconversion -Wextra -Wpedantic           *
 *              rss_ringoccs_compare_funcs.c -shared                          *
 *                  -o librssringoccs_compare.so -lrssringoccs                *
 *                                                                            *
 *      You will need to have librssringoccs already built so we can link it  *
 *      to this new comparison library. In the examples below we placed the   *
 *      output file in /usr/local/lib/:                                       *
 *                                                                            *
 *          mv librssringoccs_compare.so /usr/local/lib/                      *
 *                                                                            *
 *      You may need to add sudo to move files in /usr/.                      *
 *      We can then link via -lrssringoccs_compare (see below).               */
#include <rss_ringoccs/tests/librssringoccs_compare/rss_ringoccs_compare_funcs.h>

/*  A "fast" conjugate which avoids retrieving the complex variables via      *
 *  rssringoccs_CDouble_Real_Part and rssringoccs_CDouble_Imag_Part and       *
 *  avoids creating the output via rssringoccs_CDouble_Rect. We simply negate *
 *  the imaginary part of the input and return it.                            */
static rssringoccs_ComplexDouble rss_conj(rssringoccs_ComplexDouble z)
{
#if defined(_MSC_VER) && __RSS_RINGOCCS_USING_COMPLEX_H__==1
    /* For C++, std::complex<T> supports array-oriented access via a
     * reinterpret_cast to T(&)[2], i.e. a 2-element array of T&              */
    reinterpret_cast<double(&)[2]>(z)[1] = -reinterpret_cast<double(&)[2]>(z)[1];
#else
#if __RSS_RINGOCCS_USING_COMPLEX_H__==1
    z = conj(z);
#else
    z.dat[1] = -z.dat[1];
#endif
#endif
    return z;
}

/*  Routine for testing rss_conj defined above.                               */
int main(void)
{
    /*  Set the start and end for the values we're testing.                   */
    double start = -1.0;
    double end   =  1.0;

    /*  We'll test on a square grid of 100 million points from (start, start) *
     *  the (end, end) in the complex plane.                                  */
    unsigned long N = 1e4;
#if defined(_MSC_VER) && __RSS_RINGOCCS_USING_COMPLEX_H__==1
    /* std::conj in std::complex does not have non-const overloads,
    so we create a lambda                                                     */
    rssringoccs_ComplexDouble (*local_conj)(rssringoccs_ComplexDouble) = [](auto z) -> auto { return std::conj(z); };
    /*  Use the compare function found in rss_ringoccs_compare_funcs.h.       */
    rssringoccs_Compare_CDouble_Funcs("rss_ringoccs", rss_conj,
                                      "C99", local_conj, start, end, N);
#else
    /*  Use the compare function found in rss_ringoccs_compare_funcs.h.       */
    rssringoccs_Compare_CDouble_Funcs("rss_ringoccs", rss_conj,
                                      "C99", conj, start, end, N);
#endif

    return 0;
}
/*  End of main.                                                              */

/******************************************************************************
 *  Compileable with:                                                         *
 *      gcc -O3 -Wall -Wpedantic -Wextra -pedantic -pedantic-errors           *
 *          -std=c99 complex_conjugate_time_test.c -o test -lrssringoccs      *
 *              -lrssringoccs_compare                                         *
 *  Output (iMac 2017 3.4 GHz Intel Quad-Core i5):                            *
 *      rss_ringoccs: 1.384617                                                *
 *      C99: 1.083972                                                         *
 *      Max Error: 0.0000000000000000                                         *
 *  With -O3 optimization:                                                    *
 *      rss_ringoccs: 1.177583                                                *
 *      C99: 1.305011                                                         *
 *      Max Error: 0.0000000000000000                                         *
 ******************************************************************************/

/******************************************************************************
 *  For comparison, the rssringoccs_CDouble_Conjugate times are:              *
 *      rss_ringoccs: 1.485245                                                *
 *  With -O3 optimization:                                                    *
 *      rss_ringoccs: 1.260294                                                *
 ******************************************************************************/
