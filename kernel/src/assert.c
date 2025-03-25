#include <assert.h>
#include <driver/serial.h>

void assert_failure(s8* exp, s8* file, s8* base, const s8* func, s32 line)
{
    serial_printf(SFRED, SBBLACK, "assert : ");
    serial_printf(SFRED, SBBLACK, "%s----->file:%s\tbase_file:%s\tfunc:%s\tline:%d\n", exp, file, base, func, line);
    return;
}
