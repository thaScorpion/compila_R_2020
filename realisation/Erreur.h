#ifndef ERRORS_H
#define ERRORS_H

#include "global.h"

typedef enum{
	IF_ERR,
	WHILE_ERR,
	REPEAT_ERR,
	FOR_ERR,
	IN_ERR,
	BREAK_ERR,
	PT_ERR,
	FIN_ERR,
	PO_ERR,
	PF_ERR,
	ID_ERR,
	NOT_ERR,
	ACCO_ERR,
	ACCF_ERR,
	SEQ_ERR

}CODE_ERR;

void ERREUR(CODE_ERR error);

#endif
