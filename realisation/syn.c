#include <stdio.h>
#include <stdlib.h>
#include "lex.h"
#include "syn.h"
#include "Erreur.h"
#include <string.h>


int lock = 1;


void Test_Symbole(CODES_LEX code, CODE_ERR COD_ERR) {
	if (sym_cour.code == code) {
		lire_sym(); 
	}
	else   
		ERREUR(COD_ERR);
}


void INSTS() {
		INST();
		while (sym_cour.code == PV_TOKEN || sym_cour.code == ENTRER_TOKEN ) {
			lire_sym();
			INST();
		}
	if (lock) Test_Symbole(FIN_TOKEN, FIN_ERR);
}

void INST() {
	switch (sym_cour.code) {
		case ID_TOKEN:
			AFFECT1();
			break;
		case IF_TOKEN:
				SI();
				break;
		case WHILE_TOKEN:
			TANTQUE();
			break;
		case REPEAT_TOKEN:
			REPEAT();
			break;
		case FOR_TOKEN:
			POUR();
			break;
		case PRINT_TOKEN:
			ECRIRE();
			break;
		case ENTRER_TOKEN:
			break;
		case PV_TOKEN:
			break;
	}
	
}

void AFFECT1() {
		Test_Symbole(ID_TOKEN,ID_ERR);
		if ((sym_cour.code == ASSIGNF_TOKEN) || (sym_cour.code == ASSIGN2F_TOKEN) ||(sym_cour.code == EGAL_TOKEN)  ) {
			lire_sym(); 
		}
		EXPR();
}

void SI() {
	Test_Symbole(IF_TOKEN, IF_ERR);
	Test_Symbole(PO_TOKEN, PO_ERR);
	COND();
	Test_Symbole(PF_TOKEN, PF_ERR);
	while(sym_cour.code == ENTRER_TOKEN) lire_sym();
	switch(sym_cour.code){
		case BRACKETO_TOKEN:
			// accPresence= true;
			lire_sym();
			while(sym_cour.code == ENTRER_TOKEN) lire_sym();
			lock = 0;
			INSTS();
			lock = 1;
			while(sym_cour.code == ENTRER_TOKEN) lire_sym();
			Test_Symbole(BRACKETF_TOKEN, ACCF_ERR);
			while(sym_cour.code == ENTRER_TOKEN) lire_sym();


			// accPresence= false;
			if(sym_cour.code!=ENTRER_TOKEN && sym_cour.code!=ELSE_TOKEN && sym_cour.code!=FIN_TOKEN)
			{
			 	ERREUR(ENTRER_ERR);
			}
			break;
		default:
			INST();
			break;
	}
	/*if(sym_cour.code==PV_TOKEN){
		lire_sym(); 
		if(sym_cour.code==ELSE_TOKEN) ERREUR(ELSE_ERR);
	}
	if(sym_cour.code==ENTRER_TOKEN){
		lire_sym(); 
		while(sym_cour.code==ENTRER_TOKEN){
			lire_sym(); 
		}
		if(sym_cour.code==ELSE_TOKEN) ERREUR(ELSE_ERR);
	}*/
	
	switch(sym_cour.code){
		case ELSE_TOKEN:
			lire_sym(); 
			while(sym_cour.code==ENTRER_TOKEN) lire_sym(); 
			switch(sym_cour.code){
				case BRACKETO_TOKEN:
					// accPresence= true;
					lire_sym(); 
					lock = 0;
					INSTS();
					lock = 1;
					Test_Symbole(BRACKETF_TOKEN,ACCF_ERR);
					// accPresence= false;
					// if(sym_cour.code!=ENTRER_TOKEN && sym_cour.code!=FIN_TOKEN) ERREUR(ENTRER_ERR);
					break;
				default:
					INST();
					break;
			}
			break;
		default:
			break;
	}
}

