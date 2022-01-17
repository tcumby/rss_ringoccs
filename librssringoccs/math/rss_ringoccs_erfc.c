/*  Header file which contains aliases for the function in the standard C     *
 *  library math.h. This allows compatibility of C89 and C99 math.h headers.  */
#include <rss_ringoccs/include/rss_ringoccs_math.h>

RSS_RINGOCCS_EXPORT float rssringoccs_Float_Erfc(float x)
{
    float erfc;
    erfc = rssringoccs_Float_Exp(x*x)*rssringoccs_Float_Erfcx(x);

    return erfc;
}

RSS_RINGOCCS_EXPORT double rssringoccs_Double_Erfc(double x)
{
    double erfc;
    erfc = rssringoccs_Double_Exp(x*x)*rssringoccs_Double_Erfcx(x);

    return erfc;
}

long double rssringoccs_LDouble_Erfc(long double x)
{
    long double erfc;
    erfc = rssringoccs_LDouble_Exp(x*x)*rssringoccs_LDouble_Erfcx(x);

    return erfc;
}
