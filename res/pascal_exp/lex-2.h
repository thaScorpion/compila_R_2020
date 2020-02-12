#ifndef LEX
#define LEX
#include <stdio.h>

typedef enum {
	PROGRAM_TOKEN,
	CONST_TOKEN,
	VAR_TOKEN,
	BEGIN_TOKEN,
	END_TOKEN,
	IF_TOKEN,
	ELSE_TOKEN,
	THEN_TOKEN,
	WHILE_TOKEN,
	DO_TOKEN,
	READ_TOKEN,
	WRITE_TOKEN,
	PV_TOKEN,
	PT_TOKEN,
	PLUS_TOKEN,
	MOINS_TOKEN,
	MULT_TOKEN,
	DIV_TOKEN,
	VIR_TOKEN,
	AFF_TOKEN,
	EGAL_TOKEN,
	INF_TOKEN,
	INFEG_TOKEN,
	SUP_TOKEN,
	SUPEG_TOKEN,
	DIFF_TOKEN,
	PO_TOKEN,
	PF_TOKEN,
	FIN_TOKEN,
	ID_TOKEN,
	NUM_TOKEN,
	CHAINE_TOKEN,
	ERREUR_TOKEN,

} CODES_LEX;


typedef struct sym_cour {
	int code;
	char nom[1000];
	int val;
}SYM_COUR;

extern SYM_COUR sym_cour;
extern char car_cour; 
extern FILE* fichier; 

void lire_sym();
void lire_mot();
void lire_num();
void lire_special();
void lire_com();
void lire_chaine();
void debut();
const char* getCodeName(CODES_LEX code);

#endif // 



