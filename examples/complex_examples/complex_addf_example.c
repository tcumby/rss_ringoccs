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
 *  Purpose:                                                                  *
 *      Provides an example of adding complex numbers.                        *
 ******************************************************************************
 *  Author:     Ryan Maguire, Wellesley College                               *
 *  Date:       December 22, 2020                                             *
 ******************************************************************************/

/*  Complex functions defined here.                                           */
#include <rss_ringoccs/include/rss_ringoccs_complex.h>

/*  Real nan and inf found here.                                              */
#include <rss_ringoccs/include/rss_ringoccs_math.h>

/*  We'll use stdio to print the results.                                     */
#include <stdio.h>

/*  Routine for adding two complex numbers.                                   */
int main(void)
{
    /*  Declare necessary variables. C89 requires declarations at the top.    */
    rssringoccs_ComplexFloat z0[7], z1[7], w[7];
    float re_z0, im_z0, re_z1, im_z1, re_w, im_w;

    /*  And declare a variable for indexing.                                  */
    int n;

    /*  Set the test values in the array z0.                                  */
    z0[0] = rssringoccs_CFloat_Zero;
    z0[1] = rssringoccs_CFloat_One;
    z0[2] = rssringoccs_CFloat_Rect(1.0F, 1.0F);
    z0[3] = rssringoccs_CFloat_Rect(rssringoccs_NaN_F, 0.0F);
    z0[4] = rssringoccs_CFloat_Rect(rssringoccs_Infinity_F, 0.0F);
    z0[5] = rssringoccs_CFloat_NaN;
    z0[6] = rssringoccs_CFloat_Infinity;

    /*  Set the test values for the array z1.                                 */
    z1[0] = rssringoccs_CFloat_Rect(1.0F, 1.0F);
    z1[1] = rssringoccs_CFloat_Rect(2.0F, 0.0F);
    z1[2] = rssringoccs_CFloat_Rect(1.0F, 3.0F);
    z1[3] = rssringoccs_CFloat_Rect(1.0F, 4.0F);
    z1[4] = rssringoccs_CFloat_Rect(1.0F, 0.0F);
    z1[5] = rssringoccs_CFloat_Rect(1.0F, 8.0F);
    z1[6] = rssringoccs_CFloat_Rect(1.0F, 1.0F);

    /*  Loop over the results and print them.                                 */
    for (n=0; n<7; ++n)
    {
        /*  Compute z0 + z1 of the nth value.                                 */
        w[n] = rssringoccs_CFloat_Add(z0[n], z1[n]);

        /*  Extract the real and imaginary parts from z0[n].                  */
        re_z0 = rssringoccs_CFloat_Real_Part(z0[n]);
        im_z0 = rssringoccs_CFloat_Imag_Part(z0[n]);

        /*  Extract the real and imaginary parts from z1[n].                  */
        re_z1 = rssringoccs_CFloat_Real_Part(z1[n]);
        im_z1 = rssringoccs_CFloat_Imag_Part(z1[n]);

        /*  Extract the real and imaginary parts from w[n].                   */
        re_w = rssringoccs_CFloat_Real_Part(w[n]);
        im_w = rssringoccs_CFloat_Imag_Part(w[n]);

        /*  And finally, print the result to the screen.                      */
        printf("(%f + i%f) + (%f + i%f) = %f +i%f\n",
               re_z0, im_z0, re_z1, im_z1, re_w, im_w);
    }
    /*  End of for loop z0 + z1.                                              */

    return 0;
}
/*  End of main.                                                              */

/******************************************************************************
 *  We can compile this with:                                                 *
 *                                                                            *
 *      gcc complex_addf_example.c -o test -lrssringoccs                      *
 *                                                                            *
 *  If librssringoccs is not in /usr/local/lib/ (this is the default          *
 *  location it is placed in when built via config_librssringoccs.sh), change *
 *  the -L option to the correct location. If /usr/local/include/ is not in   *
 *  your path, add the -I option as follows:                                  *
 *                                                                            *
 *      gcc -I/usr/local/include/ -L/usr/local/lib/                           *
 *              complex_addf_example.c -o test -lrssringoccs                  *
 *                                                                            *
 *  This example is also C89 compliant and compiles with the following flags: *
 *                                                                            *
 *      gcc -Wconversion -pedantic -Wall -Wextra -std=c89 -ansi               *
 *          -Wpedantic complex_addf_example.c -o test -lrssringoccs           *
 *                                                                            *
 *  Note, this should all be one line. This outputs an executable "test".     *
 *  Running the executable with ./test, this outputs:                         *
 *      (0.000000 + i0.000000) + (1.000000 + i1.000000) = 1.000000 +i1.000000 *
 *      (1.000000 + i0.000000) + (2.000000 + i0.000000) = 3.000000 +i0.000000 *
 *      (1.000000 + i1.000000) + (1.000000 + i3.000000) = 2.000000 +i4.000000 *
 *      (nan + i0.000000) + (1.000000 + i4.000000) = nan +i4.000000           *
 *      (inf + i0.000000) + (1.000000 + i0.000000) = inf +i0.000000           *
 *      (nan + inan) + (1.000000 + i8.000000) = nan +inan                     *
 *      (inf + iinf) + (1.000000 + i1.000000) = inf +iinf                     *
 ******************************************************************************/
