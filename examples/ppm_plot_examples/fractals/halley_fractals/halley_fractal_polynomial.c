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
 ******************************************************************************/

/*  We'll need stdio to write to the output ppm file.                         */
#include <stdio.h>

/*  The Newton-Raphson routine is found here. Note the rss_ringoccs_complex.h *
 *  is included by rss_ringoccs_numerical.h so we don't need to include again.*/
#include <rss_ringoccs/include/rss_ringoccs_numerical.h>
#include <rss_ringoccs/include/rss_ringoccs_complex.h>
#include <rss_ringoccs/include/rss_ringoccs_ppm_plot.h>

/*  The number of pixels in the x and y axes. If you want a higher resolution *
 *  for the output fractal, increase this number. It is best to make n*1024   *
 *  where n is some positive integer.                                         */
const unsigned int size = 1024;

/*  Maximum number of iterations in the Newton-Raphson method before quitting.*/
const unsigned int max_iters = 32;

/*  The function we're working with is f(z) = (z^3 - 1).                      */
static rssringoccs_ComplexDouble f(rssringoccs_ComplexDouble z)
{
    rssringoccs_ComplexDouble poly;
    double coeffs[4] = {-1.0, 0.0, 0.0, 1.0};

    poly = rssringoccs_CDouble_Poly_Real_Coeffs(coeffs, 3, z);
    return poly;
}

/*  The derivative is f'(z) = 3*z^2/                                          */
static rssringoccs_ComplexDouble f_prime(rssringoccs_ComplexDouble z)
{
    rssringoccs_ComplexDouble poly;
    double coeffs[3] = {0.0, 0.0, 3.0};

    poly = rssringoccs_CDouble_Poly_Real_Coeffs(coeffs, 2, z);
    return poly;
}

/*  The derivative is f''(z) = 6z, so create this.                            */
static rssringoccs_ComplexDouble f_2prime(rssringoccs_ComplexDouble z)
{
    rssringoccs_ComplexDouble poly;
    double coeffs[2] = {0.0, 6.0};

    poly = rssringoccs_CDouble_Poly_Real_Coeffs(coeffs, 1, z);
    return poly;
}

/*  We can be more general and set up fractals for general polynomials. This  *
 *  cubic will have three roots, so set NRoots to 3, and compute the roots.   */
#define NRoots 3
#if defined( _MSC_VER) && __RSS_RINGOCCS_USING_COMPLEX_H__==1
rssringoccs_ComplexDouble ROOT_1 = {1.0, 0.0};
rssringoccs_ComplexDouble ROOT_2 = {-0.5, +0.8660254037844386};
rssringoccs_ComplexDouble ROOT_3 = {-0.5, -0.8660254037844386};
#else
rssringoccs_ComplexDouble ROOT_1 = {{1.0, 0.0}};
rssringoccs_ComplexDouble ROOT_2 = {{-0.5, +0.8660254037844386}};
rssringoccs_ComplexDouble ROOT_3 = {{-0.5, -0.8660254037844386}};
#endif

int main(void)
{
    /* Values for the min and max of the x and y axes.                        */
    double x_min = -1.0;
    double x_max =  1.0;
    double y_min = -1.0;
    double y_max =  1.0;

    /* List the roots of z^3 - 1.                                             */
    rssringoccs_ComplexDouble roots[NRoots] = {ROOT_1, ROOT_2, ROOT_3};

    /*  More dummy variables to loop over.                                    */
    unsigned int x, y, n, ind;
    double z_x, z_y, min, temp;
    rssringoccs_ComplexDouble z, root;

    /*  Colors for the roots (Red, Green, Blue).                              */
    char colors[NRoots][3] = {{255, 0, 30}, {0, 255, 30}, {0, 30, 255}};
    char brightness[3];

    /*  Declare a variable for the output file and give it write permission.  */
    FILE *fp;
    fp = fopen("halley_fractal.ppm", "w");

    /*  Needed to create the output ppm file. This is the preamble.           */
    fprintf(fp, "P6\n%d %d\n255\n", size, size);

    /*  Loop over every pixel and perform Halley's method with the given      *
     *  point as the initial guess for the algorithm.                         */
    for (y=0; y<size; ++y)
    {
        /*  We want to center z_y so scale and shift. This makes the output   *
         *  picture lie in the box [x_min, x_max] x [y_min, y_max].           */
        z_y = y * (y_max - y_min)/(size - 1) + y_min;

        for (x=0; x<size; ++x)
        {
            /*  Similarly, center z_x.                                        */
            z_x = x * (x_max - x_min)/(size - 1) + x_min;

            /*  Set out current guess to z_x + i z_y.                         */
            z = rssringoccs_CDouble_Rect(z_x, z_y);

            /*  Use the Newton-Raphson function to compute a root.            */
            root = rssringoccs_Halleys_Method_Complex(z, f, f_prime,
                                                      f_2prime, max_iters);

            /*  Find which root the final iteration is closest too.           */
            min = rssringoccs_CDouble_Abs(
                rssringoccs_CDouble_Subtract(root, roots[0])
            );
            ind = 0;

            for (n=1; n<NRoots; ++n)
            {
                temp = rssringoccs_CDouble_Abs(
                    rssringoccs_CDouble_Subtract(root, roots[n])
                );
                if (temp < min) {
                    min = temp;
                    ind = n;
                }
            }

            /*  Set the colors to correspond to the nearest root.             */
            for (n=0; n<3; ++n)
                brightness[n] = colors[ind][n];

            /*  Color the current pixel.                                      */
            rssringoccs_Color(brightness[0], brightness[1], brightness[2], fp);
        }
    }
    return 0;
}
