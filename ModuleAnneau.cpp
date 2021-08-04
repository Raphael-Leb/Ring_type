    /*___________________________________________________________________*/
   //                                                                    // 
  //                                                                    //
 //                                                                    //
/*____________________________________________________________________*/
/*          Nom du module : ModuleAnneau.cpp                         */
/*...................................................................*/
/*         Description du module:    Le module ModuleNoeud.cpp       */
/*         contient les définitions dans le sens de l'implémentation */
/*          des fonctions   qui font   partie de ce dernier.         */
/*                                                                   */
/*...................................................................*/
/*          Par    :        équipe 04                                */
/*...................................................................*/    //
/*          Date   : mardi le 13 juillet le 2021                     */   //
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

/*___________________________________________________________________________*/
/*						 Fichier(s) d'en-tête  	     	  	                 */
/*___________________________________________________________________________*/

#include "ModuleAnneau.h"


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
t_anneau* t_anneau_init() 
{
    //Allocation de memoire pour l'anneau.
    t_anneau* nouveau_anneau = (t_anneau*)calloc(1, sizeof(t_anneau));
    //Verification pour voir si l'allocation a bien fonctionné
    if (nouveau_anneau == nullptr)
    {
        printf("ModuleAnneau: t_anneau_init: Erreur d'allocation de memoire!");
        exit(EXIT_FAILURE);
    }
    //Initialiser les donnees de l'anneau
    nouveau_anneau->tete = nullptr; 
    nouveau_anneau->taille = 0;
    //Retourner le nouvel anneau
    return nouveau_anneau;
}

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
int t_anneau_get_taille(const t_anneau* anneau)
{
    //Verification que l'anneau recu est valide
    if (anneau == nullptr)
    {
        printf("ModuleAnneau: t_anneau_get_taille: Reference nulle recu!");
        exit(EXIT_FAILURE);
    }
    //renvoi de la taille
    return anneau->taille;
}

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
    Spécification : Aller au Mordor et le jeter dans la montagne de feu.
    ___________________________________________________________________________
