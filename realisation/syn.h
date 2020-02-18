#ifndef ANALYSEUR_SYNTHAXIQUE_H
#define ANALYSEUR_SYNTHAXIQUE_H

#include "Erreur.h"
#include "lex.h"


//declaration 

void Test_Symbole(CODES_LEX code,CODE_ERR error);

void INSTS();
void INST();
void AFFECT1();
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
