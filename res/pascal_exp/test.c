#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include "lex.h"
#include "erreur.h"
#include "syn.h"
int main() {
	fichier = fopen("C:/Users/Kisuke/Desktop/compilation/pascal.p", "r");
	debut();
	lire_sym();
	PROGRAM();
	if (sym_cour.code == FIN_TOKEN) {
		printf("Bravo : le programme est correcte");
	}
	else {
		printf(" le programme n'est pas correcte");
	}
	return 0;
}
