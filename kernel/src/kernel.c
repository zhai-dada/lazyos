#include <lib/string.h>
#include <driver/serial.h>
#include <driver/vbe.h>
#include <uefi.h>
#include <gate.h>
#include <trap.h>
#include <task.h>
#include <cpu.h>

int kernel(void)
{
    char a[512] = {0};
    memcpy(a, "Hello\n", 7);
    serial_init();
    vbe_init();
    serial_printf(SFGREEN, SBBLACK, "%s", a);
    color_printk(YELLOW, BLACK, "%s\n", a);

    set_tss_descriptor(10, (void *)&tss[0]); // tss 0 
    load_tr(10);

    sys_vector_init();
    
    get_cpuinfo();

    // int b = 1 / 0;
    int* aa = (int*)0xffff80000aa00000;
    *aa = 10;
    while (1)
    {
        ;
    }
    return SOK;
}