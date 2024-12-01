#include<linux/module.h>
#include<linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vaishnavi Chirmade <vaishnavi.chirmade@gmail.com>");
MODULE_DESCRIPTION("A Kernel Module to Display Processes Starting from Current Process");
MODULE_VERSION("1.0");

static int __init process_list_init(void)
{
	struct task_struct *root = current;
	printk(KERN_INFO"%s:process_list_init() started..!!",THIS_MODULE->name);

        printk(KERN_INFO "Starting process: %s [PID = %d]\n", current->comm, current->pid);
	while (root->parent != root)
       	{ 
        printk(KERN_INFO "Parent process: %s [PID = %d]\n", root->parent->comm, root->parent->pid);
        root = root->parent;
        }
    return 0;
}

static void __exit process_list_exit(void)
{
    printk(KERN_INFO "Process List Module Exited\n");
}

module_init(process_list_init);
module_exit(process_list_exit);

