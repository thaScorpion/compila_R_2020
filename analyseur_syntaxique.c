#include "analyseur_syntaxique.h"
#include "errors.h"



void Test_Symbole(CODE_LEX code,CODE_ERR error){
	if(SYM_COUR.CODE==code){
		SYM_PREC_ID.CODE = SYM_COUR.CODE;
		strcpy(SYM_PREC_ID.nom,SYM_COUR.nom);
		Sym_Suiv();
	}else{
		ERREUR(error);
	}
}

void INSTS(){
	INST();
	while(SYM_COUR.CODE==PV_TOKEN || SYM_COUR.CODE==ENTRER_TOKEN || SYM_COUR.CODE==COMM_TOKEN){
		SYM_PREC.CODE = SYM_COUR.CODE;
		Sym_Suiv();
		INST();
	}
}


void INST(){
	switch(SYM_COUR.CODE){
		case ID_TOKEN:
			AFFEC1();
			break;
		case INT_TOKEN:
		case FLOAT_TOKEN:
			AFFEC2();
			break;
		case CHAINE_TOKEN:
			AFFEC3();
			break;
		case PO_TOKEN:
			AFFEC2();
			break;
		case IF_TOKEN:
			SI();
			break;
		case WHILE_TOKEN:
			TANTQUE();
			break;
		case REPEAT_TOKEN:
			REPETER();
			break;	
		case FOR_TOKEN:
			POUR();
			break;	
		case WRITE_TOKEN:
			ECRIRE();
			break;
		case READ_TOKEN:
			LIRE();
			break;
		case ENTRER_TOKEN:
			break;
		case COMM_TOKEN:
			break;
		case PV_TOKEN:
			pvTest();
			break;
		case BREAK_TOKEN:
			Sym_Suiv();
			break;
		case EOF_TOKEN:
			break;
		default:
			break;
	}
}
	
void AFFEC1(){
	//CHERCHER_SYM(SYM_COUR.nom,OAFFEC);
	Test_Symbole(ID_TOKEN,ID_ERR);
	strcpy(nom_symbol2,nom_symbol);
	if(SYM_COUR.CODE==AFFOP1_TOKEN){
		int t = CHERCHER_SYM(nom_symbol2,OAFFEC);
		Test_Symbole(AFFOP1_TOKEN,AFF_ERR);
		Test_Symbole(ID_TOKEN,ID_ERR);
		AJOUTER_SYM(nom_symbol,t);
	}else if(SYM_COUR.CODE==AFFOP_TOKEN){
		Test_Symbole(AFFOP_TOKEN,AFF_ERR);
		if(SYM_COUR.CODE!=READ_TOKEN){
			if(SYM_COUR.CODE!=CHAINE_TOKEN) EXPR();
			else{
				Test_Symbole(CHAINE_TOKEN,CHAINE_ERR);
				AJOUTER_SYM(nom_symbol2,TCHR);
			}
		}
		else LIRE();
	}else if(SYM_COUR.CODE==AFFOP2_TOKEN){
		Test_Symbole(AFFOP2_TOKEN,AFF_ERR);
		if(SYM_COUR.CODE!=READ_TOKEN){
			if(SYM_COUR.CODE!=CHAINE_TOKEN) EXPR();
			else{
				Test_Symbole(CHAINE_TOKEN,CHAINE_ERR);
				AJOUTER_SYM(nom_symbol2,TCHR);
			}
		}
		else LIRE();
	}else{
		int t1 = CHERCHER_SYM(nom_symbol2,OAFFEC);
		ECRIRE2();
		int t2 = CHERCHER_SYM(nom_symbol2,OAFFEC);
		Test_Symbole(AFFOP1_TOKEN,AFF_ERR);
		Test_Symbole(ID_TOKEN,ID_ERR);
		AJOUTER_SYM(nom_symbol,t2);
		AJOUTER_SYM(nom_symbol2,t1);

	}
	
}

void AFFEC2(){
	int t1 = CHERCHER_SYM(nom_symbol2,OAFFEC);
	EXPR();
	Test_Symbole(AFFOP1_TOKEN,AFF_ERR);
	Test_Symbole(ID_TOKEN,ID_ERR);
	AJOUTER_SYM(nom_symbol,type_symbole);
	AJOUTER_SYM(nom_symbol2,t1);
}

void AFFEC3(){
	Test_Symbole(CHAINE_TOKEN,CHAINE_ERR);
	Test_Symbole(AFFOP1_TOKEN,AFF_ERR);
	Test_Symbole(ID_TOKEN,ID_ERR);
	AJOUTER_SYM(nom_symbol,TCHR);
}

