/************************************************************************\
  solution-02 - Chapitre "Drivers et modules personnels"

  Driver permettant le pilotage en GPIO de la led du Raspberry Pi.

  Exemples de la formation "BSP Linux Embarqué"

  (c) 2005-2022 Christophe Blaess
  http://www.blaess.fr/christophe/

\************************************************************************/

#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <asm/uaccess.h>

	#define RPI_GPIO_LED 16

	static ssize_t exemple_write (struct file * filp, const char * buffer,
	                              size_t length, loff_t * offset);


	static struct file_operations fops_exemple = {
		.owner   =  THIS_MODULE,
		.write   =  exemple_write,
	};


	static struct miscdevice exemple_misc_driver = {
		    .minor          = MISC_DYNAMIC_MINOR,
		    .name           = THIS_MODULE->name,
		    .fops           = & fops_exemple,
	};


static int __init exemple_init (void)
{
	int err;

	if ((err = gpio_request(RPI_GPIO_LED,THIS_MODULE->name)) != 0) {
		return err;
	}

	if ((err = gpio_direction_output(RPI_GPIO_LED,1)) != 0) {
		gpio_free(RPI_GPIO_LED);
		return err;
	}
	if ((err = misc_register(& exemple_misc_driver)) != 0) {
		gpio_free(RPI_GPIO_LED);
		return err;
	}
	return 0;
}


static void __exit exemple_exit (void)
{
	misc_deregister(& exemple_misc_driver);
	gpio_free(RPI_GPIO_LED);
}


static ssize_t exemple_write(struct file * filp, const char * buffer,
                             size_t length, loff_t * offset)
{
	char k_buffer[80];
	int val;

	if (length > 79)
		return -ENOMEM;
	if (copy_from_user(k_buffer, buffer, length) != 0)
		return -EFAULT;
	if (sscanf(k_buffer, "%d", & val) != 1)
		return -EINVAL;
	gpio_set_value(RPI_GPIO_LED, val);
	return length;
}


module_init(exemple_init);
module_exit(exemple_exit);
MODULE_LICENSE("GPL");

