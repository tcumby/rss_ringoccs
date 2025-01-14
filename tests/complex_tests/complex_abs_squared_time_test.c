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
 *  Date:       December 20, 2020                                             *
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

/*  C99 does not provide an abs squared function, so let's create one using   *
 *  the built-in _Complex data type.                                          */
static double cabs_sq(rssringoccs_ComplexDouble z)
{
    /*  Declare necessary variables.                                          */
    double x, y, abs_sq;

    /*  Use the creal and cimag functions found in complex.h to extract the   *
     *  real and imaginary parts from the input z.                            */
#if defined(_MSC_VER) && __RSS_RINGOCCS_USING_COMPLEX_H__==1
    x = reinterpret_cast<double(&)[2]>(z)[0];
    y = reinterpret_cast<double(&)[2]>(z)[1];
#else
    x = creal(z);
    y = cimag(z);
#endif

    /*  |z|^2 = x^2 + y^2 so return this.                                     */
    abs_sq = x*x + y*y;
    return abs_sq;
}

/*  Routine for testing rssringoccs_CDouble_Abs_Squared.                      */
int main(void)
{
    /*  Set the start and end for the values we're testing.                   */
    double start = -1.0;
    double end   =  1.0;

    /*  We'll test on a square grid of 100 million points from (start, start) *
     *  the (end, end) in the complex plane.                                  */
    unsigned long N = 1e4;

    /*  Use the compare function found in rss_ringoccs_compare_funcs.h.       */
    rssringoccs_Compare_Real_CDouble_Funcs("rss_ringoccs",
                                           rssringoccs_CDouble_Abs_Squared,
                                           "C99", cabs_sq, start, end, N);

    return 0;
}
/*  End of main.                                                              */

/******************************************************************************
 *  Compileable with:                                                         *
 *      gcc -O3 -Wall -Wpedantic -Wextra -pedantic -pedantic-errors           *
 *          -std=c99 complex_abs_squared_time_test.c -o test -lrssringoccs    *
 *              -lrssringoccs_compare                                         *
 *  Output (iMac 2017 3.4 GHz Intel Quad-Core i5):                            *
 *      rss_ringoccs: 0.817405                                                *
 *      C99: 0.670562                                                         *
 *      Max Error: 0.0000000000000000                                         *
 *  With -O3 optimization:                                                    *
 *      rss_ringoccs: 0.816004                                                *
 *      C99: 0.554516                                                         *
 *      Max Error: 0.0000000000000000                                         *
 ******************************************************************************/
