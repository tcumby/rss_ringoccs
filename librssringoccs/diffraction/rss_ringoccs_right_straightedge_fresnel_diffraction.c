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
 *            rss_ringoccs_right_straightedge_fresnel_diffraction             *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Contains the source code for the Fresnel diffraction of a right       *
 *      straightedge.                                                         *
 ******************************************************************************
 *                               DEPENDENCIES                                 *
 ******************************************************************************
 *  1.) rss_ringoccs_math.h:                                                  *
 *          This file provides compatibility between the two standard math.h  *
 *          header files (C89 vs C99 math.h). If C99 math.h exists, it simply *
 *          provides aliases for the functions, and if C89 math.h is used     *
 *          it defines the functions missing in the earlier version.          *
 *  2.) rss_ringoccs_complex.h:                                               *
 *          Header file where rssringoccs_ComplexDouble is defined, as well   *
 *          as the prototype for rssringoccs_Complex_Cos.                     *
 ******************************************************************************
 *  Author:     Ryan Maguire, Wellesley College                               *
 *  Date:       November 27, 2020                                             *
 ******************************************************************************
 *                             Revision History                               *
 ******************************************************************************
 *  2020/11/27 (Ryan Maguire):                                                *
 *      Frozen for v1.3.                                                      *
 ******************************************************************************/

/*  Header file which contains aliases for the function in the standard C     *
 *  library math.h. This allows compatibility of C89 and C99 math.h headers.  */
#include <rss_ringoccs/include/rss_ringoccs_math.h>

/*  Definition of rssringoccs_ComplexDouble found here.                       */
#include <rss_ringoccs/include/rss_ringoccs_complex.h>

/*  Header file containing the prototypes for the functions.                  */
#include <rss_ringoccs/include/rss_ringoccs_diffraction.h>

RSS_RINGOCCS_EXPORT rssringoccs_ComplexDouble
rssringoccs_Complex_Right_Straightedge_Diffraction(double x, double edge,
                                                   double F)
{
    rssringoccs_ComplexDouble left_edge, T_hat;

    left_edge = rssringoccs_Complex_Left_Straightedge_Diffraction(x, edge, F);
    T_hat = rssringoccs_CDouble_Subtract_Real(1.0, left_edge);
    return T_hat;
}
