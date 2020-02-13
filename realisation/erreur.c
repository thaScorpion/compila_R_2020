#include "erreur.h"
#include "lex.h"
#include <stdio.h>
#include <stdlib.h>

ERROR	MES_ERR[100] = { 
	{ERR_CAR_INC,"caractere inconnu"}, 
	{ERR_FICH_VID,"fichier vide"},
	{ERR_ID_LONG , "IDF tres long"},
	{PROGRAM_ERR, "PROGRAM_ERR"},
	{ID_ERR , "ID_ERR"},
	{PV_ERR , "PV_ERR"},
	{PT_ERR , "PT_ERR"},	
};
void Erreur(CODES_ERR ERR) {
	int  ind_err = ERR;
	printf("Erreur  numero  %d \t : %s \n", ind_err, MES_ERR[ind_err].mes);
	getchar();
	exit(1);
}