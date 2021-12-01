
ifeq ($(HW), REAL)
	objs_devices := startup.o memops.o memops_test.o memcpy-armv7m.o aeabi_memset-thumb2.o
else
	objs_devices := stub.o
endif

OBJS += \
  $(foreach object,$(objs_devices),$(OUT)/devices/$(object))

DIRS += $(OUT)/devices

ifeq ($(HW), REAL)

	SUBCOMPS := $(DEVICE)

	include $(foreach subcomp,$(SUBCOMPS),$(rootdir)/$(SRC)/devices/$(subcomp)/Makefile)

endif

