#include<stdlib.h>
#include<stdio.h>
#include "lex.h"
#include "erreur.h"

int main()
{
	fichier = fopen("pascaLex.p", "r");
	debut();
	while(car_cour != EOF)
	{
		lire_sym();
		
		printf("%s\n", getCodeName(sym_cour.code));
	}
	return 0;
}