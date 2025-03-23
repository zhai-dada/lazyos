#include <lib/string.h>
#include <driver/serial.h>
#include <driver/vbe.h>
#include <uefi.h>
#include <gate.h>
#include <trap.h>

int kernel(void)
{
    char a[512] = {0};
    memcpy(a, "Hello\n", 7);
    serial_init();
    vbe_init();
    serial_printf(SFGREEN, SBBLACK, "%s", a);
    color_printk(YELLOW, BLACK, "%s\n", a);

    sys_vector_init();
    int b = 1 / 0;

    while(1)
    {
        ;
    }
    return SOK;
}