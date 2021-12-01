
include $(SRC)/test/$(CONFIG)/test.bom

TEST_DIRNAME=platform/test/drv
ifneq "$(wildcard $(TEST_DIRNAME) )" ""
    TEST_TARGET := $(shell find platform/test -name test_$(LOWER_T).c -printf "%P\n")
else
    TEST_DIRNAME2=$(OUT)/test
    ifneq "$(wildcard $(TEST_DIRNAME2) )" ""
        TEST_TARGET := $(shell find $(OUT)/test -name test_$(LOWER_T).o -printf "%P\n")
    endif
endif

ifeq ($(LOWER_T), all)
    TEST_TARGET := $(CONFIG)/test_all.c
endif

ifneq ($(UPPER_T), NONE)
    objs_test += common/test.o $(TEST_TARGET:.c=.o)
endif

ifeq ($(LOWER_T), all)
    objs_test += $(AUTO_TEST)
endif

OBJS += \
  $(foreach object,$(objs_test),$(OUT)/test/$(object))

EOBJS = $(OUT)/test/common/test.o $(OUT)/test/$(CONFIG)/test_all.o

EOBJS += \
  $(foreach object,$(AUTO_TEST),$(OUT)/test/$(object))

EOBJS += \
  $(foreach object,$(EXPT_TEST),$(OUT)/test/$(object))

DIRS += $(OUT)/test $(OUT)/test/common $(OUT)/test/drv $(OUT)/test/ss \
        $(OUT)/test/svc $(OUT)/test/misc $(OUT)/test/ddr  $(OUT)/test/sys \
        $(OUT)/test/$(CONFIG)

