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
 *      Returns the square of the Euclidean norm of a vector (x, y) using the *
 *      Pythagorean formula:                                                  *
 *          ||(x, y)||^2 = x^2 + y^2                                          *
 ******************************************************************************
 *  Author:     Ryan Maguire, Wellesley College                               *
 *  Date:       December 21, 2020                                             *
 ******************************************************************************/

/*  Function prototype and two-vector typedef found here.                     */
#include <rss_ringoccs/include/rss_ringoccs_geometry.h>

/*  Function for computing the length of the vector (x, y) in the plane.      */
RSS_RINGOCCS_EXPORT double rssringoccs_TwoVector_Euclidean_Norm_Squared(rssringoccs_TwoVector P)
{
    /*  Declare necessary variables. C89 requires declarations at the top.    */
    double x, y, norm_sq;

    /*  Extract the x and y component from the input vector P.                */
    x = rssringoccs_TwoVector_X(P);
    y = rssringoccs_TwoVector_Y(P);

    /*  Use the Pythagorean formula to compute ||(x, y)||^2.                  */
    norm_sq = x*x + y*y;
    return norm_sq;
}
/*  End of rssringoccs_TwoVector_Euclidean_Norm_Squared.                      */