*/
void t_anneau_detruire(t_anneau* anneau)
{
    //Verification que l'anneau recu est valide
    if (anneau == nullptr)
    {
        printf("ModuleAnneau: t_anneau_detruire: Reference nulle recu!");
        exit(EXIT_FAILURE);
    }
    //On initialise un pointeur de noeud pour pouvoir se deplacer dans l'anneau
    t_noeud* noeud_courant;
    //On suprime tout les noeuds a partir de la fin.
    for (int i = anneau->taille - 1; i > 0; --i)
    {
        noeud_courant = t_noeud_get_gauche(anneau->tete);
        t_noeud_detruire(noeud_courant);
    }
    //On supprime le dernier noeud de l'anneau
    t_noeud_detruire(anneau->tete);
    //On libere la memoire de l'anneau.
    free(anneau);
}

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
int t_anneau_get_valeur(const t_anneau* anneau, const int indice) 
{
    //Verification que l'anneau recu est valide
    if (anneau == nullptr)
    {
        printf("ModuleAnneau: t_anneau_get_valeur: Reference nulle recu!");
        exit(EXIT_FAILURE);
    }
    //Verification que l'indice recu est dans les bornes de l'anneau
    if (indice >= t_anneau_get_taille(anneau) || indice < 0) {

        printf("ModuleAnneau: t_anneau_get_valeur: indice recu non valide!");
        exit(EXIT_FAILURE);

    }
    //Etape 0
    //Creer un pointeur de noeud pour se deplacer dans l'anneau
    t_noeud* noeud_actuel = anneau->tete;
    //Etape 1
    //On choisit le chemin le plus rapide.
    int direction = 0;      // 0= Vers l'avant  1 = Vers l'arriere
    if (indice >= (t_anneau_get_taille(anneau) / 2))
    {
        direction = 1;
    }
    else
    {
        direction = 0;
    }
    //Etape 2
    //Calculer le nombre de pas a faire pour se rendre a la position donnee
    int nb_pas = 0;
    if (direction == 1)
    {
        nb_pas = t_anneau_get_taille(anneau) - indice;
    }
    else 
    {
        nb_pas = indice;
    }
    //Etape 3
    //On se deplace jusqu'a l'adresse du noeud a l'indice donnee
    for (int i = 0; i < nb_pas; ++i)
    {
        if (direction == 1)
        {
            noeud_actuel = t_noeud_get_gauche(noeud_actuel);
        }
        else
        {
            noeud_actuel = t_noeud_get_droit(noeud_actuel);
        }
    }
    return noeud_actuel->valeur;
}

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
int t_anneau_set_valeur(const t_anneau* anneau, const int indice, const int valeur)
{
    //Verification que l'anneau recu est valide
    if (anneau == nullptr)
    {
        printf("ModuleAnneau: t_anneau_set_valeur: Reference nulle recu!");
        exit(EXIT_FAILURE);
    }
    //Verification que l'indice recu est dans les bornes de l'anneau
    if (indice >= t_anneau_get_taille(anneau) || indice < 0) {

        printf("ModuleAnneau: t_anneau_set_valeur: indice recu non valide!");
        exit(EXIT_FAILURE);

    }
    //Etape 0
    //Creer un pointeur de noeud pour se deplacer dans l'anneau
    t_noeud* noeud_actuel = anneau->tete;

    int ancienne_valeur = 0;
    //Etape 1
    //On choisit le chemin le plus rapide.
    int direction = 0;          // 0= Vers l'avant  1 = Vers l'arriere
    if (indice >= (t_anneau_get_taille(anneau) / 2))
    {
        direction = 1;
    }
    else
    {
        direction = 0;
    }
    //Etape 2
    //Calculer le nombre de pas a faire pour se rendre a la position donnee
    int nb_pas = 0;
    if (direction == 1)
    {
        nb_pas = t_anneau_get_taille(anneau) - indice;
    }
    else
    {
        nb_pas = indice;
    }
    //Etape 3
    //On se deplace jusqu'a l'adresse du noeud a l'indice donnee
    for (int i = 0; i < nb_pas; ++i)
    {
        if (direction == 1)
        {
            noeud_actuel = t_noeud_get_gauche(noeud_actuel);
        }
        else
        {
            noeud_actuel = t_noeud_get_droit(noeud_actuel);
        }
    }
    //On note l'ancienne valeur et on met la nouvelle valeur dans le noeud a la position demandee
    ancienne_valeur = t_noeud_get_valeur(noeud_actuel);
    noeud_actuel->valeur = valeur;
    //On retourne l'ancienne valeur
    return ancienne_valeur;
}

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
int t_anneau_ajouter_fin(t_anneau* anneau, const int valeur)
{
    //Verification que l'anneau recu est valide
    if (anneau == nullptr)
    {
        printf("ModuleAnneau: t_anneau_ajouter_fin: Reference nulle recu!");
        exit(EXIT_FAILURE);
    }
    //On cree un nouveau noeud et on lui donne sa valeur
    t_noeud* nouveau_noeud = t_noeud_init();
    t_noeud_set_valeur(nouveau_noeud, valeur);
    //On cree un pointeur pour acceder au noeud de l'ancienne fin
    t_noeud* ancienne_fin;
    //Quand l'anneau est vide le nouveau noeud devient la tete de l'anneau
    if (t_anneau_get_taille(anneau) == 0)
    {
        anneau->tete = nouveau_noeud;
        t_noeud_set_droit(anneau->tete, nouveau_noeud);
        t_noeud_set_gauche(anneau->tete, nouveau_noeud);
        anneau->taille += 1;
    }
    //Lorsque l'anneau n'est pas vide, on ajoute le nouveau noeud a la fin.
    else
    {
        ancienne_fin = t_noeud_get_gauche(anneau->tete);
        //On donne au nouveau noeud l'ancienne fin et la tete de l'anneau comme voisin.
        t_noeud_set_droit(nouveau_noeud, anneau->tete);
        t_noeud_set_gauche(nouveau_noeud, ancienne_fin);
        //On donne a l'ancienne fin et a la tete de l'anneau le nouveau noeud comme voisin.
        t_noeud_set_droit(ancienne_fin, nouveau_noeud);
        t_noeud_set_gauche(anneau->tete, nouveau_noeud);
        anneau->taille += 1;
    }
    
    return t_anneau_get_valeur(anneau, t_anneau_get_taille(anneau) - 1);
}

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
int t_anneau_ajouter_debut(t_anneau* anneau, const int valeur)
{
    //Verification que l'anneau recu est valide
    if (anneau == nullptr)
    {
        printf("ModuleAnneau: t_anneau_ajouter_debut: Reference nulle recu!");
        exit(EXIT_FAILURE);
    }
    //On cree un nouveau noeud et on lui donne sa valeur
    t_noeud* nouveau_noeud = t_noeud_init();
    t_noeud_set_valeur(nouveau_noeud, valeur);
    //Si l'anneau contient aucun noeud ou un seul noeud, on utilise la fonction t_anneau_ajouter_fin().
    if (t_anneau_get_taille(anneau) <= 1)
    {
        t_anneau_ajouter_fin(anneau, valeur);
    }
    //Lorsque l'anneau contient plus de deux noeud, on ajoute le nouveau noeud apres la tete de l'anneau.
    else
    {
        t_noeud* ancien_debut = t_noeud_get_droit(anneau->tete);
        //On donne au nouveau noeud l'ancien debut et la tete de l'anneau comme voisin.
        t_noeud_set_droit(nouveau_noeud, ancien_debut);
        t_noeud_set_gauche(nouveau_noeud, anneau->tete);
        //On donne a l'ancien debut et a la tete de l'anneau le nouveau noeud comme voisin.
        t_noeud_set_droit(anneau->tete, nouveau_noeud);
        t_noeud_set_gauche(ancien_debut, nouveau_noeud);
        anneau->taille += 1;
    }
    //Si l'anneau contient un seul noeud, on renvoi la valeur du noeud a la position 0.
    if (t_anneau_get_taille(anneau) == 1)
    {
        return t_anneau_get_valeur(anneau, 0);
    }
    //Si l'anneau contient plus d'un noeud, on renvoi la valeur du noeud a la positon 1.
    else
    {
        return t_anneau_get_valeur(anneau, 1);
    }
}

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
int t_anneau_ajouter(t_anneau* anneau, const int position, const int valeur)
{
    //Verification que l'anneau recu est valide
    if (anneau == nullptr)
    {
        printf("ModuleAnneau: t_anneau_ajouter: Reference nulle recu!");
        exit(EXIT_FAILURE);
    }
    //Verification que l'indice recu est dans les bornes de l'anneau
    if (position > t_anneau_get_taille(anneau) || position < 0) {

        printf("ModuleAnneau: t_anneau_ajouter: position recu non valide!");
        exit(EXIT_FAILURE);
    }
    // On cree un nouveau noeud et on lui donne sa valeur
    t_noeud* nouveau_noeud = t_noeud_init();
    t_noeud_set_valeur(nouveau_noeud, valeur);
    //Si on veut ajouter le nouveau noeud a la position 1, on utilise la fonction t_anneau_ajouter_debut().
    if (position == 1)
    {
        t_anneau_ajouter_debut(anneau, valeur);
    }
    //Si on veut ajouter le nouveau noeud a la position 0 (tete de l'anneau), 
    //on utilise la fonction t_anneau_ajouter_fin() et on change la tete de place.
    else if (position == 0)
    {
        t_anneau_ajouter_fin(anneau, valeur);
        anneau->tete = t_noeud_get_gauche(anneau->tete);
    }
    //Si on veut ajouter le nouveau noeud a la fin de l'anneau, on utilise la fonction t_anneau_ajouter_fin().
    else if (position == t_anneau_get_taille(anneau))
    {
        t_anneau_ajouter_fin(anneau, valeur);
    }
    //Si on veut ajouter le nouveau noeud dans l'anneau.
    else
    {
        //Etape 0
        //Creer un pointeur de noeud pour se deplacer dans l'anneau
        t_noeud* noeud_courant = anneau->tete;
        t_noeud* noeud_avant_courant;
        //Etape 1
        //On choisit le chemin le plus rapide.
        int direction = 0;      // 0= Vers l'avant  1 = Vers l'arriere
        if (position >= (t_anneau_get_taille(anneau) / 2))
        {
            direction = 1;
        }
        else
        {
            direction = 0;
        }
        //Etape 2
        //Calculer le nombre de pas a faire pour se rendre a la position donnee
        int nb_pas = 0;
        if (direction == 1)
        {
            nb_pas = t_anneau_get_taille(anneau) - position;
        }
        else
        {
            nb_pas = position;
        }
        //Etape 3
        //On se deplace jusqu'a l'adresse du noeud a l'indice donnee
        for (int i = 0; i < nb_pas; ++i)
        {
            if (direction == 1)
            {
                noeud_courant = t_noeud_get_gauche(noeud_courant);
            }
            else
            {
                noeud_courant = t_noeud_get_droit(noeud_courant);
            }
        }
        noeud_avant_courant = t_noeud_get_gauche(noeud_courant);

        //Ajouter le nouveau noeud dans l'anneau.
        //Ordre: noeud_avant_courant -> nouveau_noeud -> noeud_courant
        //On donne le noeud_avant_courant et le noeud_courant comme voisin au nouveau_noeud.
        t_noeud_set_gauche(nouveau_noeud, noeud_avant_courant);
        t_noeud_set_droit(nouveau_noeud, noeud_courant);
        //On donne le nouveau_noeud comme voisin au noeud_avant_courant et au noeud_courant.
        t_noeud_set_droit(noeud_avant_courant, nouveau_noeud);
        t_noeud_set_gauche(noeud_courant, nouveau_noeud);
        anneau->taille += 1;
    }
    //On renvoi la valeur du noeud ajoutee.
    return t_anneau_get_valeur(anneau, position);
}

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
int t_anneau_retirer(t_anneau* anneau, const int position)
{
    //Verification que l'anneau recu est valide
    if (anneau == nullptr)
    {
        printf("ModuleAnneau: t_anneau_retirer: Reference nulle recu!");
        exit(EXIT_FAILURE);
    }
    //Verification que la position recu est dans les bornes de l'anneau
    if (position >= t_anneau_get_taille(anneau) || position < 0) {

        printf("ModuleAnneau: t_anneau_retirer: position recu non valide!");
        exit(EXIT_FAILURE);
    }
    //Verification que l'anneau n'est pas deja vide.
    if (t_anneau_get_taille(anneau) == 0)
    {
        printf("ModuleAnneau: t_anneau_retirer: L'anneau en reference est vide!");
        exit(EXIT_FAILURE);
    }
    
    int direction = 0;      // 0= Vers l'avant  1 = Vers l'arriere
    int nb_pas = 0;
    int valeur;
    //Creer un pointeur de noeud pour se deplacer dans l'anneau
    t_noeud* noeud_courant = anneau->tete;
    //Creer des pointeur de noeud pour acceder au noeud qui devront etre modifiee pour fermer l'anneau.
    t_noeud* voisin_gauche;
    t_noeud* voisin_droit;
    //Si le noeud a retirer est a la position 0, on utilise la fonction t_anneau_retirer_debut().
    if (position == 0)
    {
        valeur = t_anneau_retirer_debut(anneau);
    }
    //Si le noeud a retirer est a la derniere position, on utilise la fonction t_anneau_retirer_fin().
    else if (position == t_anneau_get_taille(anneau) - 1)
    {
        valeur = t_anneau_retirer_fin(anneau);
    }
    //Lorsque l'on veut retirer un noeud dans l'anneau.
    else
    {
        //Etape 1
        //On choisit le chemin le plus rapide.
        if (position >= (t_anneau_get_taille(anneau) / 2))
        {
            direction = 1;
        }
        else
        {
            direction = 0;
        }
        //Etape 2
        //Calculer le nombre de pas a faire pour se rendre a la position donnee
        if (direction == 1)
        {
            nb_pas = t_anneau_get_taille(anneau) - position;
        }
        else
        {
            nb_pas = position;
        }
        //Etape 3
        //On se deplace jusqu'a l'adresse du noeud a l'indice donnee
        for (int i = 0; i < nb_pas; ++i)
        {
            if (direction == 1)
            {
                noeud_courant = t_noeud_get_gauche(noeud_courant);
            }
            else
            {
                noeud_courant = t_noeud_get_droit(noeud_courant);
            }
        }
        //On sauvegarde la valeur du noeud qui sera detruit.
        valeur = t_noeud_get_valeur(noeud_courant);
        //On sauvegarde les adresses des voisins du noeud qui sera detruit.
        voisin_gauche = t_noeud_get_gauche(noeud_courant);
        voisin_droit = t_noeud_get_droit(noeud_courant);
        //On change les voisins des noeuds qui restent dans l'anneau pour exclure le noeud qui sera detruit de l'anneau.
        t_noeud_set_gauche(voisin_droit, voisin_gauche);
        t_noeud_set_droit(voisin_gauche, voisin_droit);
        //On detruit le noeud a retirer.
        t_noeud_detruire(noeud_courant);
        //On reduit la taille de l'anneau.
        anneau->taille -= 1;
    }
    //On renvoi la valeur du noeud qui a ete retire.
    return valeur;
}

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
int t_anneau_retirer_fin(t_anneau* anneau)
{
    //Verification que l'anneau recu est valide
    if (anneau == nullptr)
    {
        printf("ModuleAnneau: t_anneau_retirer_fin: Reference nulle recu!");
        exit(EXIT_FAILURE);
    }
    //Verification que l'anneau n'est pas deja vide.
    if (t_anneau_get_taille(anneau) == 0)
    {
        printf("ModuleAnneau: t_anneau_retirer_fin: L'anneau en reference est vide!");
        exit(EXIT_FAILURE);
    }
    int valeur;
    //Creer un pointeur de noeud pour se deplacer dans l'anneau
    t_noeud* noeud_courant = anneau->tete;
    //Creer des pointeur de noeud pour acceder au noeud qui devront etre modifiee pour fermer l'anneau.
    t_noeud* voisin_gauche;
    t_noeud* voisin_droit;
    //Si l'anneau contient un seul noeud, on utilise la fonction t_anneau_retirer_debut().
    if (t_anneau_get_taille(anneau) == 1)
    {
        valeur = t_anneau_retirer_debut(anneau);
    }
    //Lorsque l'on veut retirer un noeud a la derniere position de l'anneau.
    else
    {
        //Le noeud a retirer est le noeud a gauche de la tete de l'anneau.
        noeud_courant = t_noeud_get_gauche(anneau->tete);
        //On sauvegarde la valeur du noeud qui sera detruit.
        valeur = t_noeud_get_valeur(noeud_courant);
        //On sauvegarde les adresses des voisins du noeud qui sera detruit.
        voisin_gauche = t_noeud_get_gauche(noeud_courant);
        voisin_droit = t_noeud_get_droit(noeud_courant);
        //On change les voisins des noeuds qui restent dans l'anneau pour exclure le noeud qui sera detruit de l'anneau.
        t_noeud_set_gauche(voisin_droit, voisin_gauche);
        t_noeud_set_droit(voisin_gauche, voisin_droit);
        //On detruit le noeud a retirer.
        t_noeud_detruire(noeud_courant);
        //On reduit la taille de l'anneau.
        anneau->taille -= 1;
    }
    //On renvoi la valeur du noeud qui a ete retire.
    return valeur;
}

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
int t_anneau_retirer_debut(t_anneau* anneau)
{
    //Verification que l'anneau recu est valide
    if (anneau == nullptr)
    {
        printf("ModuleAnneau: t_anneau_retirer_debut: Reference nulle recu!");
        exit(EXIT_FAILURE);
    }
    //Verification que l'anneau n'est pas deja vide.
    if (t_anneau_get_taille(anneau) == 0)
    {
        printf("ModuleAnneau: t_anneau_retirer_debut: L'anneau en reference est vide!");
        exit(EXIT_FAILURE);
    }
    //On sauvegarde la valeur du noeud qui sera detruit.
    int valeur = t_noeud_get_valeur(anneau->tete);
    //Creer un pointeur de noeud pour se deplacer dans l'anneau
    t_noeud* noeud_courant = anneau->tete;
    //Creer des pointeur de noeud pour acceder au noeud qui devront etre modifiee pour fermer l'anneau.
    t_noeud* voisin_gauche;
    t_noeud* voisin_droit;
    //Si l'anneau contient un seul noeud.
    if (t_anneau_get_taille(anneau) == 1)
    {
        //On detruit la tete de l'anneau.
        t_noeud_detruire(anneau->tete);
        //On reduit la taille de l'anneau.
        anneau->taille -= 1;
        //On s'assure que la tete de l'anneau contient un pointeur nul.
        anneau->tete = nullptr;
    }
    //Si l'anneau contient plus d'un noeud.
    else
    {
        //On sauvegarde les adresses des voisins du noeud qui sera detruit.
        voisin_gauche = t_noeud_get_gauche(noeud_courant);
        voisin_droit = t_noeud_get_droit(noeud_courant);
        //On change les voisins des noeuds qui restent dans l'anneau pour exclure le noeud qui sera detruit de l'anneau.
        t_noeud_set_gauche(voisin_droit, voisin_gauche);
        t_noeud_set_droit(voisin_gauche, voisin_droit);
        //On change la tete de l'anneau, ce qui a l'effet de decaler tout les noeuds d'une position.
        anneau->tete = voisin_droit;
        //On detruit le noeud a retirer.
        t_noeud_detruire(noeud_courant);
        //On reduit la taille de l'anneau.
        anneau->taille -= 1;
    }
    //On renvoi la valeur du noeud qui a ete retire.
    return valeur;
}

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
void t_anneau_afficher(t_anneau* anneau)
{
    //Verification que l'anneau recu est valide
    if (anneau == nullptr)
    {
        printf("ModuleAnneau: t_anneau_afficher: Reference nulle recu!");
        exit(EXIT_FAILURE);
    }
    //Verification que l'anneau n'est pas vide.
    if (t_anneau_get_taille(anneau) == 0)
    {
        printf("ModuleAnneau: t_anneau_afficher: L'anneau en reference est vide!");
        exit(EXIT_FAILURE);
    }
    //Creer un pointeur de noeud pour se deplacer dans l'anneau
    t_noeud* noeud_courant = anneau->tete;
    //Si l'anneau contient un seul noeud, on utilise le format [ %i ].
    if (t_anneau_get_taille(anneau) == 1)
    {
        printf("[ %i ]\n", t_noeud_get_valeur(anneau->tete));
    }
    //Quand l'anneau contient plus d'un noeud, on utilise le format [ %i , %i , ... ].
    else
    {
        //On imprime le crochet ouvrant avec la valeur de la tete.
        printf("[ %i ,", t_noeud_get_valeur(noeud_courant));
        noeud_courant = t_noeud_get_droit(noeud_courant);
        //Tant que l'on n'est pas a la derniere position, on imprime la valeur de tout les noeuds et on avance dans l'anneau.
        while(noeud_courant != t_noeud_get_gauche(anneau->tete))
        {
            printf(" %i ,", t_noeud_get_valeur(noeud_courant));
            noeud_courant = t_noeud_get_droit(noeud_courant);
        }
        //On choisi le dernier noeud de l'anneau et on imprime sa valeur.
        noeud_courant = t_noeud_get_gauche(anneau->tete);
        printf(" %i ]\n", t_noeud_get_valeur(noeud_courant));
    }
}
