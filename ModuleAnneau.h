#pragma once
     /*___________________________________________________________________*/
   //                                                                    // 
  //                                                                    //
 //                                                                    //
/*____________________________________________________________________*/
/*          Nom du module : ModuleAnneau.h                         */
/*...................................................................*/
/*          Par    :        équipe 04                                */
/*...................................................................*/    //
/*          Date   : mardi le 15 juin le 2021                        */   //
/*...................................................................*/  //
/*    Dernière modification : samedi 31 juillet  2021 03:11 P.M      */ //
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
#include "ModuleNoeud.h"


/*  ___________________________________________________________________________
    Nom	:			anneau
    ___________________________________________________________________________
    Description :	Enregistrement, structure de données qui regroupe diverses
    informations (variables), de types variés, qui constituent les champs de
    l'enregistrements:

    t_noeud* tete;			// L'element zero de l'anneau.

    int		taille;			// La taille de l'anneau.
    ___________________________________________________________________________
*/
typedef struct anneau
{
	t_noeud* tete;			// L'element zero de l'anneau.
	int		taille;			// La taille de l'anneau.
}t_anneau;

/*  ___________________________________________________________________________
    Nom	:			t_noeud_init
    ___________________________________________________________________________
    Description :	Constructeur du type anneau. Constructeur: alloue
                    dynamiquement
    ___________________________________________________________________________
    Paramètres :	Aucuns.
    ___________________________________________________________________________
    Retour :	   Un pointeur vers un anneau
    ___________________________________________________________________________
    Requis 1 :     Vous devez initialiser la mémoire avec des zéros.
    ___________________________________________________________________________
    Requis 2 :     Vous devez vous assurer que l’allocation de mémoire est
                   réussie.
    ___________________________________________________________________________
    Requis 3 :    La tête de l’anneau doit être initialisée avec une référence
                  nulle.
    ___________________________________________________________________________
    Requis 4 :     Vous devez initialiser les enfants du noeud par des
                  références vides
    ___________________________________________________________________________
    Test associé :  Aucun
    ___________________________________________________________________________
    Spécification : N/A
    ___________________________________________________________________________
*/
t_anneau* t_anneau_init();

/*  ___________________________________________________________________________
    Nom	:			t_anneau_detruire
    ___________________________________________________________________________
    Description :	Cette fonction libère la mémoire allouée à un anneau.
                    On detruit en reculons
    ___________________________________________________________________________
    Paramètres :	Aucuns.
    ___________________________________________________________________________
    Retour :	   Un pointeur vers un anneau
    ___________________________________________________________________________
    Requis 1 :     Si la fonction reçoit une référence nulle comme anneau,
                   afficher un message d’erreur et quitter avec le code
                   EXIT_FAILURE.
    ___________________________________________________________________________
    Requis 2 :     Vous devez d’abord libérer la mémoire de chacun des noeuds
                   de l’anneau.
    ___________________________________________________________________________
    Requis 3 :    Vous devez ensuite libérer la mémoire de l’anneau.
    ___________________________________________________________________________
    Test associé :  Aucun
    ___________________________________________________________________________
    Spécification : N/A
    ___________________________________________________________________________
*/
void t_anneau_detruire(t_anneau* anneau);


/*  ___________________________________________________________________________
    Nom	:			 t_anneau_get_taille
    ___________________________________________________________________________
    Description :	 Cette fonction est un accesseur qui retourne la taille
                     d’un anneau. Accesseur qui retourne la taille d'un anneau
    ___________________________________________________________________________
    Paramètres :	 Un pointeur vers un anneau.
    ___________________________________________________________________________
    Retour :	    Un entier qui correspond à la taille de l’anneau.
    ___________________________________________________________________________
    Requis 1 :       Si la fonction reçoit une référence nulle comme anneau,
                     afficher un message d’erreur et quitter avec le code
                     EXIT_FAILURE.
    ___________________________________________________________________________
    Test associé :  Vous devez rédiger un test nommé t_anneau_get_taille_test
                    qui démontre le fonctionnement de cette fonction.
    ___________________________________________________________________________
    Spécification : N/A
    ___________________________________________________________________________
*/
int t_anneau_get_taille(const t_anneau* anneau);

