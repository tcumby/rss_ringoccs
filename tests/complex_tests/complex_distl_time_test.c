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

/*  We'll test the computation of the distance from z to 1 + i.               */
#if defined( _MSC_VER) && __RSS_RINGOCCS_USING_COMPLEX_H__==1
static const rssringoccs_ComplexLongDouble z = {1.0L, 1.0L};
static const rssringoccs_ComplexLongDouble w = {1.0L, 1.0L};
#else
static const rssringoccs_ComplexLongDouble z = 1.0L + (rssringoccs_ComplexLongDouble)_Complex_I;
static const rssringoccs_ComplexLongDouble w = {{1.0L, 1.0L}};
#endif

/*  C99 version.                                                              */
static long double dist(rssringoccs_ComplexLongDouble z0)
{
    return cabsl(z - z0);
}

/*  rss_ringoccs version.                                                     */
static long double rss_dist(rssringoccs_ComplexLongDouble w0)
{
    return rssringoccs_CLDouble_Dist(w, w0);
}

/*  Routine for testing rssringoccs_CLDouble_Dist.                            */
int main(void)
{
    /*  Set the start and end for the values we're testing.                   */
    long double start = -1.0L;
    long double end   =  1.0L;

    /*  We'll test on a square grid of 100 million points from (start, start) *
     *  the (end, end) in the complex plane.                                  */
    unsigned long N = 1e4;

    /*  Use the compare function found in rss_ringoccs_compare_funcs.h.       */
    rssringoccs_Compare_Real_CLDouble_Funcs("rss_ringoccs", rss_dist,
                                            "C99", dist, start, end, N);

    return 0;
}
/*  End of main.                                                              */

/******************************************************************************
 *  Compileable with:                                                         *
 *      gcc -O3 -Wall -Wpedantic -Wextra -pedantic -pedantic-errors           *
 *          -std=c99 complex_distl_time_test.c -o test -lrssringoccs          *
 *              -lrssringoccs_compare                                         *
 *  Output (iMac 2017 3.4 GHz Intel Quad-Core i5):                            *
 *      rss_ringoccs: 4.453076                                                *
 *      C99: 3.562204                                                         *
 *      Max Error: 0.000000000002723155034801                                 *
 *  With -O3 optimization:                                                    *
 *      rss_ringoccs: 4.614870                                                *
 *      C99: 3.907739                                                         *
 *      Max Error: 0.000000000002723155034801                                 *
 ******************************************************************************/
