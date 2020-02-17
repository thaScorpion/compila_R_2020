#ifndef ANALYSEUR_SYNTHAXIQUE_H
#define ANALYSEUR_SYNTHAXIQUE_H


#include "analyseur_lexical.h"


//declaration 





void Test_Symbole(CODE_LEX code,CODE_ERR error);

void INSTS();
void INST();
void AFFEC1();
void SI();
void COND();
void TANTQUE();
void REPEAT();
void POUR();
void ECRIRE();

void EXPR();
void TERM();
void FACT();






#endif
