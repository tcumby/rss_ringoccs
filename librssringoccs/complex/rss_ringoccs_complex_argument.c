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
 *                     rss_ringoccs_complex_argument                          *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Contains the source code for the complex argument.                    *
 ******************************************************************************
 *                             DEFINED FUNCTIONS                              *
 ******************************************************************************
 *  Function Name:                                                            *
 *      rssringoccs_CFloat_Argument:                                          *
 *      rssringoccs_CDouble_Argument:                                         *
 *      rssringoccs_CLDouble_Argument:                                        *
 *  Purpose:                                                                  *
 *      Computes the argument of a complex number:                            *
 *                                                                            *
 *          arg(z) =  arg(r * exp(i theta)) = theta                           *
 *                                                                            *
 *      Equivalently:                                                         *
 *                                                                            *
 *          arg(z) = arg(x + iy) = arctan(y, x)                               *
 *                                                                            *
 *  Arguments:                                                                *
 *      z (rssringoccs_ComplexFloat/ComplexDouble/ComplexLongDouble):         *
 *          A complex number.                                                 *
 *  Output:                                                                   *
 *      arg (float/double/long double):                                       *
 *          The argument of z.                                                *
 *  Method:                                                                   *
 *      Extract the real and imaginary parts and return atan2(y, x).          *
 *  NOTES:                                                                    *
 *      Because the atan2 function is used, there is a discontinuity along    *
 *      the negative real axis. That is, the argument returns a real value    *
 *      in the interval (-pi, pi] (+pi is inclusive).                         *
 ******************************************************************************
 *                               DEPENDENCIES                                 *
 ******************************************************************************
 *  1.) rss_ringoccs_math.h:                                                  *
 *          This file provides compatibility between the two standard math.h  *
 *          header files (C89 vs C99 math.h). If C99 math.h exists, it simply *
 *          provides aliases for the functions, and if C89 math.h is used     *
 *          it defines the functions missing in the earlier version.          *
 *  2.) rss_ringoccs_complex.h:                                               *
 *          Header where complex types and function prototypes are defined.   *
 ******************************************************************************
 *                            A NOTE ON COMMENTS                              *
 ******************************************************************************
 *  It is anticipated that many users of this code will have experience in    *
 *  either Python or IDL, but not C. Many comments are left to explain as     *
 *  much as possible. Vagueness or unclear code should be reported to:        *
 *  https://github.com/NASA-Planetary-Science/rss_ringoccs/issues             *
 ******************************************************************************
 *                            A FRIENDLY WARNING                              *
 ******************************************************************************
 *  This code is compatible with the C89/C90 standard. The setup script that  *
 *  is used to compile this in config_librssringoccs.sh uses gcc and has the  *
 *  -pedantic and -std=c89 flags to check for compliance. If you edit this to *
 *  use C99 features (built-in complex, built-in booleans, C++ style comments *
 *  and etc.), or GCC extensions, you will need to edit the config script.    *
 ******************************************************************************
 *  Author:     Ryan Maguire, Wellesley College                               *
 *  Date:       November 30, 2020                                             *
 ******************************************************************************
 *                             Revision History                               *
 ******************************************************************************
 *  2020/12/02 (Ryan Maguire):                                                *
 *      Frozen for v1.3.                                                      *
 ******************************************************************************/

/*  Header file which contains aliases for the functions in the standard C    *
 *  library math.h. This allows compatibility of C89 and C99 math.h headers.  */
#include <rss_ringoccs/include/rss_ringoccs_math.h>

/*  Where the prototypes are declared and where complex types are defined.    */
#include <rss_ringoccs/include/rss_ringoccs_complex.h>

/*  If _RSS_RINGOCCS_USING_COMPLEX_H_ is set to zero, then C99 complex.h has  *
 *  not been included and we must define our own algorithms.                  */
#if _RSS_RINGOCCS_USING_COMPLEX_H_ == 0