void SI(){
	Test_Symbole(IF_TOKEN,IF_ERR);
	COND();
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	switch(SYM_COUR.CODE){
		case ACCO_TOKEN:
			accPresence= true;
			Sym_Suiv();
			INSTS();
			Test_Symbole(ACCF_TOKEN,ACCF_ERR);
			accPresence= false;
			if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=ELSE_TOKEN && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);
			break;
		default:
			INST();
			break;
	}
	if(SYM_COUR.CODE==PV_TOKEN){
		Sym_Suiv();
		if(SYM_COUR.CODE==ELSE_TOKEN) ERREUR(ELSE_ERR);
	}
	if(SYM_COUR.CODE==ENTRER_TOKEN){
		Sym_Suiv();
		while(SYM_COUR.CODE==ENTRER_TOKEN){
			Sym_Suiv();
		}
		if(SYM_COUR.CODE==ELSE_TOKEN) ERREUR(ELSE_ERR);
	}
	
	switch(SYM_COUR.CODE){
		case ELSE_TOKEN:
			Sym_Suiv();
			while(SYM_COUR.CODE==ENTRER_TOKEN) Sym_Suiv();
			switch(SYM_COUR.CODE){
				case ACCO_TOKEN:
					accPresence= true;
					Sym_Suiv();
					INSTS();
					Test_Symbole(ACCF_TOKEN,ACCF_ERR);
					accPresence= false;
					if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);
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
	Test_Symbole(PO_TOKEN,PO_ERR);
	switch(SYM_COUR.CODE){
		case NOT_TOKEN:
			Test_Symbole(NOT_TOKEN,NOT_ERR);
			EXPR();
			Test_Symbole(PF_TOKEN,PF_ERR);
			break;
		default: 
			EXPR();
			if(SYM_COUR.CODE == EGAL_TOKEN || SYM_COUR.CODE == DIFF_TOKEN 
			|| SYM_COUR.CODE == INF_TOKEN ||SYM_COUR.CODE == SUP_TOKEN ||
			SYM_COUR.CODE == INFG_TOKEN ||SYM_COUR.CODE == SUPG_TOKEN ) Sym_Suiv();
			else if (SYM_COUR.CODE == PF_TOKEN){
				Sym_Suiv();
				break;
			}else{
				ERREUR(PF_ERR);
			}
			if(SYM_COUR.CODE != PF_TOKEN){
				EXPR();
				Test_Symbole(PF_TOKEN,PF_ERR);
			}
			break;
	}
}

void TANTQUE(){
	Test_Symbole(WHILE_TOKEN,WHILE_ERR);
	COND();
	while(SYM_COUR.CODE==ENTRER_TOKEN) Sym_Suiv();
	switch(SYM_COUR.CODE){
		case ACCO_TOKEN:
			accPresence= true;
			Sym_Suiv();
			INSTS();
			Test_Symbole(ACCF_TOKEN,ACCF_ERR);
			accPresence= false;
			if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);
			break;
		default:
			INST();
			break;
	}
}


void REPETER(){
	Test_Symbole(REPEAT_TOKEN,REPEAT_ERR);
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	Test_Symbole(ACCO_TOKEN,ACCO_ERR);
	accPresence= true;
	INSTS();
	Test_Symbole(ACCF_TOKEN,ACCF_ERR);
	accPresence= false;
	if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);

}

void POUR(){
	Test_Symbole(FOR_TOKEN,FOR_ERR);
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	Test_Symbole(PO_TOKEN,PO_ERR);
	Test_Symbole(ID_TOKEN,ID_ERR);
	Test_Symbole(IN_TOKEN,IN_ERR);
	if(SYM_COUR.CODE == INT_TOKEN || SYM_COUR.CODE == FLOAT_TOKEN || SYM_COUR.CODE == ID_TOKEN) Sym_Suiv();
	else ERREUR(FOR_ERR);
	Test_Symbole(SEQ_TOKEN,SEQ_ERR);
	if(SYM_COUR.CODE == INT_TOKEN || SYM_COUR.CODE == FLOAT_TOKEN || SYM_COUR.CODE == ID_TOKEN) Sym_Suiv();
	else ERREUR(FOR_ERR);
	Test_Symbole(PF_TOKEN,PF_ERR);
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	switch(SYM_COUR.CODE){
		case ACCO_TOKEN:
			accPresence= true;
			Test_Symbole(ACCO_TOKEN,ACCO_ERR);
			INSTS();
			Test_Symbole(ACCF_TOKEN,ACCF_ERR);
			accPresence= false;
			if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);
			break;
		default:
			INST();
			break;
	}
}