void COND(){
	switch(sym_cour.code){
		case NOT_TOKEN:
			Test_Symbole(NOT_TOKEN,NOT_ERR);
			EXPR();
			break;
		default: 
			EXPR();
			if(sym_cour.code == DOUBLE_EGAL_TOKEN || sym_cour.code == DIFF_TOKEN 
			|| sym_cour.code == INF_TOKEN ||sym_cour.code == SUP_TOKEN ||
			sym_cour.code == INFEG_TOKEN ||sym_cour.code == SUPEG_TOKEN ) lire_sym();
			EXPR();
	}
}

void TANTQUE() {
	Test_Symbole(WHILE_TOKEN,WHILE_ERR);
	Test_Symbole(PO_TOKEN, PO_ERR);
	COND();
	Test_Symbole(PF_TOKEN, PF_ERR);
	while(sym_cour.code==ENTRER_TOKEN) lire_sym();
	switch(sym_cour.code){
		case BRACKETO_TOKEN:
			// accPresence= true;
			lire_sym();

			lock = 0;
			INSTS();
			lock = 1;
			Test_Symbole(BRACKETF_TOKEN,ACCF_ERR);
			// accPresence= false;
			if(sym_cour.code!=ENTRER_TOKEN && sym_cour.code!=FIN_TOKEN) ERREUR(ENTRER_ERR);
			break;
		default:
			INST();
			break;
	}
}

void REPEAT() {
	Test_Symbole(REPEAT_TOKEN,REPEAT_ERR);
	while(sym_cour.code == ENTRER_TOKEN) lire_sym(); 
	Test_Symbole(BRACKETO_TOKEN,ACCO_ERR);
	// accPresence= true;
	lock = 0;
	INSTS();
	lock = 1;
	Test_Symbole(BRACKETF_TOKEN,ACCF_ERR);
	// accPresence= false;
	if(sym_cour.code!=ENTRER_TOKEN && sym_cour.code!=FIN_TOKEN) ERREUR(ENTRER_ERR);

}

void POUR(){
	Test_Symbole(FOR_TOKEN,FOR_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	Test_Symbole(ID_TOKEN,ID_ERR);
	Test_Symbole(IN_TOKEN,IN_ERR);
	if(sym_cour.code == NUM_TOKEN ) lire_sym(); 
	else ERREUR(FOR_ERR);
	Test_Symbole(SEQ_TOKEN,SEQ_ERR);
	if(sym_cour.code == NUM_TOKEN) lire_sym(); 
	else ERREUR(FOR_ERR);
	Test_Symbole(PF_TOKEN,PF_ERR);
	while(sym_cour.code == ENTRER_TOKEN) lire_sym(); 
	switch(sym_cour.code){
		case BRACKETO_TOKEN:
			// accPresence= true;
			Test_Symbole(BRACKETO_TOKEN,ACCO_ERR);
			lock = 0;
			INSTS();
			lock = 1;
			Test_Symbole(BRACKETF_TOKEN,ACCF_ERR);
			// accPresence= false;
			if(sym_cour.code!=ENTRER_TOKEN && sym_cour.code!=FIN_TOKEN) ERREUR(ENTRER_ERR);
			break;
		default:
			INST();
			break;
	}
}

void ECRIRE() {
	switch(sym_cour.code)
	{
		case (PRINT_TOKEN):
			lire_sym();
			Test_Symbole(PO_TOKEN, PO_ERR);
			EXPR();
			Test_Symbole(PF_TOKEN, PF_ERR);
			break;
	}
}




void EXPR() {
	TERM();
	while (sym_cour.code == PLUS_TOKEN || sym_cour.code == MOINS_TOKEN) {
		lire_sym();
		TERM();
	}
}

void TERM() {
	
	FACT();
	while (sym_cour.code == MULT_TOKEN || sym_cour.code == DIV_TOKEN) {
		lire_sym();
		FACT();
	}

}

void FACT() {
	
	switch(sym_cour.code){
		case ID_TOKEN:
			lire_sym();
			break;
		case NUM_TOKEN:
			lire_sym();
			break;
		case PO_TOKEN:
			Test_Symbole(PO_TOKEN,PO_ERR);
			EXPR();
			Test_Symbole(PF_TOKEN,PF_ERR);
			break;
		default:
			ERREUR(ERREUR_ERR);
			break;
	}
}











