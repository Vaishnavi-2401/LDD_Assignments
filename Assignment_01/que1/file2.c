#include <linux/module.h>
#include <linux/kernel.h>

static void vc_exit(void)
{
        printk(KERN_INFO "Bye!\n");
}

module_exit(vc_exit);     