/*  ___________________________________________________________________________
    Nom	:			t_anneau_get_valeur
    ___________________________________________________________________________
    Description :	Cette fonction retourne la valeur d’un élément situé à un
                    indice donné
    ___________________________________________________________________________
    Paramètres :	Un pointeur vers un anneau.
                   Un entier qui correspond à l’indice de l’élément.
    ___________________________________________________________________________
    Retour :	   Un indice qui correspond à la valeur de l’élément.
    ___________________________________________________________________________
    Requis 1 :     Si la fonction reçoit une référence nulle comme anneau,
                   afficher un   message d’erreur et quitter avec le code
                   EXIT_FAILURE.
    ___________________________________________________________________________
    Requis 2 :    Si l’indice reçu n’est pas valide, afficher un message
                  d’erreur et quitter avec le code EXIT_FAILURE.
    ___________________________________________________________________________
    Requis 3 :   Connaissant l’indice de l’élément désiré, vous devez utiliser
                 le chemin le plus court pour parcourir l’anneau.
    ___________________________________________________________________________
    Test associé :  Vous devez rédiger un test nommé t_anneau_get_valeur_test
                    qui démontre le fonctionnement de cette fonction.
    ___________________________________________________________________________
    Spécification : N/A
    ___________________________________________________________________________
*/
int t_anneau_get_valeur(const t_anneau* anneau, const int indice);


/*  ___________________________________________________________________________
    Nom	:			t_anneau_set_valeur
    ___________________________________________________________________________
    Description :	Cette fonction modifie la valeur d’un élément dont l’indice
                    est donné.
    ___________________________________________________________________________
    Paramètres :	Un pointeur vers un anneau.
                    Un entier qui correspond à l’indice de l’élément à modifier.
                    Un entier qui correspond à la nouvelle valeur.

    ___________________________________________________________________________
    Retour :	   Un entier qui correspond à l’ancienne valeur qui fut écrasée
                   par la nouvelle.
    ___________________________________________________________________________
    Requis 1 :    Si la fonction reçoit une référence nulle comme anneau,
                  afficher un message d’erreur et quitter avec le code
                  EXIT_FAILURE.

    ___________________________________________________________________________
    Requis 2 :    Si l’indice reçu n’est pas valide, afficher un message d’erreur
                  et quitter avec le code EXIT_FAILURE.

    ___________________________________________________________________________
    Requis 3 :  Connaissant l’indice de l’élément à modifier, vous devez utiliser
                le chemin le plus court pour parcourir l’anneau.
    ___________________________________________________________________________
    Test associé :  Vous devez rédiger un test nommé t_anneau_set_valeur_test
                    qui démontre le fonctionnement de cette fonction.
    ___________________________________________________________________________
    Spécification : N/A
    ___________________________________________________________________________
*/
int t_anneau_set_valeur(const t_anneau* anneau, const int indice, const int valeur);


/*  ___________________________________________________________________________
    Nom	:			t_anneau_ajouter_fin
    ___________________________________________________________________________
    Description :	Cette fonction ajoute un élément à la fin de l’anneau
                    (i.e. à gauche de la tête).

    ___________________________________________________________________________
    Paramètres :	Un pointeur vers un anneau.
                    Un entier qui représenta la valeur du nouveau noeud.

    ___________________________________________________________________________
    Retour :	   La valeur du nouveau noeud.
    ___________________________________________________________________________
    Requis 1 :    Si la fonction reçoit une référence nulle comme anneau,
                  afficher un message d’erreur et quitter avec le code
                  EXIT_FAILURE.

    ___________________________________________________________________________
    Requis 2 :     Si l’anneau est vide, (1) la tête de l’anneau, (2) l’enfant
                   gauche de la tête et (3) l’enfant droit de la tête sont tous
                   égaux au nouveau noeud. Il s’agit d’un noeud qui pointe vers
                   lui-même.
    ___________________________________________________________________________
    Requis 3 :  Sinon, (1) l’ancien dernier noeud devient l’enfant gauche du
                nouveau noeud, (2) L’enfant droit de l’ancien dernier noeud est
                remplacé par le nouveau noeud, (3) l’enfant droit du nouveau
                noeud est remplacé par la tête de l’anneau et (4) l’enfant gauche
                de la tête est remplacé le nouveau noeud. Voici une
                représentation schématique de ce requis :
    ___________________________________________________________________________
    Test associé :  Vous devez rédiger un test nommé t_anneau_ajouter_fin_test
                    qui démontre le fonctionnement de cette fonction.
    ___________________________________________________________________________
    Spécification : N/A
    ___________________________________________________________________________
*/
int t_anneau_ajouter_fin(t_anneau* anneau, const int valeur);


