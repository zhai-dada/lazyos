#include <task.h>

tss_t tss[CPUNUM] = 
{
    [0 ... CPUNUM - 1] = INIT_TSS,
};