void ECRIRE(){
	Test_Symbole(WRITE_TOKEN,WRITE_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	EXPR();
	Test_Symbole(PF_TOKEN,PF_ERR);
}

void LIRE(){
	Test_Symbole(READ_TOKEN,READ_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	Test_Symbole(PF_TOKEN,ID_ERR);
	/*CHERCHER_SYM(SYM_PREC.nom,OLIRE);
	while(SYM_COUR.CODE==VIR_TOKEN){
		Sym_Suiv();
		Test_Symbole(ID_TOKEN,ID_ERR);
		CHERCHER_SYM(SYM_PREC.nom,OLIRE);
	}
	Test_Symbole(PF_TOKEN,PF_ERR);*/
}


void EXPR(){
	TERM();
	TYPE_SYM_PREC = TYPE_SYM_PREC_ID;
	while(SYM_COUR.CODE==PLUS_TOKEN||SYM_COUR.CODE==MOINS_TOKEN){
		Sym_Suiv();
		TERM();
	}
	TYPE_SYM_PREC = -1;
}

void TERM(){
	FACT();
	TYPE_SYM_PREC = TYPE_SYM_PREC_ID;
	while(SYM_COUR.CODE==MULT_TOKEN||SYM_COUR.CODE==DIV_TOKEN || SYM_COUR.CODE==DIVENT_TOKEN || SYM_COUR.CODE==RES_TOKEN){
		Sym_Suiv();
		FACT();
	}
}

void FACT(){
	if(TYPE_SYM_PREC == TCHR && TYPE_SYM_PREC!= TYPE_SYM_PREC_ID){
		printf(" '%s' ERROR COMPATIBILITE at ligne %d",SYM_COUR.nom,numLigne);
		exit(0);
	}
	switch(SYM_COUR.CODE){
		case ID_TOKEN:
			Test_Symbole(ID_TOKEN,ID_ERR);
			printf("%s\n",nom_symbol);
			printf("%s\n",nom_symbol2);
			int r = CHERCHER_SYM(nom_symbol,OAFFEC);
			if (r != -1)
			{
				if (CHERCHER_SYM(nom_symbol2,OALL)==TFLT)
				{
					AJOUTER_SYM(nom_symbol2,TFLT);
				}
				else AJOUTER_SYM(nom_symbol2,r);
			}
			
			break;
		
		case INT_TOKEN:
			printf("test int : %s\n",SYM_COUR.nom);
			if(type_symbole != TFLT) type_symbole = TINT;
			Test_Symbole(INT_TOKEN,NUM_ERR);
			AJOUTER_SYM(nom_symbol2,(CHERCHER_SYM(nom_symbol2,OALL)==TFLT)? TFLT : TINT);
			//TYPE_SYM_PREC_ID = TINT;
			break;
		case FLOAT_TOKEN:
			type_symbole = TFLT;
			Test_Symbole(FLOAT_TOKEN,NUM_ERR);
			AJOUTER_SYM(nom_symbol2,type_symbole);
			//TYPE_SYM_PREC_ID = TFLT;
			break;
		case PO_TOKEN:
			Test_Symbole(PO_TOKEN,PO_ERR);
			EXPR();
			Test_Symbole(PF_TOKEN,PF_ERR);
			break;
		case MIN_TOKEN:
			MIN();
			break;
		case MAX_TOKEN:
			MAX();
			break;
		default:
			ERREUR(ERREUR_ERR);
			break;
	}
}

void PREMIER_SYM(){
    numLigne = 1;
    FLOAT = 0;
    accPresence = false;
    SAME_TYPE_EXPR = true;
    indice = 0;
	Lire_Car();
	Sym_Suiv();
}

void pvTest(){
	if((SYM_PREC.CODE == PV_TOKEN || SYM_PREC.CODE == ENTRER_TOKEN || SYM_PREC.CODE == 0 ) && accPresence==false)
		ERREUR(PV_ERR);
}


void ECRIRE2(){
	int operationSYM = 0;
	while(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=PV_TOKEN && SYM_COUR.CODE != AFFOP1_TOKEN){
	switch(SYM_COUR.CODE){
		case PLUS_TOKEN:
			operationSYM++;
			Sym_Suiv();
			break;
		case MOINS_TOKEN:
			operationSYM++;
			Sym_Suiv()
			break;
		case MULT_TOKEN:
			operationSYM++;
			Sym_Suiv();
			break;
		case DIV_TOKEN:
			operationSYM++;
			Sym_Suiv();
			break;
		case DIVENT_TOKEN:
			operationSYM++;
			Sym_Suiv();
			break;
		case RES_TOKEN:
			operationSYM++;
			Sym_Suiv();
			break;
		case ID_TOKEN:
			CHERCHER_SYM(nom_symbol,OAFFEC);
			operationSYM--;
			Sym_Suiv();
			break;
		case INT_TOKEN:
			operationSYM--;
			Sym_Suiv();
			break;
		case FLOAT_TOKEN:
			AJOUTER_SYM(nom_symbol2,TFLT);
			operationSYM--;
			Sym_Suiv();
			break;
		case PO_TOKEN:
			EXPR();
			break;
		case ENTRER_TOKEN:
			break;
		case PV_TOKEN:
			break;
		default:
			ERREUR(WRITE_ERR);
			break;
	}
	}
	if(operationSYM>=1 && operationSYM<0) ERREUR(WRITE_ERR);
}



