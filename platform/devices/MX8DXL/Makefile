
objs_mx8 := system_MX8DXL.o handlers_MX8DXL.o

ifdef ROM
objs_mx8 += gcc/startup_rom_MX8DXL.o
else
objs_mx8 += gcc/startup_MX8DXL.o
endif

OBJS += \
  $(foreach object,$(objs_mx8),$(OUT)/devices/MX8DXL/$(object))

DIRS += $(OUT)/devices/MX8DXL/gcc

