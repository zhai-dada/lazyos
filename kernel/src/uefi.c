#include <uefi.h>

// UEFI保存所需数据的存放地址，具体参考UEFI代码
struct KERNEL_BOOT_INFORMATION* boot_info = (struct KERNEL_BOOT_INFORMATION *)0xffff800000060000;

