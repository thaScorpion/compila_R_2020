#pragma once	

typedef enum {
	TPROG,
	TCONST,
	TVAR
} TSYM;



typedef struct {
	char nom[20];
	TSYM TIDF;
} T_TAB_IDF;

int affectation_const();

int use_prog();
	
int undeclared();
