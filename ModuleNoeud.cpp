    /*___________________________________________________________________*/
   //                                                                    // 
  //                                                                    //
 //                                                                    //
/*____________________________________________________________________*/
/*          Nom du module : ModuleNoeud.cpp                          */
/*...................................................................*/
/*         Description du module:    Le module ModuleAnneau.cpp      */
/*         contient les definitions dans le sens de l'implementation */
/*         des fonctions   qui font   partie de ce dernier.          */
/*                                                                   */
/*...................................................................*/
/*          Par    :        equipe 04                                */
/*...................................................................*/    //
/*          Date   : mardi le 13 juillet le 2021                     */   //
/*...................................................................*/  //
/*    Derni�re modification : samedi 31 juillet  2021 05:57 P.M      */ //
/*___________________________________________________________________*///
/*    propelled by       C   H    N   O                              */
/*                          8  10   4   2                            */
/*___________________________________________________________________*/
/*                        GBS enabled                                */
/*___________________________________________________________________*/

/*___________________________________________________________________________*/
/*			   Commandes préprocesseur et modules	     		             */
/*___________________________________________________________________________*/

/*___________________________________________________________________________*/
/*						 Fichier(s) d'en-tête  	     	  	                 */
/*___________________________________________________________________________*/
#include "ModuleNoeud.h"

/*  ___________________________________________________________________________
	Nom	:			t_noeud_init
	___________________________________________________________________________
	Description :	Constructeur du type noeud. Initialise un noeud vide
	___________________________________________________________________________
	Paramètres :	Aucuns.
	___________________________________________________________________________
	Retour :	   Un pointeur vers un noeud
	___________________________________________________________________________
	Requis 1 :     Si la fonction reçoit une référence nulle comme noeud, 
	               afficher un message d’erreur et quitter avec le code 
				   EXIT_FAILURE.
	___________________________________________________________________________
	Requis 2 :     Vous devez initialiser la mémoire avec des zéros.
	___________________________________________________________________________
	Requis 3 :     Vous devez vous assurer que l’allocation de mémoire est
	               réussie.
    ___________________________________________________________________________
	Requis 4 :     Vous devez initialiser les enfants du noeud par des 
	              références vides
	___________________________________________________________________________
	Test associé :  Aucun
	___________________________________________________________________________
	Spécification : N/A
	___________________________________________________________________________
*/
t_noeud* t_noeud_init()
{
	//Allocation de memoire pour un noeud
	t_noeud* nouveau_noeud = (t_noeud*)calloc(1, sizeof(t_noeud));
	//Verification de l'allocation de memoire
	if (nouveau_noeud == nullptr)
	{
		printf("ModuleNoeud: t_noeud_init: Erreur d'allocation de memoire!");
		exit(EXIT_FAILURE);
	}
	//On initialise les donnees du noeud avec des pointeurs nuls.
	nouveau_noeud->gauche = nullptr;
	nouveau_noeud->droit = nullptr;
	//On renvoi le pointeur du nouveau noeud.
	return nouveau_noeud;
}

/*  ___________________________________________________________________________
	Nom	:			t_noeud_detruire
	___________________________________________________________________________
	Description :	Cette fonction libère la mémoire allouée à un noeud.
	___________________________________________________________________________
	Paramètres :	Un pointeur vers un noeud.
	___________________________________________________________________________
	Retour :	   Un pointeur vers un noeud
	___________________________________________________________________________
	Requis 1 :    Si la fonction reçoit une référence nulle comme anneau,
	             afficher un message d’erreur et quitter avec le code
				 EXIT_FAILURE.
	___________________________________________________________________________
	Test associé :  Aucun
	___________________________________________________________________________
*/
void t_noeud_detruire(t_noeud* noeud)
{
	//Verification que le noeud recu est valide.
	if (noeud == nullptr)
	{
		printf("ModuleNoeud: t_noeud_detruire: Reference nulle recu!");
	}
	//On libere la memoire associe au noeud.
	free(noeud);
}

/*  ___________________________________________________________________________
	Nom	:		    t_noeud_set_valeur
	___________________________________________________________________________
	Description :   Mutateur de la valeur d’un noeud.
	___________________________________________________________________________
	Paramètres :   Un pointeur vers un noeud.
                   Un entier qui correspond à la valeur du noeud.
	___________________________________________________________________________
	Retour :	   Un entier qui correspond à la valeur du noeud.
	___________________________________________________________________________
	Requis 1 :    Si la fonction reçoit une référence nulle comme noeud,
	              afficher un message d’erreur et quitter avec le code 
				  EXIT_FAILURE.
	___________________________________________________________________________
	Test associé :  Vous devez rédiger un test nommé t_noeud_set_valeur_test qui
                    démontre le fonctionnement de cette fonction.
	___________________________________________________________________________
*/
int t_noeud_set_valeur(t_noeud* noeud, const int valeur_set)
{
	//Verification que le noeud recu est valide.
	if (noeud == nullptr)
	{
		printf("ModuleNoeud: t_noeud_set_valeur: Reference nulle recu!");
		exit(EXIT_FAILURE);
	}
	//On assigne la nouvelle valeur du noeud.
	noeud->valeur = valeur_set;
	//On renvoi la nouvelle valeur du noeud.
	return noeud->valeur;
}

