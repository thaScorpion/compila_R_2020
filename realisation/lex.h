#ifndef LEX
#define LEX
#include <stdio.h>

typedef enum {
	FIN_TOKEN,
	IF_TOKEN,
	ELSE_TOKEN,
	WHILE_TOKEN,
	READ_TOKEN,
	PV_TOKEN,
	PLUS_TOKEN,
	MOINS_TOKEN,
	MULT_TOKEN,
	DIV_TOKEN,
	VIR_TOKEN,
	AFF_TOKEN,
	EGAL_TOKEN,
	DOUBLE_EGAL_TOKEN,
	INF_TOKEN,
	INFEG_TOKEN,
	SUP_TOKEN,
	SUPEG_TOKEN,
	DIFF_TOKEN,
	PO_TOKEN,
	PF_TOKEN,
	ID_TOKEN,
	NUM_TOKEN,
	CHAINE_TOKEN,
	ERREUR_TOKEN,

	PERCENT_TOKEN,
	CROCHETO_TOKEN,
	CROCHETF_TOKEN,
	QUOTE_TOKEN,
	BRACKETO_TOKEN,
	BRACKETF_TOKEN,
	ASSIGNO_TOKEN,
	ASSIGN2O_TOKEN,
	ASSIGNF_TOKEN,
	ASSIGN2F_TOKEN,
	DOLLAR_TOKEN,
	TILD_TOKEN,
	_LIBPATHS_TOKEN,
	ROUND_TOKEN,
	HIST_TOKEN,
	SIGHNIF_TOKEN,
	LOG_TOKEN,
	NA_TOKEN,
	NUMERIC_TOKEN,
	PRINT_TOKEN,
	NULL_TOKEN,
	LOAD_TOKEN,
	SORT_TOKEN,
	BREAKS_TOKEN,
	FOR_TOKEN,
	CUT_TOKEN,
	RNORM_TOKEN,
	NROW_TOKEN,
	HELP_TOKEN,
	EXP_TOKEN,
	AS_TOKEN,
	MATRIX_TOKEN,
	INSTALL_TOKEN,
	PAIRWISE_T_TEST_TOKEN,
	MAX_TOKEN,
	MIN_TOKEN,
	VIEW_TOKEN,
	LIBRARY_TOKEN,
	SAVE_TOKEN,
	REV_TOKEN,
	STR_TOKEN,
	GETWD_TOKEN,
	GREP_TOKEN,
	PACKAGE_TOKEN,
	SEARCH_TOKEN,
	PLOT_TOKEN,
	RBINOM_TOKEN,
	MEAN_TOKEN,
	DATA_TOKEN,
	TIMES_TOKEN,
	LS_TOKEN,
	BY_TOKEN,
	TABLE_TOKEN,
	SEQ_TOKEN,
	NCHAR_TOKEN,
	SETWD_TOKEN,
	EACH_TOKEN,
	LOGICALAL_TOKEN,
	PNORM_TOKEN,
	IN_TOKEN,
	COLLAPSE_TOKEN,
	UNIQUE_TOKEN,
	WRITE_TOKEN,
	COR_TOKEN,
	REPLACE_TOKEN,
	FALSE_TOKEN,
	QNORM_TOKEN,
	PROP_TEST_TOKEN,
	RM_TOKEN,
	REP_TOKEN,
	LIST_TOKEN,
	NCOL_TOKEN,
	FRAME_TOKEN,
	IS_TOKEN,
	GSUB_TOKEN,
	DIM_TOKEN,
	HEAD_TOKEN,
	PASTE_TOKEN,
	CLASS_TOKEN,
	SUMMARY_TOKEN,
	QBINOM_TOKEN,
	PATTERN_TOKEN,
	GLM_TOKEN,
	SEP_TOKEN,
	TOLOER_TOKEN,
	CHARACTER_TOKEN,
	TOUPPER_TOKEN,
	LM_TOKEN,
	PUNIF_TOKEN,
	T_TEST_TOKEN,
	QUNIF_TOKEN,
	AOV_TOKEN,
	C_TOKEN,
	INPUT_TOKEN,
	SELECT_TOKEN,
	DNORM_TOKEN,
	FACTOR_TOKEN,
	TRUE_TOKEN,
	PPOIS_TOKEN,
	RPOIS_TOKEN,
	DBINOM_TOKEN,
	DPOIS_TOKEN,
	QPOIS_TOKEN,
	PBINOM_TOKEN,
	FILE_TOKEN,
	RUNIF_TOKEN,
	DUNIF_TOKEN,



} CODES_LEX;


typedef struct sym_cour {
	int code;
	char nom[1000];
	int val;
}SYM_COUR;

extern SYM_COUR sym_cour;
extern char car_cour; 
extern FILE* fichier;

void getNextChar();
void lire_sym();
void lire_mot();
void lire_num();
void lire_special();
void lire_com();
void lire_chaine();
void debut();
const char* getCodeName(CODES_LEX code);

#endif // 



