#pragma once
typedef enum {
	ERR_CAR_INC,
	ERR_FICH_VID,
	ERR_ID_LONG,
	PROGRAM_ERR,
	ID_ERR,
	PV_ERR,
	PT_ERR,
	EGAL_ERR,
	NUM_ERR,
	CONST_VAR_BEGIN_ERR,
	VIR_ERR,
	BEGIN_ERR,
	END_ERR,
	PO_ERR,
	PF_ERR,
	AFF_ERR,
	OPERATOR_TERM_ERR,
	OPERATOR_FACT_ERR,
	INST_ERROR,
	IF_ERR,
	THEN_ERR,
	COMP_ERR,
	WHILE_ERR,
	DO_ERR,
	READ_ERR,
	WRITE_ERR,
	ERR_DOUBLE_DECLARATION,
	ERR_AFFEC_CONST,
	ERR_USE_PROG,
	ERR_UNDECLARED_VAR,

} CODES_ERR;

typedef  struct { CODES_ERR  code; char mes[40]; }   ERROR;
extern ERROR	MES_ERR[];
void Erreur(CODES_ERR ERR);