/*  ___________________________________________________________________________
	Nom	:		    t_noeud_set_droit 
	___________________________________________________________________________
	Description :  Mutateur de l’enfant gauche d’un noeud.
	___________________________________________________________________________
	Paramètres :   Un pointeur vers un noeud.
                   Un pointeur vers le nouveau de droit.  
	___________________________________________________________________________
	Retour :	  Un entier qui corresont à un indicateur de succès.
	___________________________________________________________________________
	Requis 1 :   Si la fonction reçoit une référence nulle comme noeud, 
	             afficher un message d’erreur et quitter avec le code
				 EXIT_FAILURE.
	___________________________________________________________________________
	Test associé :  Aucun.
	___________________________________________________________________________
*/
int t_noeud_set_droit(t_noeud* noeud, t_noeud* droit_set)
{
	//Verification que le noeud recu est valide.
	if (noeud == nullptr)
	{
		printf("ModuleNoeud: t_noeud_set_droit: Reference nulle recu!");
		exit(EXIT_FAILURE);
	}
	//On assigne le nouveau voisin de droite du noeud.
	noeud->droit = droit_set;
	//On renvoi une mention de succes.
	return EXIT_SUCCESS;
}

/*  ___________________________________________________________________________
	Nom	:		   t_noeud_set_gauche
	___________________________________________________________________________
	Description :  Mutateur de l’enfant gauche d’un noeud.
	___________________________________________________________________________
	Paramètres :   Un pointeur vers un noeud.
                   Un pointeur vers le noeud de gauche.
	___________________________________________________________________________
	Retour :	  Un entier qui corresont à un indicateur de succès
	___________________________________________________________________________
	Requis 1 :   Si la fonction reçoit une référence nulle comme noeud,
	             afficher un message d’erreur et quitter avec le code
				 EXIT_FAILURE.
   ___________________________________________________________________________
	Test associé :  Aucun.
	___________________________________________________________________________
*/
int t_noeud_set_gauche(t_noeud* noeud, t_noeud* gauche_set)
{
	//Verification que le noeud recu est valide.
	if (noeud == nullptr)
	{
		printf("ModuleNoeud: t_noeud_set_gauche: Reference nulle recu!");
		exit(EXIT_FAILURE);
	}
	//On assigne le nouveau voisin de gauche du noeud.
	noeud->gauche = gauche_set;
	//On renvoi une mention de succes.
	return EXIT_SUCCESS;
}

/*  ___________________________________________________________________________
	Nom	:		   t_noeud_get_valeur
	___________________________________________________________________________
	Description :  Accesseur de la valeur d’un noeud.
	___________________________________________________________________________
	Paramètres :  Un pointeur vers un noeud.
	___________________________________________________________________________
	Retour :	  Un entier qui corresont à un indicateur de succès
	___________________________________________________________________________
	Requis 1 :  Si la fonction reçoit une référence nulle comme noeud,
	            afficher un message d’erreur et quitter avec le code 
				EXIT_FAILURE.
   ___________________________________________________________________________
	Test associé :  Vous devez rédiger un test nommé t_noeud_get_valeur_test qui
                    démontre le fonctionnement de cette fonction.
	___________________________________________________________________________
*/
int t_noeud_get_valeur(const t_noeud* noeud)
{
	//Verification que le noeud recu est valide.
	if (noeud == nullptr)
	{
		printf("ModuleNoeud: t_noeud_get_valeur: Reference nulle recu!");
		exit(EXIT_FAILURE);
	}
	//On renvoi la valeur du noeud.
	return noeud->valeur;
}

/*  ___________________________________________________________________________
	Nom	:		   t_noeud_get_droit 
	___________________________________________________________________________
	Description :  Accesseur de l’enfant droit d’un noeud.accesseur de l'enfant 
	               droit d'un noeud
	___________________________________________________________________________
	Paramètres :   Un pointeur vers un noeud.
	___________________________________________________________________________
	Retour :	   Un pointeur vers un noeud.
	___________________________________________________________________________
	Requis 1 :  Si la fonction reçoit une référence nulle comme noeud, 
	            afficher un message d’erreur et quitter avec le code
				EXIT_FAILURE.
   ___________________________________________________________________________
	Test associé :  Vous devez rédiger un test nommé t_noeud_get_droit_test qui
                    démontre le fonctionnement de cette fonction.
	___________________________________________________________________________
*/
t_noeud* t_noeud_get_droit(const t_noeud* noeud)
{
	//Verification que le noeud recu est valide.
	if (noeud == nullptr)
	{
		printf("ModuleNoeud: t_noeud_get_droit: Reference nulle recu!");

		exit(EXIT_FAILURE);
	}
	//On renvoi l'adresse du voisin de droite.
	return noeud->droit;
}

/*  ___________________________________________________________________________
	Nom	:		   t_noeud_get_gauche
	___________________________________________________________________________
	Description :  Accesseur de l’enfant gauche d’un noeud.
	___________________________________________________________________________
	Paramètres :   Un pointeur vers un noeud.
	___________________________________________________________________________
	Retour :	   Un pointeur vers un noeud.
	___________________________________________________________________________
	Requis 1 : Si la fonction reçoit une référence nulle comme noeud, afficher
	           un  message d’erreur et quitter avec le code EXIT_FAILURE.       
   ___________________________________________________________________________
	Test associé :  Vous devez rédiger un test nommé t_noeud_get_gauche_test
                    qui démontre le fonctionnement de cette fonction.
	___________________________________________________________________________
*/
t_noeud* t_noeud_get_gauche(const t_noeud* noeud)
{
	//Verification que le noeud recu est valide.
	if (noeud == nullptr)
	{
		printf("ModuleNoeud: t_noeud_get_gauche: Reference nulle recu!");
		exit(EXIT_FAILURE);
	}
	//On renvoi l'adresse du voisin de gauche.
	return noeud->gauche;
}

