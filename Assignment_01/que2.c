#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vaishnavi Chirmade <vaishnavi.chirmade@gmail.com>");
MODULE_DESCRIPTION("A Kernel Module to List Loaded Kernel Modules");


static int __init listofmodules_init(void)
{
    struct module *mod;

    printk(KERN_INFO "Kernel Module List:\n");
    
    list_for_each_entry(mod, THIS_MODULE->list.prev, list) {
        printk(KERN_INFO "Module Name: %s\n", mod->name);
    }

    return 0; 
}

static void __exit listofmodule_exit(void)
{
    printk(KERN_INFO "Exiting Kernel Module Listing Module.\n");
}

module_init(listofmodule_init);
module_exit(listofmodule_exit);

