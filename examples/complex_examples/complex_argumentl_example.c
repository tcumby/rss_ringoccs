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
 *      Provides an example of using the complex argument function.           *
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

/*  Routine for computing arg(z) for several test values.                     */
int main(void)
{
    /*  Declare necessary variables. C89 requires declarations at the top.    */
    rssringoccs_ComplexLongDouble z[9];
    long double w[9];
    long double re_z, im_z;

    /*  And declare a variable for indexing.                                  */
    int n;

    /*  Set the test values in the array z.                                   */
    z[0] = rssringoccs_CLDouble_Zero;
    z[1] = rssringoccs_CLDouble_One;
    z[2] = rssringoccs_CLDouble_Rect(1.0L, 1.0L);
    z[3] = rssringoccs_CLDouble_I;
    z[4] = rssringoccs_CLDouble_Rect(-1.0L, 1.0L);
    z[5] = rssringoccs_CLDouble_Rect(-1.0L, 0.0L);
    z[6] = rssringoccs_CLDouble_Rect(-1.0L, -1.0L);
    z[7] = rssringoccs_CLDouble_Rect(0.0L, -1.0L);
    z[8] = rssringoccs_CLDouble_Rect(1.0L, -1.0L);

    /*  Loop over the results and print them.                                 */
    for (n=0; n<9; ++n)
    {
        /*  Compute arg(z) of the nth value.                                  */
        w[n] = rssringoccs_CLDouble_Argument(z[n]);

        /*  Extract the real and imaginary parts from z[n].                   */
        re_z = rssringoccs_CLDouble_Real_Part(z[n]);
        im_z = rssringoccs_CLDouble_Imag_Part(z[n]);

        /*  And finally, print the result to the screen.                      */
        printf("arg(%Lf + i%Lf) = %Lf\n", re_z, im_z, w[n]);
    }
    /*  End of for loop computing arg(z).                                     */

    return 0;
}
/*  End of main.                                                              */

/******************************************************************************
 *  We can compile this with:                                                 *
 *                                                                            *
 *      gcc complex_argumentl_example.c -o test -lrssringoccs                 *
 *                                                                            *
 *  If librssringoccs is not in /usr/local/lib/ (this is the default          *
 *  location it is placed in when built via config_librssringoccs.sh), change *
 *  the -L option to the correct location. If /usr/local/include/ is not in   *
 *  your path, add the -I option as follows:                                  *
 *                                                                            *
 *      gcc -I/usr/local/include/ -L/usr/local/lib/                           *
 *              complex_argumentl_example.c -o test -lrssringoccs             *
 *                                                                            *
 *  This example is also C89 compliant and compiles with the following flags: *
 *                                                                            *
 *      gcc -Wconversion -pedantic -Wall -Wextra -std=c89 -ansi               *
 *          -Wpedantic complex_argumentl_example.c -o test -lrssringoccs      *
 *                                                                            *
 *  Note, this should all be one line. This outputs an executable "test".     *
 *  Running the executable with ./test, this outputs:                         *
 *      arg(0.000000 + i0.000000) = 0.000000                                  *
 *      arg(1.000000 + i0.000000) = 0.000000                                  *
 *      arg(1.000000 + i1.000000) = 0.785398                                  *
 *      arg(0.000000 + i1.000000) = 1.570796                                  *
 *      arg(-1.000000 + i1.000000) = 2.356194                                 *
 *      arg(-1.000000 + i0.000000) = 3.141593                                 *
 *      arg(-1.000000 + i-1.000000) = -2.356194                               *
 *      arg(0.000000 + i-1.000000) = -1.570796                                *
 *      arg(1.000000 + i-1.000000) = -0.785398                                *
 ******************************************************************************/
