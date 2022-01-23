#include <rss_ringoccs/include/rss_ringoccs_ppm_plot.h>
RSS_RINGOCCS_EXPORT void rssringoccs_Color(unsigned char red, unsigned char green,
                       unsigned char blue, FILE *fp)
{
    fputc(red,   fp);
    fputc(green, fp);
    fputc(blue,  fp);
}
