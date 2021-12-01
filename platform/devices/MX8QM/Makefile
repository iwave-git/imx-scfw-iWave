
objs_mx8 := system_MX8QM.o handlers_MX8QM.o

ifdef ROM
objs_mx8 += gcc/startup_rom_MX8QM.o
else
objs_mx8 += gcc/startup_MX8QM.o
endif

OBJS += \
  $(foreach object,$(objs_mx8),$(OUT)/devices/MX8QM/$(object))

DIRS += $(OUT)/devices/MX8QM/gcc