/*  ___________________________________________________________________________
    Nom	:			t_anneau_ajouter_debut
    ___________________________________________________________________________
    Description :	Cette fonction ajoute un élément au début de l’anneau
                    (i.e. à droite de la tête).

    ___________________________________________________________________________
    Paramètres :	Un pointeur vers un anneau.
                    Un entier qui représente la valeur du nouveau noeud.
    ___________________________________________________________________________
    Retour :	  Un entier qui correspond à la valeur du nouveau noeud.
    ___________________________________________________________________________
    Requis 1 :   Si la fonction reçoit une référence nulle comme anneau,
                 afficher un message d’erreur et quitter avec le code
                 EXIT_FAILURE.

    ___________________________________________________________________________
    Requis 2 :     Si l’anneau est vide, (1) la tête de l’anneau, (2) l’enfant
                   gauche de la tête et (3) l’enfant droit de la tête sont tous
                   égaux au nouveau noeud. Il s’agit d’un noeud qui pointe vers
                   lui-même.
    ___________________________________________________________________________
    Test associé :  Vous devez rédiger un test nommé t_anneau_ajouter_debut_test
                    qui démontre le fonctionnement de cette fonction.

    ___________________________________________________________________________
    Spécification : N/A
    ___________________________________________________________________________
*/
int t_anneau_ajouter_debut(t_anneau* anneau, const int valeur);


/*  ___________________________________________________________________________
    Nom	:			t_anneau_ajouter
    ___________________________________________________________________________
    Description :	Cette fonction ajoute un élément à la position donnée.
    ___________________________________________________________________________
    Paramètres :	Un pointeur vers un anneau.
                    Un entier qui correspond à la position du nouveau noeud.
                    Un entier qui correspond à la valeur du nouveau noeud.
    ___________________________________________________________________________
    Retour :	  Un entier qui correspond à la nouvelle valeur.
    ___________________________________________________________________________
    Requis 1 :     Si la fonction reçoit une référence nulle comme anneau,
                   afficher un message d’erreur et quitter avec le code
                   EXIT_FAILURE.
    ___________________________________________________________________________
    Requis 2 :      Si la position reçu n’est pas valide, afficher un message
                    d’erreur et quitter avec le code EXIT_FAILURE.
    ___________________________________________________________________________
    Requis 3 :     Vous devez faire un usage judicieux de t_anneau_ajouter_debut
                   et t_anneau_ajouter_fin lorsque la position appartient à [0,1]

    ___________________________________________________________________________
    Requis 4 :     Pour une position qui n’appartient pas à [0,1, vous devez
                   utiliser le chemin le plus court pour parcourir l’anneau
                   jusqu’à cet endroit qu’on nommera le noeud courant. Ensuite,
                   (1) l’enfant gauche du nouveau noeud sera l’enfant gauche du
                   noeud courant, (2) l’enfant droit de l’enfant gauche du noeud
                   courant sera le nouveau noeud, (3) l’enfant droit du nouveau
                   noeud sera le noeud courant et (4) l’enfant gauche du noeud
                   courant sera le nouveau noeud. Vous pouvez aider de la figure
                   donnée pour le Requis 3 du sour-programme 13 pour mieux
                   visualiser l’opération.
    ___________________________________________________________________________
    Test associé :  Vous devez rédiger un test nommé t_anneau_ajouter_test
                    qui démontre le fonctionnement de cette fonction.
    ___________________________________________________________________________
    Spécification : N/A
    ___________________________________________________________________________
*/
int t_anneau_ajouter(t_anneau* anneau, const int position, const int valeur);


/*  ___________________________________________________________________________
    Nom	:			t_anneau_retirer
    ___________________________________________________________________________
    Description :	Cette fonction rétire un élément à une position donnée.
    ___________________________________________________________________________
    Paramètres :	Un pointeur vers un anneau.
                    Un entier qui correspond à la position de l’élément à retirer.
    ___________________________________________________________________________
    Retour :	    Un entier qui correspond à la valeur de l’élément retiré.
    ___________________________________________________________________________
    Requis 1 :     Si la fonction reçoit une référence nulle comme anneau,
                   afficher un message d’erreur et quitter avec le code
                   EXIT_FAILURE.
    ___________________________________________________________________________
    Requis 2 :   Si la position reçu n’est pas valide, afficher un message
                 d’erreur et quitter avec le code EXIT_FAILURE.
    ___________________________________________________________________________
    Requis 3 :   Si l’anneau est vide, afficher un message d’erreur et
                 quitter avec le code EXIT_FAILURE.
    ___________________________________________________________________________
    Requis 4 :   Connaissant l’indice de l’élément à modifier, vous devez
                 utiliser le chemin le plus court pour parcourir l’anneau

    ___________________________________________________________________________
    Requis 5 :  Votre fonction doit être capable de supprimer la tête de
                l’anneau.
    ___________________________________________________________________________
    Requis 6 :   Vous devez libérer la mémoire du noeud supprimé.
    ___________________________________________________________________________
    Requis 7 :    Votre fonction doit remplacer la tête de l’anneau par une
                  référence vide si l’anneau est vidé après à la supression

    ___________________________________________________________________________
    Test associé : Vous devez rédiger un test nommé t_anneau_retirer_test qui
                   démontre le fonctionnement de cette fonction.
    ___________________________________________________________________________
    Spécification : N/A
    ___________________________________________________________________________
*/
int t_anneau_retirer(t_anneau* anneau, const int position);


