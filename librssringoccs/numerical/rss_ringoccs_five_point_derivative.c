#include <rss_ringoccs/include/rss_ringoccs_math.h>
#include <rss_ringoccs/include/rss_ringoccs_numerical.h>

float rssringoccs_Float_Five_Point_Derivative(float (*f)(float),
                                              float x, float h)
{
    float y0, y1 ,y2, y3, der;

    y0 = -f(x + 2*h);
    y1 =  8*f(x + h);
    y2 = -8*f(x - h);
    y3 = f(x - 2*h);

    der = (y0 + y1 + y2 + y3)/(12.0*h);

    return der;
}

double rssringoccs_Double_Five_Point_Derivative(double (*f)(double),
                                                double x, double h)
{
    double y0, y1 ,y2, y3, der;

    y0 = -f(x + 2*h);
    y1 =  8*f(x + h);
    y2 = -8*f(x - h);
    y3 = f(x - 2*h);

    der = (y0 + y1 + y2 + y3)/(12.0*h);

    return der;
}

long double
rssringoccs_LongDouble_Five_Point_Derivative(long double (*f)(long double),
                                             long double x, long double h)
{
    long double y0, y1 ,y2, y3, der;

    y0 = -f(x + 2*h);
    y1 =  8*f(x + h);
    y2 = -8*f(x - h);
    y3 = f(x - 2*h);

    der = (y0 + y1 + y2 + y3)/(12.0*h);

    return der;
}
