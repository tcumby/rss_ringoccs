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
 *                    rss_ringoccs_complex_constants                          *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Define 0, 1, i, complex infinity, and complex NaN constants.          *
 ******************************************************************************
 *                               DEPENDENCIES                                 *
 ******************************************************************************
 *  1.) rss_ringoccs_math.h:                                                  *
 *          Header file where NaN and Infinity are defined.                   *
 *  2.) rss_ringoccs_complex.h:                                               *
 *          Header where complex types and function prototypes are defined.   *
 ******************************************************************************
 *  Author:     Ryan Maguire, Wellesley College                               *
 *  Date:       December 1, 2020                                              *
 ******************************************************************************
 *  2020/12/02 (Ryan Maguire):                                                *
 *      Frozen for v1.3.                                                      *
 ******************************************************************************/

/*  Header file which contains aliases for the function in the standard C     *
 *  library math.h. This allows compatibility of C89 and C99 math.h headers.  */
#include <rss_ringoccs/include/rss_ringoccs_math.h>

/*  Where the prototypes are declared and where complex types are defined.    */
#include <rss_ringoccs/include/rss_ringoccs_complex.h>

/*  If C99 complex.h was included then we'll use the _Complex_I macro.        */
#if _RSS_RINGOCCS_USING_COMPLEX_H_ == 1

#ifndef _MSC_VER
/*  Single precision constants.                                               */
RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_I = _Complex_I;

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_Zero = 0.0F;

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_One  = 1.0F;

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_NaN = rssringoccs_NaN_F + rssringoccs_NaN_F*_Complex_I;

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_Infinity = rssringoccs_Infinity_F +
                              rssringoccs_Infinity_F*_Complex_I;

/*  Double precision constants.                                               */
RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_I = (rssringoccs_ComplexDouble)_Complex_I;

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_Zero = 0.0;

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_One  = 1.0;

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_NaN = rssringoccs_NaN +
                          (rssringoccs_ComplexDouble)_Complex_I*rssringoccs_NaN;

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_Infinity = rssringoccs_Infinity +
                               (rssringoccs_ComplexDouble)_Complex_I*rssringoccs_Infinity;

/*  Long double precision constants.                                          */
RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_I = (rssringoccs_ComplexLongDouble)_Complex_I;

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_Zero = 0.0L;

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_One = 1.0L;

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_NaN = rssringoccs_NaN_L +
                           (rssringoccs_ComplexLongDouble)_Complex_I*rssringoccs_NaN_L;

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_Infinity = rssringoccs_Infinity_L +
    (rssringoccs_ComplexLongDouble)_Complex_I*rssringoccs_Infinity_L;

#else
/*  Else statement for #ifndef _MSC_VER                                       */

/*  Single precision constants.                                               */
RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_I = {0.0F, 1.0F};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_Zero =  {0.0F, 0.0F};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_One  =  {1.0F, 1.0F};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_NaN = {rssringoccs_NaN_F, rssringoccs_NaN_F};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_Infinity = {rssringoccs_Infinity_F, rssringoccs_Infinity_F};

/*  Double precision constants.                                               */
RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_I = {0.0, 1.0};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_Zero = {0.0, 0.0};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_One  = {1.0, 0.0};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_NaN = {rssringoccs_NaN, rssringoccs_NaN};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_Infinity = {rssringoccs_Infinity, rssringoccs_Infinity};

/*  Long double precision constants.                                          */
RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_I = {0.0L, 1.0L};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_Zero = {0.0L, 0.0L};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_One = {1.0L, 0.0L};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_NaN = {rssringoccs_NaN_L, rssringoccs_NaN_L};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_Infinity = {rssringoccs_Infinity_L, rssringoccs_Infinity_L};

#endif
/*  End of #ifndef _MSC_VER                                                   */

#else
/*  Else statement for #if _RSS_RINGOCCS_USING_COMPLEX_H_ == 1.               */

/*  If you do not have complex.h supported, we'll need to define complex      *
 *  constants using the rss_ringoccs complex data types.                      */

/*  Single precision constants.                                               */
RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_I = {{0.0F, 1.0F}};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_Zero = {{0.0F, 0.0F}};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_One = {{1.0F, 0.0F}};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_NaN = {{rssringoccs_NaN_F, rssringoccs_NaN_F}};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexFloat
rssringoccs_CFloat_Infinity = {{rssringoccs_Infinity_F,
                                rssringoccs_Infinity_F}};

/*  Double precision constants.                                               */
RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_I = {{0.0, 1.0}};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_Zero = {{0.0, 0.0}};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_One = {{1.0, 0.0}};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_NaN = {{rssringoccs_NaN, rssringoccs_NaN}};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexDouble
rssringoccs_CDouble_Infinity = {{rssringoccs_Infinity, rssringoccs_Infinity}};

/*  Long double precision constants.                                          */
RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_I = {{0.0L, 1.0L}};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_Zero = {{0.0L, 0.0L}};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_One = {{1.0L, 0.0L}};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_NaN = {{rssringoccs_NaN_L, rssringoccs_NaN_L}};

RSS_RINGOCCS_EXPORT const rssringoccs_ComplexLongDouble
rssringoccs_CLDouble_Infinity = {{rssringoccs_Infinity_L,
                                  rssringoccs_Infinity_L}};

#endif
/*  End of #if _RSS_RINGOCCS_USING_COMPLEX_H_ == 1                            */
