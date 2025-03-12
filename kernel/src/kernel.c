#include <lib/string.h>

int kernel(void)
{
    char a[512] = {0};
    memcpy(a, "Hello\n", 7);
    while(1)
    {
        ;
    }
    return 0;
}