#include "ModuleTests.h"


/*  ___________________________________________________________________________
	Nom	:			t_noeud_set_valeur_test
	___________________________________________________________________________
	Description :	test de la fonction t_noeud_set_valeur
	___________________________________________________________________________
	Paramètres : aucun
	___________________________________________________________________________
	Retour : aucun
	___________________________________________________________________________
	Requis 1 : Demontrer que la fonction t_noeud_set_valeur fonctionne
	___________________________________________________________________________
*/
void t_noeud_set_valeur_test(void) {
	t_noeud* noeud_test = t_noeud_init();
	t_noeud_set_valeur(noeud_test, 5);
	if (noeud_test->valeur == 5) {
		printf("\nTest t_noeud_set_valeur: SUCCES");
	}
	else {
		printf("\nTest t_noeud_set_valeur: ECHEC");
	}
	printf("\nValeur attendu: 5\nValeur recu:    %d\n", noeud_test->valeur);
}

/*  ___________________________________________________________________________
	Nom	:			t_noeud_get_valeur_test
	___________________________________________________________________________
	Description :	test de la fonction t_noeud_get_valeur
	___________________________________________________________________________
	Paramètres : aucun
	___________________________________________________________________________
	Retour : aucun
	___________________________________________________________________________
	Requis 1 : Demontrer que la fonction t_noeud_get_valeur fonctionne
	___________________________________________________________________________
*/
void t_noeud_get_valeur_test(void) {
	t_noeud* noeud_test = t_noeud_init();
	noeud_test->valeur = 5;
	if (t_noeud_get_valeur(noeud_test) == 5) {
		printf("\nTest t_noeud_get_valeur: SUCCES");
	}
	else {
		printf("\nTest t_noeud_get_valeur: ECHEC");
	}
	printf("\nValeur attendu: 5\nValeur recu:    %d\n", t_noeud_get_valeur(noeud_test));
}

/*  ___________________________________________________________________________
	Nom	:			t_noeud_get_droit_test
	___________________________________________________________________________
	Description :	test de la fonction t_noeud_get_droit
	___________________________________________________________________________
	Paramètres : aucun
	___________________________________________________________________________
	Retour : aucun
	___________________________________________________________________________
	Requis 1 : Demontrer que la fonction t_noeud_get_droit fonctionne
	___________________________________________________________________________
*/
void t_noeud_get_droit_test(void) {
	t_noeud* noeud_1 = t_noeud_init();
	t_noeud* noeud_2 = t_noeud_init();
	noeud_1->droit = noeud_2;
	if (t_noeud_get_droit(noeud_1) == noeud_2) {
		printf("\nTest t_noeud_get_droit: SUCCES ");
	}
	else {
		printf("\nTest t_noeud_get_droit: ECHEC");
	}
}

/*  ___________________________________________________________________________
	Nom	:			t_noeud_get_gauche_test
	___________________________________________________________________________
	Description :	test de la fonction t_noeud_get_gauche
	___________________________________________________________________________
	Paramètres : aucun
	___________________________________________________________________________
	Retour : aucun
	___________________________________________________________________________
	Requis 1 : Demontrer que la fonction t_noeud_get_gauche fonctionne
	___________________________________________________________________________
*/
void t_noeud_get_gauche_test(void) {
	t_noeud* noeud_1 = t_noeud_init();
	t_noeud* noeud_2 = t_noeud_init();
	noeud_1->gauche = noeud_2;
	if (t_noeud_get_gauche(noeud_1) == noeud_2) {
		printf("\nTest t_noeud_get_gauche: SUCCES ");
	}
	else {
		printf("\nTest t_noeud_get_gauche: ECHEC");
	}
}

/*  ___________________________________________________________________________
	Nom	:			t_anneau_get_taille_test
	___________________________________________________________________________
	Description :	test de la fonction t_anneau_get_taille
	___________________________________________________________________________
	Paramètres : aucun
	___________________________________________________________________________
	Retour : aucun
	___________________________________________________________________________
	Requis 1 : Demontrer que la fonction t_anneau_get_taille fonctionne
	___________________________________________________________________________
*/
void t_anneau_get_taille_test(void) {
	t_anneau* anneau1 = t_anneau_init();
	anneau1->taille = 2;
	if (t_anneau_get_taille(anneau1) == 2) {
		printf("\n\nTest t_anneau_get_taille: SUCCES");
	}
	else {
		printf("\n\nTest t_anneau_get_taille: ECHEC");
	}
	printf("\nValeur attendu: 2\nValeur recu:    %d\n", t_anneau_get_taille(anneau1));
}

/*  ___________________________________________________________________________
	Nom	:			t_anneau_get_valeur_test
	___________________________________________________________________________
	Description :	test de la fonction t_anneau_get_valeur
	___________________________________________________________________________
	Paramètres : aucun
	___________________________________________________________________________
	Retour : aucun
	___________________________________________________________________________
	Requis 1 : Demontrer que la fonction t_anneau_get_valeur fonctionne
	___________________________________________________________________________
*/
void t_anneau_get_valeur_test(void) {
	t_anneau* anneau1 = t_anneau_init();
	t_anneau_ajouter_fin(anneau1,5);
	if (t_anneau_get_valeur(anneau1,0) == 5) {
		printf("\n\nTest t_anneau_get_valeur: SUCCES");
	}
	else {
		printf("\n\nTest t_anneau_get_valeur: ECHEC");
	}
	printf("\nValeur attendu: 5\nValeur recu:    %d\n", t_anneau_get_valeur(anneau1, 0));
}

