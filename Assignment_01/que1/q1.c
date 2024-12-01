#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

//init
static int vc_init(void)
{
	printk(KERN_INFO "Hello!\n");
	return 0;
}

//exit
static void vc_exit(void)
{
	printk(KERN_INFO "Bye!\n");
}

module_init(vc_init);
module_exit(vc_exit);

MODULE_LICENSE("GPL");

MODULE_DESCRIPTION("HELLO PROGRAM");

MODULE_AUTHOR("VAISHNAVI CHIRMADE <vaishnavi.chirmade@gmail.com>");
