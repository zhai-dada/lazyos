BUILD_KERNEL := ../build/kernel

CFLAGS 	:=	-mcmodel=large -fno-builtin -fno-stack-protector -fno-pie -fno-pic -fno-common -nostartfiles -Wno-address-of-packed-member -m64 -I./inc/ -c -O0
LDFLAGS :=	-b elf64-x86-64 -z muldefs -z noexecstack

obj = 	$(BUILD_KERNEL)/head.o	\
		$(BUILD_KERNEL)/kernel.o

$(BUILD_KERNEL)/head.o:./src/head.S
	gcc -E -I./inc/ $< -o $(BUILD_KERNEL)/head.s
	as --64 $(BUILD_KERNEL)/head.s -o $@
$(BUILD_KERNEL)/kernel.o:./src/kernel.c
	gcc $(CFLAGS) $< -o $@


$(BUILD_KERNEL)/osImage:$(obj)
	ld $(LDFLAGS) $(obj) -o $@ -T ./kernel.lds

builddir:
	mkdir -p $(BUILD_KERNEL)

all: builddir $(BUILD_KERNEL)/osImage

.PHONY:builddir all

