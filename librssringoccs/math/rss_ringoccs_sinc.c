/*  The C Standard Library header for math functions and more found here.     */
#include <rss_ringoccs/include/rss_ringoccs_math.h>

RSS_RINGOCCS_EXPORT float rssringoccs_Float_Sinc(float x)
{
    float y;

    if (x == 0.0F)
        y = 1.0F;
    else
        y = rssringoccs_Float_Sin(x)/x;

    return y;
}

RSS_RINGOCCS_EXPORT double rssringoccs_Double_Sinc(double x)
{
    double y;

    if (x == 0.0)
        y = 1.0;
    else
        y = rssringoccs_Double_Sin(x)/x;

    return y;
}

RSS_RINGOCCS_EXPORT long double rssringoccs_LDouble_Sinc(long double x)
{
    long double y;

    if (x == 0.0L)
        y = 1.0L;
    else
        y = rssringoccs_LDouble_Sin(x)/x;

    return y;
}
