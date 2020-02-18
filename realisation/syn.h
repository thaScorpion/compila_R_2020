#ifndef ANALYSEUR_SYNTHAXIQUE_H
#define ANALYSEUR_SYNTHAXIQUE_H

<<<<<<< HEAD
#include "Erreur.h"
#include "lex.h"
=======

#include "analyseur_lexical.h"
>>>>>>> 5c3b0fd3350a88af7c6427bfad954d56d8b6bc1f


//declaration 

<<<<<<< HEAD
void Test_Symbole(CODES_LEX code,CODE_ERR error);

void INSTS();
void INST();
void AFFECT1();
=======




void Test_Symbole(CODE_LEX code,CODE_ERR error);

void INSTS();
void INST();
void AFFEC1();
>>>>>>> 5c3b0fd3350a88af7c6427bfad954d56d8b6bc1f
void SI();
void COND();
void TANTQUE();
void REPEAT();
void POUR();
void ECRIRE();

void EXPR();
void TERM();
void FACT();

<<<<<<< HEAD
=======





>>>>>>> 5c3b0fd3350a88af7c6427bfad954d56d8b6bc1f
#endif
