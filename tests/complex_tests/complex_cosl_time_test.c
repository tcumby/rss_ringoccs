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
 *  Date:       December 19, 2020                                             *
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

/*  Routine for testing rssringoccs_CLDouble_Cos.                             */
int main(void)
{
    /*  Set the start and end for the values we're testing.                   */
    long double start = -1.0L;
    long double end   =  1.0L;

    /*  We'll test on a square grid of 100 million points from (start, start) *
     *  the (end, end) in the complex plane.                                  */
    unsigned long N = 1e4;

#if defined(_MSC_VER) && __RSS_RINGOCCS_USING_COMPLEX_H__==1
    /* std::cos in std::complex does not have non-const overloads,
    so we create a lambda                                                     */
    auto ccosl = [](rssringoccs_ComplexLongDouble z) { return std::cos(z); };
#endif

    /*  Use the compare function found in rss_ringoccs_compare_funcs.h.       */
    rssringoccs_Compare_CLDouble_Funcs("rss_ringoccs", rssringoccs_CLDouble_Cos,
                                       "C99", ccosl, start, end, N);

    return 0;
}
/*  End of main.                                                              */

/******************************************************************************
 *  Compileable with:                                                         *
 *      gcc -O3 -Wall -Wpedantic -Wextra -pedantic -pedantic-errors           *
 *          -std=c99 complex_cosl_time_test.c -o test -lrssringoccs           *
 *              -lrssringoccs_compare                                         *
 *  Output (iMac 2017 3.4 GHz Intel Quad-Core i5):                            *
 *      rss_ringoccs: 11.772154                                               *
 *      C99: 15.611350                                                        *
 *      Max Error: 0.000000000002800554493840                                 *
 *  With -O3 optimization:                                                    *
 *      rss_ringoccs: 11.594109                                               *
 *      C99: 15.470880                                                        *
 *      Max Error: 0.000000000002800554493840                                 *
 ******************************************************************************/
