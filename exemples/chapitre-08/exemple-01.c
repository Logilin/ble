/************************************************************************\
  exemple-01 - Chapitre "Drivers et modules personnels"

  Messages dans les traces du noyau au chargement et dechargement
  du module.

  Exemples de la formation "BSP Linux Embarqué"

  (c) 2005-2014 Christophe Blaess
  http://www.blaess.fr/christophe/

\************************************************************************/

#include <linux/module.h>

// Ecrivez une fonction "exemple_01_init" qui affiche un message dans
// les traces du noyau.


// Ecrivez une fonction "exemple_01_exit" qui affiche un message dans
// les traces du noyau.

module_init(solution_01_init);
module_exit(solution_01_exit);

MODULE_LICENSE("GPL");

