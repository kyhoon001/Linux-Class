cmd_/home/pi/Linux-Class/driver/coco.ko := ld -r  -EL -T ./scripts/module-common.lds -T ./arch/arm/kernel/module.lds  --build-id  -o /home/pi/Linux-Class/driver/coco.ko /home/pi/Linux-Class/driver/coco.o /home/pi/Linux-Class/driver/coco.mod.o ;  true