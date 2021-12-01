
ifeq ($(D),1)
objs_utilities := newlib_stubs.o

OBJS += \
  $(foreach object,$(objs_utilities),$(OUT)/utilities/$(object))

DIRS += $(OUT)/utilities
endif

