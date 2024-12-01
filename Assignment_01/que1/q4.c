#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

static char *towhom = "World";

module_param(towhom,charp,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);

static int count = 3;

module_param_named(cnt,count,int,0644);

//init
static int vc_init(void)
{
	int j;
	
	printk(KERN_INFO "%s : vc_init() called\n", THIS_MODULE->name);
	
	for(j=0; j <= count; j++)
	
		printk(KERN_INFO "Hello %s !\n", towhom);
		
	return 0;
}

//exit
static void vc_exit(void)
{
	int j;
	
	printk(KERN_INFO "%s : vc_exit() called\n", THIS_MODULE->name);
	
	for(j=0; j <= count; j++)
	
		printk(KERN_INFO "Bye %s !\n", towhom);
}

module_init(vc_init);
module_exit(vc_exit);

MODULE_LICENSE("GPL");

MODULE_DESCRIPTION("MODULE PARAMTERES");

MODULE_AUTHOR("VAISHNAVI CHIRMADE <vaishnavi.chirmade@gmail.com>");

