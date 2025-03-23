#include <task.h>

tss_t tss[MAX_CPUNUM] = 
{
    [0 ... MAX_CPUNUM - 1] = INIT_TSS,
};
