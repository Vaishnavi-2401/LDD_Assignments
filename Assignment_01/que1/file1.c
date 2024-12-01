#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

MODULE_DESCRIPTION("HELLO PROGRAM");

MODULE_AUTHOR("VAISHNAVI CHIRMADE <vaishnavi.chirmade@gmail.com>");

static int vc_init(void)
{
        printk(KERN_INFO "Hello!\n");
        return 0;
}

module_init(vc_init);
