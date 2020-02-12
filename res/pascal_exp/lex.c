#include <stdio.h>
#include <stdlib.h>
#include "lex.h"
#include "erreur.h"
#include <string.h>

SYM_COUR sym_cour;
char car_cour;
FILE* fichier;

void debut() {
	// Debut
	car_cour = fgetc(fichier);

	// verification du fichier vide
	while (car_cour == ' ' || car_cour == '\n' || car_cour == '\t')
		car_cour = fgetc(fichier);
	if (car_cour == EOF)
		Erreur(ERR_FICH_VID);
}



void lire_sym() {

	// on ignore les espace retour a la ligne
	while (car_cour == ' ' || car_cour == '\n' || car_cour == '\t')
		car_cour = fgetc(fichier);


	// on ignore les commentaires 

	if (car_cour == '{') {
		lire_com();
	}


	// on lit les chaine de la forme 'xxxxx'

	if (car_cour == '\'') {
		lire_chaine();
		sym_cour.code = CHAINE_TOKEN;
	}


	// on lit les mots qui commence par une lettre ou une '_' et qui comporte juste le chiffres , les lettres et les '_' 
	else if ((car_cour >= 'a' && car_cour <= 'z') || (car_cour >= 'A' && car_cour <= 'Z') || car_cour == '_') {
		lire_mot();
		if (!strcmp(sym_cour.nom, "program"))
			sym_cour.code = PROGRAM_TOKEN;
		else if (!strcmp(sym_cour.nom, "const"))
			sym_cour.code = CONST_TOKEN;
		else if (!strcmp(sym_cour.nom, "var"))
			sym_cour.code = VAR_TOKEN;
		else if (!strcmp(sym_cour.nom, "begin"))
			sym_cour.code = BEGIN_TOKEN;
		else if (!strcmp(sym_cour.nom, "end"))
			sym_cour.code = END_TOKEN;
		else if (!strcmp(sym_cour.nom, "if"))
			sym_cour.code = IF_TOKEN;
		else if (!strcmp(sym_cour.nom, "then"))
			sym_cour.code = THEN_TOKEN;
		else if (!strcmp(sym_cour.nom, "while"))
			sym_cour.code = WHILE_TOKEN;
		else if (!strcmp(sym_cour.nom, "do"))
			sym_cour.code = DO_TOKEN;
		else if (!strcmp(sym_cour.nom, "read"))
			sym_cour.code = READ_TOKEN;
		else if (!strcmp(sym_cour.nom, "write"))
			sym_cour.code = WRITE_TOKEN;
		else
			sym_cour.code = ID_TOKEN;  // les mots qui ne sont pas reservés au langage sont des identifiants

	}




	// on lit un numero qui comporte que des chiffres
	else if (car_cour >= '0' && car_cour <= '9') {
		lire_num();
		sym_cour.code = NUM_TOKEN;

	}


	// les operateur speciaux
	else if (car_cour == '*' || car_cour == '+' || car_cour == '/' || car_cour == '-' || car_cour == ',' || car_cour == ';' || car_cour == '.' || car_cour == '<' || car_cour == '>'
		|| car_cour == '(' || car_cour == ')' || car_cour == EOF || car_cour == ':' || car_cour == '=') {
		lire_special();
	}
	// sinon c'est un caractere inconnue
	else {
		sym_cour.code = ERREUR_TOKEN;
		Erreur(ERR_CAR_INC);
	}
}




void lire_com() {
	car_cour = fgetc(fichier);
	if (car_cour == '*') {
		car_cour = fgetc(fichier);
		while (car_cour != EOF) {
			if (car_cour == '*') {
				car_cour = fgetc(fichier);
				if (car_cour == '}') {
					car_cour = fgetc(fichier);
					while (car_cour == ' ' || car_cour == '\n' || car_cour == '\t')
						car_cour = fgetc(fichier);
					break;
				}
			}
			car_cour = fgetc(fichier);
		}
	}

	else Erreur(ERR_CAR_INC);

}


void lire_chaine() {
	int i = 0;
	car_cour = fgetc(fichier);
	while (car_cour != EOF && car_cour != '\'') {
		sym_cour.nom[i] = car_cour;
		i++;
		car_cour = fgetc(fichier);
	}
	sym_cour.nom[i] = '\0';
	if (car_cour == EOF) {
		Erreur(ERR_CAR_INC);
	}


}






void lire_mot() {
	int i = 0;
	sym_cour.nom[i] = car_cour;
	car_cour = fgetc(fichier);
	i++;
	while ((car_cour >= 'a' && car_cour <= 'z') || (car_cour >= 'A' && car_cour <= 'Z') || (car_cour >= '0' && car_cour <= '9') || (car_cour == '_')) {
		sym_cour.nom[i] = car_cour;
		car_cour = fgetc(fichier);
		if (i >= 20) {
			sym_cour.code = ERREUR_TOKEN;
			Erreur(ERR_ID_LONG);
		}

		i++;
	}
	sym_cour.nom[i] = '\0';
}


void lire_num() {
	int i = 0;
	sym_cour.nom[i] = car_cour;
	car_cour = fgetc(fichier);
	i++;
	while ((car_cour >= '0' && car_cour <= '9')) {
		sym_cour.nom[i] = car_cour;
		car_cour = fgetc(fichier);
		i++;
	}
	sym_cour.nom[i] = '\0';
	sym_cour.val = atoi(sym_cour.nom);
}



