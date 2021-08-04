#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "ModuleNoeud.h"
#include "ModuleAnneau.h"
#include "ModuleTests.h"

int main(void)
{
	t_noeud_set_valeur_test();
	t_noeud_get_valeur_test();
	t_noeud_get_droit_test();
	t_noeud_get_gauche_test();

	t_anneau_get_taille_test();
	t_anneau_get_valeur_test();
	t_anneau_set_valeur_test();
	t_anneau_ajouter_fin_test();
	t_anneau_ajouter_debut_test();
	t_anneau_ajouter_test();
	t_anneau_retirer_test();
	t_anneau_retirer_debut_test();

	system("pause");
	return EXIT_SUCCESS;
}