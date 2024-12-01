#include <linux/module.h>
#include <linux/kernel.h>
#include "Export.h"

int num = 100;

//init
static int __init vc_init(void)
{
	
	printk(KERN_INFO "Export part to print\n");
	return 0;
}

//exit
static void __exit vc_exit(void)
{
	printk(KERN_INFO "Exited\n");
}

//export
void export_fn(void)
{
	printk(KERN_INFO "Exported Function Executed\n");
}

module_init(vc_init);
module_exit(vc_exit);

EXPORT_SYMBOL(export_fn);
EXPORT_SYMBOL(num);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("EXPORT DEMO");
MODULE_AUTHOR("VAISHNAVI CHIRMADE <vaishnavi.chirmade@gmail.com>");