/*  Single precision complex argument function (cargf equivalent).            */
RSS_RINGOCCS_EXPORT float rssringoccs_CFloat_Argument(rssringoccs_ComplexFloat z)
{
    /*  Declare necessary variables. C89 requires declarations at the top.    */
    float real, imag, theta;

    /*  Extract the real and imaginary parts from the input complex number.   */
    real = rssringoccs_CFloat_Real_Part(z);
    imag = rssringoccs_CFloat_Imag_Part(z);

    /*  Compute the argument using arctan and return.                         */
    theta = rssringoccs_Float_Arctan2(imag, real);
    return theta;
}
/*  End of rssringoccs_CFloat_Argument.                                 */

/*  Double precision complex argument function (carg equivalent).             */
RSS_RINGOCCS_EXPORT double rssringoccs_CDouble_Argument(rssringoccs_ComplexDouble z)
{
    /*  Declare necessary variables. C89 requires declarations at the top.    */
    double real, imag, theta;

    /*  Extract the real and imaginary parts from the input complex number.   */
    real = rssringoccs_CDouble_Real_Part(z);
    imag = rssringoccs_CDouble_Imag_Part(z);

    /*  Compute the argument using arctan and return.                         */
    theta = rssringoccs_Double_Arctan2(imag, real);
    return theta;
}
/*  End of rssringoccs_CDouble_Argument.                                */

/*  Long double precision complex argument function (cargl equivalent).       */
RSS_RINGOCCS_EXPORT long double
rssringoccs_CLDouble_Argument(rssringoccs_ComplexLongDouble z)
{
    /*  Declare necessary variables. C89 requires declarations at the top.    */
    long double real, imag, theta;

    /*  Extract the real and imaginary parts from the input complex number.   */
    real = rssringoccs_CLDouble_Real_Part(z);
    imag = rssringoccs_CLDouble_Imag_Part(z);

    /*  Compute the argument using arctan and return.                         */
    theta = rssringoccs_LDouble_Arctan2(imag, real);
    return theta;
}
/*  End of rssringoccs_CLDouble_Argument.                            */

#else
/*  Else statement for #if _RSS_RINGOCCS_USING_COMPLEX_H_ == 0.               */

/*  If we get here we have complex.h support so we'll just alias the          *
 *  functions found in the library.                                           */
#ifdef __cplusplus
/*  Single precision complex argument function.                               */
RSS_RINGOCCS_EXPORT float rssringoccs_CFloat_Argument(rssringoccs_ComplexFloat z)
{
    return arg(z);
}
/*  End of rssringoccs_CFloat_Argument.                                 */

/*  Double precision complex argument function.                               */
RSS_RINGOCCS_EXPORT double rssringoccs_CDouble_Argument(rssringoccs_ComplexDouble z)
{
    return arg(z);
}
/*  End of rssringoccs_CDouble_Argument.                                */

/*  Long double precision complex argument function.                          */
RSS_RINGOCCS_EXPORT long double
rssringoccs_CLDouble_Argument(rssringoccs_ComplexLongDouble z)
{
    return arg(z);
}
/*  End of rssringoccs_CLDouble_Argument.                            */
#else
/*  Else statement for #ifdef __cplusplus.                                   */

/*  If we get here we have complex.h support so we'll just alias the          *
 *  functions found in the library.                                           */

/*  Single precision complex argument function.                               */
RSS_RINGOCCS_EXPORT float rssringoccs_CFloat_Argument(rssringoccs_ComplexFloat z)
{
    return cargf(z);
}
/*  End of rssringoccs_CFloat_Argument.                                 */

/*  Double precision complex argument function.                               */
RSS_RINGOCCS_EXPORT double rssringoccs_CDouble_Argument(rssringoccs_ComplexDouble z)
{
    return carg(z);
}
/*  End of rssringoccs_CDouble_Argument.                                */

/*  Long double precision complex argument function.                          */
RSS_RINGOCCS_EXPORT long double
rssringoccs_CLDouble_Argument(rssringoccs_ComplexLongDouble z)
{
    return carg(z);
}
/*  End of rssringoccs_CLDouble_Argument.                            */

#endif

#endif
/*  End of #if _RSS_RINGOCCS_USING_COMPLEX_H_ == 0.                           */