/*  ___________________________________________________________________________
	Nom	:			t_anneau_set_valeur_test
	___________________________________________________________________________
	Description :	test de la fonction t_anneau_set_valeur
	___________________________________________________________________________
	Paramètres : aucun
	___________________________________________________________________________
	Retour : aucun
	___________________________________________________________________________
	Requis 1 : Demontrer que la fonction t_anneau_set_valeur fonctionne
	___________________________________________________________________________
*/
void t_anneau_set_valeur_test(void) {
	t_anneau* anneau1 = t_anneau_init();
	t_anneau_ajouter_fin(anneau1, 2);
	t_anneau_set_valeur(anneau1, 0, 5);
	if (t_anneau_get_valeur(anneau1, 0) == 5) {
		printf("\n\nTest t_anneau_set_valeur: SUCCES");
	}
	else {
		printf("\n\nTest t_anneau_set_valeur: ECHEC");
	}
	printf("\nValeur attendu: 5\nValeur recu:    %d\n", t_anneau_get_valeur(anneau1, 0));
}

/*  ___________________________________________________________________________
	Nom	:			t_anneau_ajouter_fin_test
	___________________________________________________________________________
	Description :	test de la fonction t_anneau_ajouter_fin
	___________________________________________________________________________
	Paramètres : aucun
	___________________________________________________________________________
	Retour : aucun
	___________________________________________________________________________
	Requis 1 : Demontrer que la fonction t_anneau_ajouter_fin fonctionne
	___________________________________________________________________________
*/
void t_anneau_ajouter_fin_test(void) {
	t_anneau* anneau1 = t_anneau_init();
	t_anneau_ajouter_fin(anneau1, 2);
	if (t_anneau_get_valeur(anneau1, 0) == 2) {
		printf("\n\nTest t_anneau_ajouter_fin: SUCCES");
	}
	else {
		printf("\n\nTest t_anneau_ajouter_fin: ECHEC");
	}
	printf("\nValeur attendu: 2\nValeur recu:    %d\n", t_anneau_get_valeur(anneau1, 0));
}

/*  ___________________________________________________________________________
	Nom	:			t_anneau_ajouter_debut_test
	___________________________________________________________________________
	Description :	test de la fonction t_anneau_ajouter_debut
	___________________________________________________________________________
	Paramètres : aucun
	___________________________________________________________________________
	Retour : aucun
	___________________________________________________________________________
	Requis 1 : Demontrer que la fonction t_anneau_ajouter_debut fonctionne
	___________________________________________________________________________
*/
void t_anneau_ajouter_debut_test(void) {
	t_anneau* anneau1 = t_anneau_init();
	t_anneau_ajouter_debut(anneau1, 2);
	if (t_anneau_get_valeur(anneau1, 0) == 2) {
		printf("\n\nTest t_anneau_ajouter_debut: SUCCES");
	}
	else {
		printf("\n\nTest t_anneau_ajouter_debut: ECHEC");
	}
	printf("\nValeur attendu: 2\nValeur recu:    %d\n", t_anneau_get_valeur(anneau1, 0));
}

/*  ___________________________________________________________________________
	Nom	:			t_anneau_ajouter_test
	___________________________________________________________________________
	Description :	test de la fonction t_anneau_ajouter
	___________________________________________________________________________
	Paramètres : aucun
	___________________________________________________________________________
	Retour : aucun
	___________________________________________________________________________
	Requis 1 : Demontrer que la fonction t_anneau_ajouter fonctionne
	___________________________________________________________________________
*/
void t_anneau_ajouter_test(void) {
	t_anneau* anneau1 = t_anneau_init();
	t_anneau_ajouter_fin(anneau1, 2);
	t_anneau_ajouter(anneau1, 0, 5);
	if (t_anneau_get_valeur(anneau1, 0) == 5) {
		printf("\n\nTest t_anneau_ajouter: SUCCES");
	}
	else {
		printf("\n\nTest t_anneau_ajouter: ECHEC");
	}
	printf("\nValeur attendu: 5\nValeur recu:    %d\n", t_anneau_get_valeur(anneau1, 0));
}

/*  ___________________________________________________________________________
	Nom	:			t_anneau_retirer_test
	___________________________________________________________________________
	Description :	test de la fonction t_anneau_retirer
	___________________________________________________________________________
	Paramètres : aucun
	___________________________________________________________________________
	Retour : aucun
	___________________________________________________________________________
	Requis 1 : Demontrer que la fonction t_anneau_retirer fonctionne
	___________________________________________________________________________
*/
void t_anneau_retirer_test(void) {
	t_anneau* anneau1 = t_anneau_init();
	t_anneau_ajouter_fin(anneau1, 2);
	int valeur = t_anneau_retirer(anneau1, 0);
	if (valeur == 2) {
		printf("\n\nTest t_anneau_retirer: SUCCES");
	}
	else {
		printf("\n\nTest t_anneau_retirer: ECHEC");
	}
	printf("\nValeur attendu: 2\nValeur recu:    %d\n", valeur);
}

/*  ___________________________________________________________________________
	Nom	:			t_anneau_retirer_debut_test
	___________________________________________________________________________
	Description :	test de la fonction t_anneau_retirer_debut
	___________________________________________________________________________
	Paramètres : aucun
	___________________________________________________________________________
	Retour : aucun
	___________________________________________________________________________
	Requis 1 : Demontrer que la fonction t_anneau_retirer_debut fonctionne
	___________________________________________________________________________
*/
void t_anneau_retirer_debut_test(void) {
	t_anneau* anneau1 = t_anneau_init();
	t_anneau_ajouter_fin(anneau1, 2);
	int valeur = t_anneau_retirer_debut(anneau1);
	if (valeur == 2) {
		printf("\n\nTest t_anneau_retirer_debut: SUCCES");
	}
	else {
		printf("\n\nTest t_anneau_retirer_debut: ECHEC");
	}
	printf("\nValeur attendu: 2\nValeur recu:    %d\n", valeur);
}