#include <gate.h>

static void set_gate(idt_t *gate_addr, u8 attr, u8 ist, void *code_addr)
{
    // 对着IDT结构写

    u64 d0 = 0, d1 = 0;
    
    // 低 16 位：code_addr 的低 16 位
    d0 = 0 | ((u64)(void*)code_addr & 0xFFFF);

    // 段选择子 0x08 64位代码段
    d0 |= (u64)(0x8 << 16);

    // 属性 + IST
    d0 |= ((u64)attr << 40);        // 属性值（包含 Type, DPL, P）
    d0 |= ((u64)(ist & 0x7) << 32); // IST 仅保留 3 位

    // 代码地址的中间 16 位
    d0 |= (((u64)(void*)code_addr >> 16) & 0xFFFF) << 48;

    // 高 32 位
    d1 = ((u64)(void*)code_addr >> 32);

    // 写入 IDT 表
    gate_addr->idt_low = d0;
    gate_addr->idt_high = d1;
    return;
}

void set_intr_gate(u32 n, u8 ist, void *addr)
{
    // P, DPL = 0, TYPE = E
    set_gate(idt_table + n, 0x8E, ist, addr);
    return;
}
void set_trap_gate(u32 n, u8 ist, void *addr)
{
    // P, DPL = 0, TYPE = F
    set_gate(idt_table + n, 0x8F, ist, addr);
    return;
}
void set_system_intr_gate(u32 n, u8 ist, void *addr)
{
    // P, DPL = 3, TYPE = E
    set_gate(idt_table + n, 0xEE, ist, addr);
    return;
}
void set_system_trap_gate(u32 n, u8 ist, void *addr)
{
    // P DPL = 3, TYPE = F
    set_gate(idt_table + n, 0xEF, ist, addr);
    return;
}