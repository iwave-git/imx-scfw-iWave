
objs_main := main.o main_common.o boot.o

ifeq ($(HW), SIMU)
	objs_main += main_simu.o
endif

ifndef NO_IPC
	objs_main += rpc.o ipc_srv.o

	ifeq ($(HW), REAL)
	    objs_main += ipc.o
	else
	    objs_main += ipc_simu.o
	endif
endif

ifeq ($(M),1)
	objs_main += monitor.o
endif

ifeq ($(EM),1)
	objs_main += monitor.o
endif

OBJS += \
  $(foreach object,$(objs_main),$(OUT)/main/$(object))

DIRS += $(OUT)/main

