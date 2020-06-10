KERNEL_HEADERS=/lib/modules/$(shell uname -r)/build

obj-m := hi.o

all :
	@$(MAKE) -C $(KERNEL_HEADERS) M=$(PWD) modules

clean:
	@$(MAKE) -C $(KERNEL_HEADERS) M=$(PWD) clean
