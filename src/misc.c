#include <stdint.h>
#include <string.h>

void *memrchr(const void *m, int c, size_t n)
{
    const unsigned char *s = (const unsigned char*)m;
    c = (unsigned char)c;
    while (n--) if (s[n]==c) return (void *)(s+n);
    return 0;
}

const char* home_dir = ".";

char *getenv(char* env_name)
{
    if (!strcmp(env_name, "HOME")) {
        return (char*)home_dir;
    }
    return NULL;
}
