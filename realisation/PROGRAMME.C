#include <stdio.h>
#include <stdlib.h>
#include "lex.h"
#include "erreur.h"
#include <assert.h>

//#include "global.h"
#include "analyseur_syntaxique.h"

int main(int argc, char const *argv[])
{
    
    fichier = fopen("pascaLex.p", "r");
    debut();
    lire_sym();
	INSTS();
	if(sym_cour.code == FIN_TOKEN)
		printf("BRAVO: le programme est correcte!!! test\n");
	else
		printf("PAS BRAVO: fin de programme erronee!!!! test\n");
    return 0;
}



