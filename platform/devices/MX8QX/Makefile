
objs_mx8 := system_MX8QX.o handlers_MX8QX.o

ifdef ROM
objs_mx8 += gcc/startup_rom_MX8QX.o
else
objs_mx8 += gcc/startup_MX8QX.o
endif

OBJS += \
  $(foreach object,$(objs_mx8),$(OUT)/devices/MX8QX/$(object))

DIRS += $(OUT)/devices/MX8QX/gcc