/*  ___________________________________________________________________________
    Nom	:			t_anneau_retirer_fin
    ___________________________________________________________________________
    Description :	Cette fonction retire l’élément à gauche de la tête
    ___________________________________________________________________________
    Paramètres :	Un pointeur vers un anneau.
    ___________________________________________________________________________
    Retour :	    Un entier qui correspond à la valeur de l’élément retiré
    ___________________________________________________________________________
    Requis 1 :     Si la fonction reçoit une référence nulle comme anneau,
                   afficher un message d’erreur et quitter avec le code
                   EXIT_FAILURE.
    ___________________________________________________________________________
    Requis 2 :   Si l’anneau est vide, afficher un message d’erreur et quitter
                 avec le code EXIT_FAILURE.
    ___________________________________________________________________________
    Requis 3 :   Vous devez libérer la mémoire du noeud supprimé.
    ___________________________________________________________________________
    Requis 4 :  Votre fonction doit remplacer la tête de l’anneau par une
                référence vide si l’anneau est vidé après à la supression.
    ___________________________________________________________________________
    Test associé : Vous devez rédiger un test nommé t_anneau_retirer_fin_test
                   qui démontre le fonctionnement de cette fonction.

    ___________________________________________________________________________
    Spécification : N/A
    ___________________________________________________________________________
*/
int t_anneau_retirer_fin(t_anneau* anneau);


/*  ___________________________________________________________________________
    Nom	:			t_anneau_retirer_debut
    ___________________________________________________________________________
    Description :	Cette fonction reture la tête de l’anneau
    ___________________________________________________________________________
    Paramètres :	Un pointeur vers un anneau
    ___________________________________________________________________________
    Retour :	    Un entier qui correspond à la valeur retirée.
    ___________________________________________________________________________
    Requis 1 :     Si la fonction reçoit une référence nulle comme anneau,
                   afficher un message d’erreur et quitter avec le code
                   EXIT_FAILURE.
    ___________________________________________________________________________
    Requis 2 :   Si l’anneau est vide, afficher un message d’erreur et quitter
                 avec le code EXIT_FAILURE.

    ___________________________________________________________________________
    Requis 3 :  Votre fonction doit faire un usage judicieux de t_anneau_retirer_fin
    ___________________________________________________________________________
    Requis 4 :  Votre fonction doit remplacer la tête de l’anneau par une
                référence vide si l’anneau est vidé après à la supression.
    ___________________________________________________________________________
    Test associé : Vous devez rédiger un test nommé t_anneau_debut_test qui
                   démontre le fonctionnement de cette fonction.

    ___________________________________________________________________________
    Spécification : N/A
    ___________________________________________________________________________
*/
int t_anneau_retirer_debut(t_anneau* anneau);


/*  ___________________________________________________________________________
    Nom	:			t_anneau_afficher
    ___________________________________________________________________________
    Description :	Cette procédure affiche l’anneau à la ligne de commande
    ___________________________________________________________________________
    Paramètres :	Un pointeur vers un anneau
    ___________________________________________________________________________
    Retour :	    Aucun.
    ___________________________________________________________________________
    Requis 1 :     Si la procedure reçoit une référence nulle comme anneau,
                   afficher un message d’erreur et quitter avec le code
                   EXIT_FAILURE.
    ___________________________________________________________________________
    Requis 2 :   Si l’anneau est vide, afficher un message d’erreur et quitter
                 avec le code EXIT_FAILURE.
    ___________________________________________________________________________
    Requis 3 :   Votre procédure doit faire un affichage selon le format
                 [𝑎, 𝑏, . . .]. S’il n’y a qu’un
                  seul élément, la procédure fait un affichage selon le format [𝑎].
                  Voici un exemple :

                  [ 5 , 4 , 3 , 2 , 1 ]
                  Press any key to continue . . .


    ___________________________________________________________________________
    Test associé : Aucun.

    ___________________________________________________________________________
    Spécification : N/A
    ___________________________________________________________________________
*/
void t_anneau_afficher(t_anneau* anneau);