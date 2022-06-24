#include <stdint.h>
#include <string.h>

void *memrchr(const void *m, int c, size_t n)
{
    const unsigned char *s = (const unsigned char*)m;
    c = (unsigned char)c;
    while (n--) if (s[n]==c) return (void *)(s+n);
    return 0;
}
