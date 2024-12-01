#include <linux/module.h>
#include <linux/kernel.h>
#include "Export.h"

static int __init vc_init(void)
{
	printk(KERN_INFO "Import program is running\n");
	
	export_fn();
	
	printk(KERN_INFO "Imported symbol 'num' = %d from export.ko\n",num);
	printk(KERN_INFO"This is the module which is using exported symbols\n");
	return 0;
}

static void __exit vc_exit(void)
{
	printk(KERN_INFO "Exited\n");
}

module_init(vc_init);
module_exit(vc_exit);

MODULE_LICENSE("GPL");

MODULE_DESCRIPTION("IMPORTED FUNCTION");

MODULE_AUTHOR("VAISHNAVI CHIRMADE <vaishnavi.chirmade@gmail.com>");

