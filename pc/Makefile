CROSS_COMPILE:=gcc
STRIP = strip
OS=OS_LINUX
PRO_CFLAGS ?= -D OMW -D ARCH_ARM -D ${OS} -g  -rdynamic -fexceptions -O0 -std=gnu99 -D UART_VERB

FLAGS_LIB=-lm -lpthread -ldl -lrt 


OS_MD=$(shell pwd)/os_middleware
JZAPI=$(shell pwd)/os_middleware/JDBsp/jzapi
JDASP=$(shell pwd)/os_middleware/JDAsp
STPTLC=$(shell pwd)/os_middleware/JDBsp/stptlc

SRC=$(wildcard $(shell pwd)/*.c \
	$(JDASP)/*.c \
	$(STPTLC)/*.c \
	$(JZAPI)/linux_src/*.c \
) 

HEAD=$(wildcard $(shell pwd)/*.h \
	$(JZAPI)/include/*.h \
	$(OS_MD)/*.h \
	$(STPTLC)/*.h \
)

INCLUDE_DIRS += -I $(OS_MD)
INCLUDE_DIRS += -I $(JZAPI)/include
INCLUDE_DIRS += -I $(STPTLC)
INCLUDE_DIRS += -I $(shell pwd)

#object
OBJ=uart_test
all: $(OBJ)
$(OBJ):$(SRC) $(HEAD)  $(DEPEND_SRC) $(DEPEND_HEAD)
		$(CROSS_COMPILE)  -o $@ \
		$(SRC) \
		$(DEPEND_SRC) \
		$(INCLUDE_DIRS) \
		$(FLAGS_LIB) \
		$(PRO_CFLAGS)
clean:
	rm  $(OBJ) -rf
