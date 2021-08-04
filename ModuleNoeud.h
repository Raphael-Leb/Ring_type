#pragma once
    /*___________________________________________________________________*/
   //                                                                    // 
  //                                                                    //
 //                                                                    //
/*____________________________________________________________________*/
/*          Nom du module : ModuleNoeud.h						     */
/*...................................................................*/
/*           Description du module:    Le module ModuleNoeud.h       */
/*           contient les d�clarations des fonctions   qui font      */
/*            partie de ce dernier                                   */
/*...................................................................*/
/*          Par    :        �quipe 04                                */
/*...................................................................*/    //
/*          Date   : mardi le 13 juillet  2021                       */   //
/*...................................................................*/  //
/*    Derni�re modification : samedi 31 juillet  2021 05:48 P.M      */ //
/*___________________________________________________________________*///
/*    propelled by       C   H    N   O                              */
/*                          8  10   4   2                            */
/*___________________________________________________________________*/
/*                        GBS enabled                                */
/*___________________________________________________________________*/

/*___________________________________________________________________________*/
/*			   Commandes préprocesseur et modules	     		             */
/*___________________________________________________________________________*/
#include <stdio.h>
#include <stdlib.h>
/*___________________________________________________________________________*/
/*						 Fichier(s) d'en-tête  	     	  	                 */
/*___________________________________________________________________________*/


/*  ___________________________________________________________________________
	Nom	:			noeud
	___________________________________________________________________________
	Description :	Enregistrement
	___________________________________________________________________________
	Paramètres :	
	___________________________________________________________________________
	Retour :	   
	___________________________________________________________________________
	Requis 1 :     
	___________________________________________________________________________
	Requis 2 :     
	___________________________________________________________________________
	Requis 3 :   
	___________________________________________________________________________
	Requis 4 :     
	___________________________________________________________________________
	Test associé :  
	___________________________________________________________________________
	Spécification : 
	___________________________________________________________________________
*/
typedef struct noeud
{
	struct noeud* gauche;	// Le noeud qui precede le noeud actuel.
	struct noeud* droit;		// Le noeud qui suit le noeud actuel.
	int valeur;			// La valeur du noeud.
}t_noeud;

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
t_noeud* t_noeud_init();

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
void t_noeud_detruire(t_noeud* noeud);

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
int t_noeud_set_valeur(t_noeud* noeud, const int valeur_set);

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
int t_noeud_set_droit(t_noeud* noeud, t_noeud* droit_set);

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
int t_noeud_set_gauche(t_noeud* noeud, t_noeud* gauche_set);

/*  ___________________________________________________________________________
	Nom	:		   t_noeud_get_valeur
	___________________________________________________________________________
	Description :  Accesseur de la valeur d’un noeud.
	___________________________________________________________________________
	Paramètres :  Un pointeur vers un noeud.
	___________________________________________________________________________
	Retour :	  Un entier qui correspont à un indicateur de succès
				  retourne la reference vers la valeur d'un noeud
	___________________________________________________________________________
	Requis 1 :  Si la fonction reçoit une référence nulle comme noeud,
				afficher un message d’erreur et quitter avec le code
				EXIT_FAILURE.
   ___________________________________________________________________________
	Test associé :  Vous devez rédiger un test nommé t_noeud_get_valeur_test qui
					démontre le fonctionnement de cette fonction.
	___________________________________________________________________________
*/
int t_noeud_get_valeur(const t_noeud* noeud);

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
t_noeud* t_noeud_get_droit(const t_noeud* noeud);

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
t_noeud* t_noeud_get_gauche(const t_noeud* noeud);
