#include <stdio.h>
#include <stdlib.h>
#include "lex.h"
#include "syn.h"
#include "sem.h"
#include "erreur.h"
#include <string.h>
#define NbrIDFS 100 

T_TAB_IDF TAB_IDFS [NbrIDFS];
int compteur_id = 0;

void ajouter_id(TSYM tid) {
	strcpy_s(TAB_IDFS[compteur_id].nom , 100 , sym_cour.nom);
	TAB_IDFS[compteur_id].TIDF = tid;
	compteur_id++;
}

int double_declaration() {
	for (int i = 0; i < compteur_id; i++) {
		if (!strcmp(sym_cour.nom, TAB_IDFS[i].nom)) {
			return 1;
		}
	}
	return 0;
}

int affectation_const() {
	for (int i = 0; i < compteur_id; i++) {
		if (!strcmp(sym_cour.nom, TAB_IDFS[i].nom) && TAB_IDFS[i].TIDF == TCONST ) {
			return 1;
		}
	}
	return 0;
}

int use_prog() {
	for (int i = 0; i < compteur_id; i++) {
		if (!strcmp(sym_cour.nom, TAB_IDFS[i].nom) && TAB_IDFS[i].TIDF == TPROG) {
			return 1;
		}
	}
	return 0;
}

int undeclared() {
	for (int i = 0; i < compteur_id; i++) {
		if (!strcmp(sym_cour.nom, TAB_IDFS[i].nom)) {
			return 0;
		}
	}
	return 1;
}

