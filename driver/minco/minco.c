#include <linux/module.h>

static int minco_init(void)
{
	printk( KERN_INFO "hi\n");
	printk( "<0>""hi\n");
	// printk("<0>""hi" 나 "<0>hi" 나 같음 c언어 문법
	printk( "<1>"" hi\n");
	printk( "<2>hi\n");
	printk( "<3>"" hi\n");
	printk( "<4>hi\n");
	printk( "<5>hi\n");
	printk( "<6>hi\n");
	printk( "<7>hi\n");
	return 0;
}

static void minco_exit(void)
{
	printk( KERN_INFO "bye\n");
}

module_init(minco_init);
module_exit(minco_exit);