void lire_special() {
	int i = 0;
	char suiv;
	sym_cour.nom[i] = car_cour;
	switch (car_cour) {
	case '*':
		sym_cour.code = MULT_TOKEN;
		car_cour = fgetc(fichier);
		i++;
		sym_cour.nom[i] = '\0';
		break;

	case '+':
		sym_cour.code = PLUS_TOKEN;
		i++;
		car_cour = fgetc(fichier);
		sym_cour.nom[i] = '\0';
		break;

	case '/':
		sym_cour.code = DIV_TOKEN;
		i++;
		car_cour = fgetc(fichier);
		sym_cour.nom[i] = '\0';
		break;

	case '-':
		sym_cour.code = MOINS_TOKEN;
		i++;
		car_cour = fgetc(fichier);
		sym_cour.nom[i] = '\0';
		break;

	case ',':
		sym_cour.code = VIR_TOKEN;
		i++;
		car_cour = fgetc(fichier);
		sym_cour.nom[i] = '\0';
		break;

	case ';':
		sym_cour.code = PV_TOKEN;
		i++;
		car_cour = fgetc(fichier);
		sym_cour.nom[i] = '\0';
		break;

	case '.':
		sym_cour.code = PT_TOKEN;
		i++;
		car_cour = fgetc(fichier);
		sym_cour.nom[i] = '\0';
		break;

	case '=':
		sym_cour.code = EGAL_TOKEN;
		i++;
		car_cour = fgetc(fichier);
		sym_cour.nom[i] = '\0';
		break;

	case '(':
		sym_cour.code = PO_TOKEN;
		i++;
		car_cour = fgetc(fichier);
		sym_cour.nom[i] = '\0';
		break;

	case ')':
		sym_cour.code = PF_TOKEN;
		i++;
		car_cour = fgetc(fichier);
		sym_cour.nom[i] = '\0';
		break;

	case EOF:
		sym_cour.code = FIN_TOKEN;
		i++;
		sym_cour.nom[i] = '\0';
		break;

	case '<':
		suiv = fgetc(fichier);
		if (suiv == '=') {
			sym_cour.code = INFEG_TOKEN;
			i++;
			sym_cour.nom[i] = '=';
			i++;
			car_cour = fgetc(fichier);
			sym_cour.nom[i] = '\0';
		}

		else if (suiv == '>') {
			sym_cour.code = DIFF_TOKEN;
			i++;
			sym_cour.nom[i] = '>';
			i++;
			car_cour = fgetc(fichier);
			sym_cour.nom[i] = '\0';
		}

		else {
			fseek(fichier, -1, SEEK_CUR);
			sym_cour.code = INF_TOKEN;
			i++;
			car_cour = fgetc(fichier);
			sym_cour.nom[i] = '\0';
		}

		break;

	case '>':
		suiv = fgetc(fichier);
		if (suiv == '=') {
			sym_cour.code = SUPEG_TOKEN;
			i++;
			sym_cour.nom[i] = '=';
			i++;
			car_cour = fgetc(fichier);
			sym_cour.nom[i] = '\0';
		}

		else {
			fseek(fichier, -1, SEEK_CUR);
			sym_cour.code = SUP_TOKEN;
			i++;
			car_cour = fgetc(fichier);
			sym_cour.nom[i] = '\0';
		}

		break;

	case ':':
		suiv = fgetc(fichier);
		if (suiv == '=') {
			sym_cour.code = AFF_TOKEN;
			i++;
			sym_cour.nom[i] = '=';
			i++;
			car_cour = fgetc(fichier);
			sym_cour.nom[i] = '\0';
		}

		else {
			fseek(fichier, -1, SEEK_CUR);
			sym_cour.code = ERREUR_TOKEN;
			Erreur(ERR_CAR_INC);
			i++;
			sym_cour.nom[i] = '\0';
		}

		break;

	}

}

const char* getCodeName(CODES_LEX code) {
	switch (code)
	{
		case PROGRAM_TOKEN: return "PROGRAM_TOKEN";
		case CONST_TOKEN: return "CONST_TOKEN";
		case VAR_TOKEN: return "VAR_TOKEN";
		case BEGIN_TOKEN: return "BEGIN_TOKEN";
		case END_TOKEN: return "END_TOKEN";
		case IF_TOKEN: return "IF_TOKEN";
		case THEN_TOKEN: return "THEN_TOKEN";
		case WHILE_TOKEN: return "WHILE_TOKEN";
		case DO_TOKEN: return "DO_TOKEN";
		case READ_TOKEN: return "READ_TOKEN";
		case WRITE_TOKEN: return "WRITE_TOKEN";
		case PV_TOKEN: return "PV_TOKEN";
		case PT_TOKEN: return "PT_TOKEN";
		case PLUS_TOKEN: return "PLUS_TOKEN";
		case MOINS_TOKEN: return "MOINS_TOKEN";
		case MULT_TOKEN: return "MULT_TOKEN";
		case DIV_TOKEN: return "DIV_TOKEN";
		case VIR_TOKEN: return "VIR_TOKEN";
		case AFF_TOKEN: return "AFF_TOKEN";
		case EGAL_TOKEN: return "EGAL_TOKEN";
		case INF_TOKEN: return "INF_TOKEN";
		case INFEG_TOKEN: return "INFEG_TOKEN";
		case SUP_TOKEN: return "SUP_TOKEN";
		case SUPEG_TOKEN: return "SUPEG_TOKEN";
		case DIFF_TOKEN: return "DIFF_TOKEN";
		case PO_TOKEN: return "PO_TOKEN";
		case PF_TOKEN: return "PF_TOKEN";
		case FIN_TOKEN: return "FIN_TOKEN";
		case ID_TOKEN: return "ID_TOKEN";
		case NUM_TOKEN: return "NUM_TOKEN";
		case CHAINE_TOKEN: return "CHAINE_TOKEN";
		case ERREUR_TOKEN: return "ERREUR_TOKEN";

		}
}

