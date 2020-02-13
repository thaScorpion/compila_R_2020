#include <stdio.h>
#include <stdlib.h>
#include "lex.h"
#include "syn.h"
#include "sem.h"
#include "erreur.h"
#include <string.h>
 


void PROGRAM() {
	Test_Symbole(PROGRAM_TOKEN, PROGRAM_ERR);
	ajouter_id(TPROG);
	Test_Symbole(ID_TOKEN, ID_ERR);     
	Test_Symbole(PV_TOKEN, PV_ERR); 
	BLOCK();  
	Test_Symbole(PT_TOKEN, PT_ERR); 
}

void Test_Symbole(CODES_LEX code, CODES_ERR COD_ERR) {
	if (sym_cour.code == code) {
		lire_sym(); 
	}
	else   
		Erreur(COD_ERR);

}

void BLOCK() { 
	CONSTS(); 
	VARS();  
	INSTS(); 
}

void CONSTS() {
	switch (sym_cour.code) { 
		case CONST_TOKEN:  
			lire_sym();
			if(!double_declaration())
				ajouter_id(TCONST);
			else
				Erreur(ERR_DOUBLE_DECLARATION);

			Test_Symbole(ID_TOKEN, ID_ERR);
			Test_Symbole(EGAL_TOKEN, EGAL_ERR);     
			Test_Symbole(NUM_TOKEN, NUM_ERR);     
			Test_Symbole(PV_TOKEN, PV_ERR);     
			while (sym_cour.code == ID_TOKEN) { 
				if (!double_declaration())
					ajouter_id(TCONST);
				else
					Erreur(ERR_DOUBLE_DECLARATION);

				lire_sym();      
				Test_Symbole(EGAL_TOKEN, EGAL_ERR);                                        
				Test_Symbole(NUM_TOKEN, NUM_ERR);      
				Test_Symbole(PV_TOKEN, PV_ERR); 
			}   
			break;                                              
			case VAR_TOKEN:  
				break;            
			case BEGIN_TOKEN:  
				break;            
			default:    
				Erreur(CONST_VAR_BEGIN_ERR); 
				break; 
	}
}


void VARS() {
	switch (sym_cour.code) {
	case VAR_TOKEN:
		lire_sym();
		if (!double_declaration())
			ajouter_id(TVAR);
		else
			Erreur(ERR_DOUBLE_DECLARATION);

		Test_Symbole(ID_TOKEN, ID_ERR);
		while (sym_cour.code == VIR_TOKEN) {
			lire_sym();
			if (!double_declaration())
				ajouter_id(TVAR);
			else
				Erreur(ERR_DOUBLE_DECLARATION);
			Test_Symbole(ID_TOKEN, ID_ERR);
		}
		Test_Symbole(PV_TOKEN, PV_ERR);
		break;
	case BEGIN_TOKEN:
		break;
	default:
		Erreur(CONST_VAR_BEGIN_ERR); 
		break;
	}
}


void INSTS() {
	Test_Symbole(BEGIN_TOKEN , BEGIN_ERR);
		INST();
		while (sym_cour.code == PV_TOKEN) {
			lire_sym();
			INST();
		}
	Test_Symbole(END_TOKEN, END_ERR);
}

void INST() {
	switch (sym_cour.code) {
		case(BEGIN_TOKEN) : 
			INSTS();
			break;
		case(ID_TOKEN):
			if (affectation_const()){
				Erreur(ERR_AFFEC_CONST);
			}

			if (use_prog()) {
				Erreur(ERR_USE_PROG);
			}

			if (undeclared())
				Erreur(ERR_UNDECLARED_VAR);
			AFFEC();
			break;
		case(IF_TOKEN):
				SI();
				break;
		case(WHILE_TOKEN):
			TANTQUE();
			break;
		case(WRITE_TOKEN):
			ECRIRE();
			break;
		case(READ_TOKEN):
			LIRE();
			break;
		default :
			Erreur(INST_ERROR);

	}
	
}

void SI() {
	Test_Symbole(IF_TOKEN, IF_ERR);
	COND();
	Test_Symbole(THEN_TOKEN, THEN_ERR);
	INST();
	if (sym_cour.code == ELSE_TOKEN) {
		lire_sym();
		INST();
	}
}
void COND() {
	EXPR();
	if (sym_cour.code == EGAL_TOKEN || sym_cour.code == INF_TOKEN || sym_cour.code == INFEG_TOKEN || sym_cour.code == SUP_TOKEN || sym_cour.code == SUPEG_TOKEN || sym_cour.code == DIFF_TOKEN)
		lire_sym();
	else
		Erreur(COMP_ERR);
	EXPR();
}

void TANTQUE() {
	Test_Symbole(WHILE_TOKEN, WHILE_ERR);
	COND();
	Test_Symbole(DO_TOKEN, DO_ERR);
	INST();
}

void LIRE() {
	Test_Symbole(READ_TOKEN, READ_ERR);
	Test_Symbole(PO_TOKEN, PO_ERR);
	if (affectation_const()) {
		Erreur(ERR_AFFEC_CONST);
	}

	if (use_prog()) {
		Erreur(ERR_USE_PROG);
	}

	if (undeclared())
		Erreur(ERR_UNDECLARED_VAR);

	Test_Symbole(ID_TOKEN, ID_ERR);
	while (sym_cour.code == VIR_TOKEN) {
		lire_sym();
		if (affectation_const()) {
			Erreur(ERR_AFFEC_CONST);
		}

		if (use_prog()) {
			Erreur(ERR_USE_PROG);
		}

		if (undeclared())
			Erreur(ERR_UNDECLARED_VAR);
		Test_Symbole(ID_TOKEN, ID_ERR);
	}
	Test_Symbole(PF_TOKEN, PF_ERR);
}

void ECRIRE() {
	Test_Symbole(WRITE_TOKEN, WRITE_ERR);
	Test_Symbole(PO_TOKEN, PO_ERR);
	EXPR();
	while (sym_cour.code == VIR_TOKEN) {
		lire_sym();
		EXPR();
	}
	Test_Symbole(PF_TOKEN, PF_ERR);
}

void AFFEC() {
	Test_Symbole(ID_TOKEN,ID_ERR);
	Test_Symbole(AFF_TOKEN, AFF_ERR);
	EXPR();
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
	if (sym_cour.code == ID_TOKEN) {
		
		if (use_prog()) {
			Erreur(ERR_USE_PROG);
		}

		if (undeclared())
			Erreur(ERR_UNDECLARED_VAR);

		lire_sym();
	}
	else if (sym_cour.code == NUM_TOKEN) {
		lire_sym();
	}

	else {
		Test_Symbole(PO_TOKEN, PO_ERR);
		EXPR();
		Test_Symbole(PF_TOKEN, PF_ERR);
	}
}
