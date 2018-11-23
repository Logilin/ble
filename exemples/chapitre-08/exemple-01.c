/************************************************************************\
  solution-01 - Chapitre "Drivers et modules personnels"

  Messages dans les traces du noyau au chargement et dechargement
  du module.

  Exemples de la formation "BSP Linux Embarqué"

  (c) 2005-2014 Christophe Blaess
  http://www.blaess.fr/christophe/

\************************************************************************/

#include <linux/module.h>

static int __init solution_01_init (void)
{
	printk(KERN_INFO "%s: Hello...\n", THIS_MODULE->name);
	return 0; 
}
 
static void __exit solution_01_exit (void)
{
	printk(KERN_INFO "%s: Bye!\n", THIS_MODULE->name);
}

module_init(solution_01_init);
module_exit(solution_01_exit);

MODULE_LICENSE("GPL");

