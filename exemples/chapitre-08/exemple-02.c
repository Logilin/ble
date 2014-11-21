/************************************************************************\
  solution-02 - Chapitre "Drivers et modules personnels"

  Driver permettant le pilotage en GPIO de la led du Raspberry Pi.

  Exemples de la formation "BSP Linux Embarqué"

  (c) 2005-2014 Christophe Blaess
  http://www.blaess.fr/christophe/

\************************************************************************/

#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <asm/uaccess.h>

					
	#define RPI_GPIO_LED  16

	static ssize_t exemple_write (struct file * filp, const char * buffer,
	                              size_t length, loff_t * offset);


	static struct file_operations fops_exemple = {
		.owner   =  THIS_MODULE,
		// inserer un lien vers la methode "exemple_write".
	};


	static struct miscdevice exemple_misc_driver = {
		    .minor          = MISC_DYNAMIC_MINOR,
		    .name           = THIS_MODULE->name,
		    .fops           = & fops_exemple,
	};


static int __init exemple_init (void)
{
	// Demander l'acces à la GPIO de la led.
	
	// Placer la GPIO de la led en sortie.

	// Enregistrer le driver dans le sous-systeme "misc".
	return 0;
}


static void __exit exemple_exit (void)
{
	// Retirer le driver du sous-systeme "misc".

	// Liberer la GPIO de la led.
}


static ssize_t exemple_write(struct file * filp, const char * u_buffer,
                             size_t length, loff_t * offset)
{
	char k_buffer[80];
	int val;

	if (length > 79)
		return -ENOMEM;

	// Copier le u_buffer (espace utilisateur) dans le k_buffer (kernel).

	// Lire dans le k_buffer la valeur transmise.

	// Fixer la GPIO de la led a la valeur indiquee.

	return length;
}


module_init(exemple_init);
module_exit(exemple_exit);
MODULE_LICENSE("GPL");

