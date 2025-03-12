#include <lib/string.h>
#include <driver/serial.h>

int kernel(void)
{
    char a[512] = {0};
    memcpy(a, "Hello\n", 7);
    serial_init();
    serial_printf(SFGREEN, SBBLACK, "%s", a);
    while(1)
    {
        ;
    }
    return 0;
}