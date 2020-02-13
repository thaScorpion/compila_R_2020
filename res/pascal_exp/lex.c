#include <stdio.h>
#include <stdlib.h>
#include "lex.h"
#include "erreur.h"
#include <string.h>

SYM_COUR sym_cour;
char car_cour;
FILE* fichier;

void debut() {
	getNextChar();
	while (car_cour == ' ' || car_cour == '\n' || car_cour == '\t')
		getNextChar();
	if (car_cour == EOF)
		Erreur(ERR_FICH_VID);
}

void getNextChar()
{
	car_cour = fgetc(fichier);
}

void lire_sym() {

	//ignorer separateurs
	while (car_cour == ' ' || car_cour == '\n' || car_cour == '\t')
		getNextChar();

	if (car_cour == '#') {
		lire_com();
	}


	if (car_cour == '\'') {
		lire_chaine();
		sym_cour.code = CHAINE_TOKEN;
	}

	// on lit les mots qui commence par une lettre ou une '_' et qui comporte juste le chiffres , les lettres et les '_' 
	else if ((car_cour >= 'a' && car_cour <= 'z') || (car_cour >= 'A' && car_cour <= 'Z') || car_cour == '_' || car_cour == '.') {
		lire_mot();
		if (!strcmp(sym_cour.nom, "if"))
			sym_cour.code = IF_TOKEN;
		else if (!strcmp(sym_cour.nom, "while"))
			sym_cour.code = WHILE_TOKEN;
		else if (!strcmp(sym_cour.nom, "repeat"))
			sym_cour.code = REPEAT_TOKEN;
		else if (!strcmp(sym_cour.nom, "read"))
			sym_cour.code = READ_TOKEN;
		else if (!strcmp(sym_cour.nom, "else"))
			sym_cour.code = WHILE_TOKEN;
		else if (!strcmp(sym_cour.nom, ".libPaths"))
			sym_cour.code = _LIBPATHS_TOKEN;
		else if (!strcmp(sym_cour.nom, "round"))
			sym_cour.code = ROUND_TOKEN;
		else if (!strcmp(sym_cour.nom, "hist"))
			sym_cour.code = HIST_TOKEN;
		else if (!strcmp(sym_cour.nom, "sighnif"))
			sym_cour.code = SIGHNIF_TOKEN;
		else if (!strcmp(sym_cour.nom, "log"))
			sym_cour.code = LOG_TOKEN;
		else if (!strcmp(sym_cour.nom, "na"))
			sym_cour.code = NA_TOKEN;
		else if (!strcmp(sym_cour.nom, "numeric"))
			sym_cour.code = NUMERIC_TOKEN;
		else if (!strcmp(sym_cour.nom, "print"))
			sym_cour.code = PRINT_TOKEN;
		else if (!strcmp(sym_cour.nom, "null"))
			sym_cour.code = NULL_TOKEN;
		else if (!strcmp(sym_cour.nom, "load"))
			sym_cour.code = LOAD_TOKEN;
		else if (!strcmp(sym_cour.nom, "sort"))
			sym_cour.code = SORT_TOKEN;
		else if (!strcmp(sym_cour.nom, "breaks"))
			sym_cour.code = BREAKS_TOKEN;
		else if (!strcmp(sym_cour.nom, "read"))
			sym_cour.code = READ_TOKEN;
		else if (!strcmp(sym_cour.nom, "for"))
			sym_cour.code = FOR_TOKEN;
		else if (!strcmp(sym_cour.nom, "cut"))
			sym_cour.code = CUT_TOKEN;
		else if (!strcmp(sym_cour.nom, "rnorm"))
			sym_cour.code = RNORM_TOKEN;
		else if (!strcmp(sym_cour.nom, "nrow"))
			sym_cour.code = NROW_TOKEN;
		else if (!strcmp(sym_cour.nom, "else"))
			sym_cour.code = ELSE_TOKEN;
		else if (!strcmp(sym_cour.nom, "if"))
			sym_cour.code = IF_TOKEN;
		else if (!strcmp(sym_cour.nom, "while"))
			sym_cour.code = WHILE_TOKEN;
		else if (!strcmp(sym_cour.nom, "help"))
			sym_cour.code = HELP_TOKEN;
		else if (!strcmp(sym_cour.nom, "exp"))
			sym_cour.code = EXP_TOKEN;
		else if (!strcmp(sym_cour.nom, "as"))
			sym_cour.code = AS_TOKEN;
		else if (!strcmp(sym_cour.nom, "matrix"))
			sym_cour.code = MATRIX_TOKEN;
		else if (!strcmp(sym_cour.nom, "install"))
			sym_cour.code = INSTALL_TOKEN;
		else if (!strcmp(sym_cour.nom, "pairwise.t.test"))
			sym_cour.code = PAIRWISE_T_TEST_TOKEN;
		else if (!strcmp(sym_cour.nom, "max"))
			sym_cour.code = MAX_TOKEN;
		else if (!strcmp(sym_cour.nom, "min"))
			sym_cour.code = MIN_TOKEN;
		else if (!strcmp(sym_cour.nom, "view"))
			sym_cour.code = VIEW_TOKEN;
		else if (!strcmp(sym_cour.nom, "library"))
			sym_cour.code = LIBRARY_TOKEN;
		else if (!strcmp(sym_cour.nom, "save"))
			sym_cour.code = SAVE_TOKEN;
		else if (!strcmp(sym_cour.nom, "rev"))
			sym_cour.code = REV_TOKEN;
		else if (!strcmp(sym_cour.nom, "str"))
			sym_cour.code = STR_TOKEN;
		else if (!strcmp(sym_cour.nom, "getwd"))
			sym_cour.code = GETWD_TOKEN;
		else if (!strcmp(sym_cour.nom, "grep"))
			sym_cour.code = GREP_TOKEN;
		else if (!strcmp(sym_cour.nom, "package"))
			sym_cour.code = PACKAGE_TOKEN;
		else if (!strcmp(sym_cour.nom, "search"))
			sym_cour.code = SEARCH_TOKEN;
		else if (!strcmp(sym_cour.nom, "plot"))
			sym_cour.code = PLOT_TOKEN;
		else if (!strcmp(sym_cour.nom, "rbinom"))
			sym_cour.code = RBINOM_TOKEN;
		else if (!strcmp(sym_cour.nom, "mean"))
			sym_cour.code = MEAN_TOKEN;
		else if (!strcmp(sym_cour.nom, "data"))
			sym_cour.code = DATA_TOKEN;
		else if (!strcmp(sym_cour.nom, "times"))
			sym_cour.code = TIMES_TOKEN;
		else if (!strcmp(sym_cour.nom, "ls"))
			sym_cour.code = LS_TOKEN;
		else if (!strcmp(sym_cour.nom, "by"))
			sym_cour.code = BY_TOKEN;
		else if (!strcmp(sym_cour.nom, "table"))
			sym_cour.code = TABLE_TOKEN;
		else if (!strcmp(sym_cour.nom, "seq"))
			sym_cour.code = SEQ_TOKEN;
		else if (!strcmp(sym_cour.nom, "nchar"))
			sym_cour.code = NCHAR_TOKEN;
		else if (!strcmp(sym_cour.nom, "setwd"))
			sym_cour.code = SETWD_TOKEN;
		else if (!strcmp(sym_cour.nom, "each"))
			sym_cour.code = EACH_TOKEN;
		else if (!strcmp(sym_cour.nom, "logicalal"))
			sym_cour.code = LOGICALAL_TOKEN;
		else if (!strcmp(sym_cour.nom, "pnorm"))
			sym_cour.code = PNORM_TOKEN;
		else if (!strcmp(sym_cour.nom, "in"))
			sym_cour.code = IN_TOKEN;
		else if (!strcmp(sym_cour.nom, "collapse"))
			sym_cour.code = COLLAPSE_TOKEN;
		else if (!strcmp(sym_cour.nom, "unique"))
			sym_cour.code = UNIQUE_TOKEN;
		else if (!strcmp(sym_cour.nom, "write"))
			sym_cour.code = WRITE_TOKEN;
		else if (!strcmp(sym_cour.nom, "cor"))
			sym_cour.code = COR_TOKEN;
		else if (!strcmp(sym_cour.nom, "replace"))
			sym_cour.code = REPLACE_TOKEN;
		else if (!strcmp(sym_cour.nom, "FALSE"))
			sym_cour.code = FALSE_TOKEN;
		else if (!strcmp(sym_cour.nom, "qnorm"))
			sym_cour.code = QNORM_TOKEN;
		else if (!strcmp(sym_cour.nom, "prop.test"))
			sym_cour.code = PROP_TEST_TOKEN;
		else if (!strcmp(sym_cour.nom, "rm"))
			sym_cour.code = RM_TOKEN;
		else if (!strcmp(sym_cour.nom, "rep"))
			sym_cour.code = REP_TOKEN;
		else if (!strcmp(sym_cour.nom, "list"))
			sym_cour.code = LIST_TOKEN;
		else if (!strcmp(sym_cour.nom, "ncol"))
			sym_cour.code = NCOL_TOKEN;
		else if (!strcmp(sym_cour.nom, "frame"))
			sym_cour.code = FRAME_TOKEN;
		else if (!strcmp(sym_cour.nom, "is"))
			sym_cour.code = IS_TOKEN;
		else if (!strcmp(sym_cour.nom, "gsub"))
			sym_cour.code = GSUB_TOKEN;
		else if (!strcmp(sym_cour.nom, "dim"))
			sym_cour.code = DIM_TOKEN;
		else if (!strcmp(sym_cour.nom, "head"))
			sym_cour.code = HEAD_TOKEN;
		else if (!strcmp(sym_cour.nom, "paste"))
			sym_cour.code = PASTE_TOKEN;
		else if (!strcmp(sym_cour.nom, "class"))
			sym_cour.code = CLASS_TOKEN;
		else if (!strcmp(sym_cour.nom, "summary"))
			sym_cour.code = SUMMARY_TOKEN;
		else if (!strcmp(sym_cour.nom, "qbinom"))
			sym_cour.code = QBINOM_TOKEN;
		else if (!strcmp(sym_cour.nom, "pattern"))
			sym_cour.code = PATTERN_TOKEN;
		else if (!strcmp(sym_cour.nom, "glm"))
			sym_cour.code = GLM_TOKEN;
		else if (!strcmp(sym_cour.nom, "sep"))
			sym_cour.code = SEP_TOKEN;
		else if (!strcmp(sym_cour.nom, "toloer"))
			sym_cour.code = TOLOER_TOKEN;
		else if (!strcmp(sym_cour.nom, "character"))
			sym_cour.code = CHARACTER_TOKEN;
		else if (!strcmp(sym_cour.nom, "toupper"))
			sym_cour.code = TOUPPER_TOKEN;
		else if (!strcmp(sym_cour.nom, "lm"))
			sym_cour.code = LM_TOKEN;
		else if (!strcmp(sym_cour.nom, "punif"))
			sym_cour.code = PUNIF_TOKEN;
		else if (!strcmp(sym_cour.nom, "t.test"))
			sym_cour.code = T_TEST_TOKEN;
		else if (!strcmp(sym_cour.nom, "qunif"))
			sym_cour.code = QUNIF_TOKEN;
		else if (!strcmp(sym_cour.nom, "aov"))
			sym_cour.code = AOV_TOKEN;
		else if (!strcmp(sym_cour.nom, "c"))
			sym_cour.code = C_TOKEN;
		else if (!strcmp(sym_cour.nom, "input"))
			sym_cour.code = INPUT_TOKEN;
		else if (!strcmp(sym_cour.nom, "select"))
			sym_cour.code = SELECT_TOKEN;
		else if (!strcmp(sym_cour.nom, "dnorm"))
			sym_cour.code = DNORM_TOKEN;
		else if (!strcmp(sym_cour.nom, "factor"))
			sym_cour.code = FACTOR_TOKEN;
		else if (!strcmp(sym_cour.nom, "TRUE"))
			sym_cour.code = TRUE_TOKEN;
		else if (!strcmp(sym_cour.nom, "ppois"))
			sym_cour.code = PPOIS_TOKEN;
		else if (!strcmp(sym_cour.nom, "rpois"))
			sym_cour.code = RPOIS_TOKEN;
		else if (!strcmp(sym_cour.nom, "dbinom"))
			sym_cour.code = DBINOM_TOKEN;
		else if (!strcmp(sym_cour.nom, "dpois"))
			sym_cour.code = DPOIS_TOKEN;
		else if (!strcmp(sym_cour.nom, "qpois"))
			sym_cour.code = QPOIS_TOKEN;
		else if (!strcmp(sym_cour.nom, "pbinom"))
			sym_cour.code = PBINOM_TOKEN;
		else if (!strcmp(sym_cour.nom, "file"))
			sym_cour.code = FILE_TOKEN;
		else if (!strcmp(sym_cour.nom, "runif"))
			sym_cour.code = RUNIF_TOKEN;
		else if (!strcmp(sym_cour.nom, "dunif"))
			sym_cour.code = DUNIF_TOKEN;


		else
			sym_cour.code = ID_TOKEN;  // les mots qui ne sont pas reservés au langage sont des identifiants
	}




	// on lit un nombre qui comporte que des chiffres
	else if (car_cour >= '0' && car_cour <= '9') {
		lire_num();
		sym_cour.code = NUM_TOKEN;

	}


	// les operateur speciaux
	else if (car_cour == '*' || car_cour == '+' || car_cour == '/' || car_cour == '-' || car_cour == ',' || car_cour == ';' || car_cour == '.' || car_cour == '<' || car_cour == '>'
		|| car_cour == '(' || car_cour == ')' || car_cour == EOF || car_cour == ':' || car_cour == '=' || car_cour == '%'  || car_cour == '[' || car_cour == ']'  || car_cour == '\''   || car_cour == '{' || car_cour == '}' || car_cour == '!' || car_cour == '$' || car_cour == '~') {
		lire_special();
	}
	// sinon c'est un caractere inconnue
	else {
		sym_cour.code = ERREUR_TOKEN;
		Erreur(ERR_CAR_INC);
	}
}




