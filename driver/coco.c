#include <linux/module.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <asm/io.h>


#define LL "\0014"

#define GPIO1_IN(g)  (*(gpio+1) &= ~(7<<(g%10*3)))
#define GPIO1_OUT(g) (*(gpio+1) |= (1<<(g%10*3)))
#define GPIO_SET(g)  (*(gpio+7) |= (1<<g))
#define GPIO_CLR(g)  (*(gpio+10) |= (1<<g))

volatile unsigned int * gpio;

static int coco_open(struct inode *inode, struct file *filp)
{
	printk( LL "welcome\n");
	return 0;
}
static int coco_release(struct inode *inode, struct file *filp)
{
	printk(LL "re re re release \n");
	return 0;

}

ssize_t coco_read(struct file *filp, char *buf, size_t count, loff_t *ppos)
{
	buf[0] = 'H';
	buf[1] = 'I';
	buf[2] = '\0';
	return count;
}

ssize_t coco_write(struct file *filp, const char* buf, size_t count, loff_t* ppos)
{
	printk( KERN_INFO "app message : %s\n", buf);
	return count;
}


long coco_ioctl(struct file* filp, unsigned int cmd, unsigned long arg)
{
	printk( LL "Hi Im IOCTL\n");

	switch(cmd) {
		case 100:
			printk( LL "ABC\n");
			break;
		case 200:
			printk( LL "BBC\n");
			break;
		case 300 :
			printk(LL "CCC\n");
			break;
	}
	return 17;
}


static struct file_operations fops = {
	.open = coco_open,
	.release = coco_release,
	.write = coco_write,
	.read = coco_read,
	.unlocked_ioctl = coco_ioctl,
};




static int coco_init(void)
{
	/*
	printk( KERN_INFO "hi\n");
	// printk("<0>""hi" 나 "<0>hi" 나 같음 c언어 문법
	printk( "<7>hi\n");

	*/

	if(register_chrdev(141, "coco", &fops) < 0) {
		printk( LL "REG ERROR");
		return -1;
	}


	static void *map;
	map = ioremap(0xFE200000, 256);
	gpio = (volatile unsigned int *) map;
	
	GPIO1_OUT(18);
	GPIO_SET(18);


	printk( LL "hi\n");

	return 0;
}

static void coco_exit(void)
{
	GPIO_CLR(18);

	unregister_chrdev(141, "coco");
	printk( KERN_INFO "bye\n");
}

module_init(coco_init);
module_exit(coco_exit);
MODULE_LICENSE("GPL");
