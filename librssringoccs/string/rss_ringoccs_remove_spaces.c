
#include <stdlib.h>
#include <rss_ringoccs/include/rss_ringoccs_string.h>
RSS_RINGOCCS_EXPORT void rssringoccs_Remove_Spaces(char* s) {
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while ((*s++ = *d++));
}