void lire_com() {
	getNextChar();
	while(car_cour != '\n') getNextChar();
	while (car_cour == ' ' || car_cour == '\n' || car_cour == '\t') getNextChar();
}


void lire_chaine() {
	int i = 0;
	getNextChar();
	while (car_cour != EOF && car_cour != '\'') {
		sym_cour.nom[i++] = car_cour;
		getNextChar();
	}
	sym_cour.nom[i] = '\0';
	if (car_cour == EOF) {
		Erreur(ERR_CAR_INC);
	}
}

void lire_mot() {
	int i = 0;
	sym_cour.nom[i] = car_cour;
	getNextChar();
	i++;
	while ((car_cour >= 'a' && car_cour <= 'z') || (car_cour >= 'A' && car_cour <= 'Z') || (car_cour >= '0' && car_cour <= '9') || (car_cour == '_')  || (car_cour == '.')) {
		sym_cour.nom[i] = car_cour;
		getNextChar();
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
	getNextChar();
	i++;
	while ((car_cour >= '0' && car_cour <= '9')) {
		sym_cour.nom[i] = car_cour;
		getNextChar();
		i++;
	}
	sym_cour.nom[i] = '\0';
	sym_cour.val = atoi(sym_cour.nom);
}



void lire_special() {
	int i = 0;
	char suiv, suiv2;
	sym_cour.nom[i] = car_cour;
	switch (car_cour) {
	case '*':
		sym_cour.code = MULT_TOKEN;
		getNextChar();
		i++;
		sym_cour.nom[i] = '\0';
		break;

	case '+':
		sym_cour.code = PLUS_TOKEN;
		i++;
		getNextChar();
		sym_cour.nom[i] = '\0';
		break;

	case '/':
		sym_cour.code = DIV_TOKEN;
		i++;
		getNextChar();
		sym_cour.nom[i] = '\0';
		break;

	case '-':
		suiv = fgetc(fichier);
		if (suiv == '>')
		{
			suiv2 = fgetc(fichier);
			if (suiv2 == '>')
			{
				sym_cour.code = ASSIGN2O_TOKEN;
				i++;
				getNextChar();
				sym_cour.nom[i] = '\0';
			}
			else
			{
				fseek(fichier, -1, SEEK_CUR);
				sym_cour.code = ASSIGNO_TOKEN;
				i++;
				getNextChar();
				sym_cour.nom[i] = '\0';
			}
		}
		else
		{
			fseek(fichier, -1, SEEK_CUR);
			sym_cour.code = MOINS_TOKEN;
			i++;
			getNextChar();
			sym_cour.nom[i] = '\0';
		}
		break;
	case ',':
		sym_cour.code = VIR_TOKEN;
		i++;
		getNextChar();
		sym_cour.nom[i] = '\0';
		break;

	case ';':
		sym_cour.code = PV_TOKEN;
		i++;
		getNextChar();
		sym_cour.nom[i] = '\0';
		break;

	case '=':
		suiv = fgetc(fichier);
		if (suiv == '=') {
			sym_cour.code = DOUBLE_EGAL_TOKEN;
			i++;
			sym_cour.nom[i] = '=';
			i++;
			getNextChar();
			sym_cour.nom[i] = '\0';
		}
		else {
			fseek(fichier, -1, SEEK_CUR);
			sym_cour.code = EGAL_TOKEN;
			i++;
			getNextChar();
			sym_cour.nom[i] = '\0';
		}
		
		break;

	case '(':
		sym_cour.code = PO_TOKEN;
		i++;
		getNextChar();
		sym_cour.nom[i] = '\0';
		break;

	case ')':
		sym_cour.code = PF_TOKEN;
		i++;
		getNextChar();
		sym_cour.nom[i] = '\0';
		break;

	case '%':
		sym_cour.code = PERCENT_TOKEN;
		i++;
		getNextChar();
		sym_cour.nom[i] = '\0';
		break;

	case '[':
		sym_cour.code = CROCHETO_TOKEN;
		i++;
		getNextChar();
		sym_cour.nom[i] = '\0';
		break;
	
	case ']':
		sym_cour.code = CROCHETF_TOKEN;
		i++;
		getNextChar();
		sym_cour.nom[i] = '\0';
		break;
	
	case '\'':
		sym_cour.code = QUOTE_TOKEN;
		i++;
		getNextChar();
		sym_cour.nom[i] = '\0';
		break;

	case '{':
		sym_cour.code = BRACKETO_TOKEN;
		i++;
		getNextChar();
		sym_cour.nom[i] = '\0';
		break;
	
	case '}':
		sym_cour.code = BRACKETF_TOKEN;
		i++;
		getNextChar();
		sym_cour.nom[i] = '\0';
		break;
	
	case '$':
		sym_cour.code = DOLLAR_TOKEN;
		i++;
		getNextChar();
		sym_cour.nom[i] = '\0';
		break;
	
	case '~':
		sym_cour.code = TILD_TOKEN;
		i++;
		getNextChar();
		sym_cour.nom[i] = '\0';
		break;
	case '!':
		suiv = fgetc(fichier);
		if (suiv == '=')
		{
			sym_cour.code = DIFF_TOKEN;
			i++;
			getNextChar();
			sym_cour.nom[i] = '\0';
		}
		else
		{
			sym_cour.code = ERREUR_TOKEN;
			i++;
			getNextChar();
			sym_cour.nom[i] = '\0';
		}
		break;

	case EOF:
		sym_cour.code = FIN_TOKEN;
		i++;
		sym_cour.nom[i] = '\0';
		break;

	case '<':
		suiv = fgetc(fichier);
		if (suiv == '<')
		{
			suiv2 = fgetc(fichier);
			if (suiv2 == '-')
			{
				sym_cour.code = ASSIGN2F_TOKEN;
				i++;
				getNextChar();
				sym_cour.nom[i] = '\0';
			}
			else
			{
				fseek(fichier, -1, SEEK_CUR);
				sym_cour.code = ERREUR_TOKEN;
				i++;
				getNextChar();
				sym_cour.nom[i] = '\0';
			}
		}
		else if (suiv == '=')
		{
			sym_cour.code = INFEG_TOKEN;
			i++;
			getNextChar();
			sym_cour.nom[i] = '\0';	
		}
		else if (suiv == '-')
		{
			sym_cour.code = ASSIGNF_TOKEN;
			i++;
			getNextChar();
			sym_cour.nom[i] = '\0';	
		}
		else
		{
			fseek(fichier, -1, SEEK_CUR);
			sym_cour.code = INF_TOKEN;
			i++;
			getNextChar();
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
			getNextChar();
			sym_cour.nom[i] = '\0';
		}

		else {
			fseek(fichier, -1, SEEK_CUR);
			sym_cour.code = SUP_TOKEN;
			i++;
			getNextChar();
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
			getNextChar();
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
		case FIN_TOKEN: return "FIN_TOKEN";
		case REPEAT_TOKEN: return "REPEAT_TOKEN";
		case ELSE_TOKEN: return "ELSE_TOKEN";
		case IF_TOKEN: return "IF_TOKEN";
		case WHILE_TOKEN: return "WHILE_TOKEN";
		case READ_TOKEN: return "READ_TOKEN";
		case PV_TOKEN: return "PV_TOKEN";
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
		case ID_TOKEN: return "ID_TOKEN";
		case NUM_TOKEN: return "NUM_TOKEN";
		case CHAINE_TOKEN: return "CHAINE_TOKEN";
		case ERREUR_TOKEN: return "ERREUR_TOKEN";
		case DOUBLE_EGAL_TOKEN: return "DOUBLE_EGAL_TOKEN";
		case PERCENT_TOKEN: return "PERCENT_TOKEN";
		case CROCHETO_TOKEN: return "CROCHETO_TOKEN";
		case CROCHETF_TOKEN: return "CROCHETF_TOKEN";
		case QUOTE_TOKEN: return "QUOTE_TOKEN";
		case BRACKETO_TOKEN: return "BRACKETO_TOKEN";
		case BRACKETF_TOKEN: return "BRACKETF_TOKEN";
		case ASSIGNO_TOKEN: return "ASSIGNO_TOKEN";
		case ASSIGN2O_TOKEN: return "ASSIGN2O_TOKEN";
		case ASSIGNF_TOKEN: return "ASSIGNF_TOKEN";
		case ASSIGN2F_TOKEN: return "ASSIGN2F_TOKEN";
		case DOLLAR_TOKEN: return "DOLLAR_TOKEN";
		case TILD_TOKEN: return "TILD_TOKEN";

		case _LIBPATHS_TOKEN: return "_LIBPATHS_TOKEN";
		case ROUND_TOKEN: return "ROUND_TOKEN";
		case HIST_TOKEN: return "HIST_TOKEN";
		case SIGHNIF_TOKEN: return "SIGHNIF_TOKEN";
		case LOG_TOKEN: return "LOG_TOKEN";
		case NA_TOKEN: return "NA_TOKEN";
		case NUMERIC_TOKEN: return "NUMERIC_TOKEN";
		case PRINT_TOKEN: return "PRINT_TOKEN";
		case NULL_TOKEN: return "NULL_TOKEN";
		case LOAD_TOKEN: return "LOAD_TOKEN";
		case SORT_TOKEN: return "SORT_TOKEN";
		case BREAKS_TOKEN: return "BREAKS_TOKEN";
		case FOR_TOKEN: return "FOR_TOKEN";
		case CUT_TOKEN: return "CUT_TOKEN";
		case RNORM_TOKEN: return "RNORM_TOKEN";
		case NROW_TOKEN: return "NROW_TOKEN";
		case HELP_TOKEN: return "HELP_TOKEN";
		case EXP_TOKEN: return "EXP_TOKEN";
		case AS_TOKEN: return "AS_TOKEN";
		case MATRIX_TOKEN: return "MATRIX_TOKEN";
		case INSTALL_TOKEN: return "INSTALL_TOKEN";
		case PAIRWISE_T_TEST_TOKEN: return "PAIRWISE_T_TEST_TOKEN";
		case MAX_TOKEN: return "MAX_TOKEN";
		case MIN_TOKEN: return "MIN_TOKEN";
		case VIEW_TOKEN: return "VIEW_TOKEN";
		case LIBRARY_TOKEN: return "LIBRARY_TOKEN";
		case SAVE_TOKEN: return "SAVE_TOKEN";
		case REV_TOKEN: return "REV_TOKEN";
		case STR_TOKEN: return "STR_TOKEN";
		case GETWD_TOKEN: return "GETWD_TOKEN";
		case GREP_TOKEN: return "GREP_TOKEN";
		case PACKAGE_TOKEN: return "PACKAGE_TOKEN";
		case SEARCH_TOKEN: return "SEARCH_TOKEN";
		case PLOT_TOKEN: return "PLOT_TOKEN";
		case RBINOM_TOKEN: return "RBINOM_TOKEN";
		case MEAN_TOKEN: return "MEAN_TOKEN";
		case DATA_TOKEN: return "DATA_TOKEN";
		case TIMES_TOKEN: return "TIMES_TOKEN";
		case LS_TOKEN: return "LS_TOKEN";
		case BY_TOKEN: return "BY_TOKEN";
		case TABLE_TOKEN: return "TABLE_TOKEN";
		case SEQ_TOKEN: return "SEQ_TOKEN";
		case NCHAR_TOKEN: return "NCHAR_TOKEN";
		case SETWD_TOKEN: return "SETWD_TOKEN";
		case EACH_TOKEN: return "EACH_TOKEN";
		case LOGICALAL_TOKEN: return "LOGICALAL_TOKEN";
		case PNORM_TOKEN: return "PNORM_TOKEN";
		case IN_TOKEN: return "IN_TOKEN";
		case COLLAPSE_TOKEN: return "COLLAPSE_TOKEN";
		case UNIQUE_TOKEN: return "UNIQUE_TOKEN";
		case WRITE_TOKEN: return "WRITE_TOKEN";
		case COR_TOKEN: return "COR_TOKEN";
		case REPLACE_TOKEN: return "REPLACE_TOKEN";
		case FALSE_TOKEN: return "FALSE_TOKEN";
		case QNORM_TOKEN: return "QNORM_TOKEN";
		case PROP_TEST_TOKEN: return "PROP_TEST_TOKEN";
		case RM_TOKEN: return "RM_TOKEN";
		case REP_TOKEN: return "REP_TOKEN";
		case LIST_TOKEN: return "LIST_TOKEN";
		case NCOL_TOKEN: return "NCOL_TOKEN";
		case FRAME_TOKEN: return "FRAME_TOKEN";
		case IS_TOKEN: return "IS_TOKEN";
		case GSUB_TOKEN: return "GSUB_TOKEN";
		case DIM_TOKEN: return "DIM_TOKEN";
		case HEAD_TOKEN: return "HEAD_TOKEN";
		case PASTE_TOKEN: return "PASTE_TOKEN";
		case CLASS_TOKEN: return "CLASS_TOKEN";
		case SUMMARY_TOKEN: return "SUMMARY_TOKEN";
		case QBINOM_TOKEN: return "QBINOM_TOKEN";
		case PATTERN_TOKEN: return "PATTERN_TOKEN";
		case GLM_TOKEN: return "GLM_TOKEN";
		case SEP_TOKEN: return "SEP_TOKEN";
		case TOLOER_TOKEN: return "TOLOER_TOKEN";
		case CHARACTER_TOKEN: return "CHARACTER_TOKEN";
		case TOUPPER_TOKEN: return "TOUPPER_TOKEN";
		case LM_TOKEN: return "LM_TOKEN";
		case PUNIF_TOKEN: return "PUNIF_TOKEN";
		case T_TEST_TOKEN: return "T_TEST_TOKEN";
		case QUNIF_TOKEN: return "QUNIF_TOKEN";
		case AOV_TOKEN: return "AOV_TOKEN";
		case C_TOKEN: return "C_TOKEN";
		case INPUT_TOKEN: return "INPUT_TOKEN";
		case SELECT_TOKEN: return "SELECT_TOKEN";
		case DNORM_TOKEN: return "DNORM_TOKEN";
		case FACTOR_TOKEN: return "FACTOR_TOKEN";
		case TRUE_TOKEN: return "TRUE_TOKEN";
		case PPOIS_TOKEN: return "PPOIS_TOKEN";
		case RPOIS_TOKEN: return "RPOIS_TOKEN";
		case DBINOM_TOKEN: return "DBINOM_TOKEN";
		case DPOIS_TOKEN: return "DPOIS_TOKEN";
		case QPOIS_TOKEN: return "QPOIS_TOKEN";
		case PBINOM_TOKEN: return "PBINOM_TOKEN";
		case FILE_TOKEN: return "FILE_TOKEN";
		case RUNIF_TOKEN: return "RUNIF_TOKEN";
		case DUNIF_TOKEN: return "DUNIF_TOKEN";

		default: printf("khikhi\n"); return "salam";
	}
}
