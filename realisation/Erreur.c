#include "Erreur.h"
#include "lex.h"
#include<stdlib.h>
#include<stdio.h>

void ERREUR(CODE_ERR error){
	switch(error){
		
		case ERREUR_ERR:
			printf("Erreur"); 
			break;	
		case ELSE_ERR:
			printf("Erreur else"); 
			break;
		case ENTRER_ERR:
			printf("Erreur ...."); 
			break;		
		case FIN_ERR:
			printf("Erreur à la fin du fichier"); 
			break;
		case IF_ERR:
			printf("Erreur à une condition IF"); 
			break;
		case NOT_ERR:
			printf("Erreur à une condition NOT"); 
			break;
		case PF_ERR:
			printf("Erreur à une Parenthese fermée"); 
			break;
		case WHILE_ERR:
			printf("Erreur à la boucle WHILE"); 
			break;
		case REPEAT_ERR:
			printf("Erreur à REPEAT" ); 
			break;
		case FOR_ERR:
			printf("Erreur à la boucle FOR"); 
			break;
		case IN_ERR:
			printf("Erreur à IN"); 
			break;
		case BREAK_ERR:
			printf("Erreur à BREAK"); 
			break;
		case PO_ERR:
			printf("Erreur à PO"); 
			break;
		case ID_ERR:
			printf("Erreur de l'identifiant"); 
			break;
		case ACCO_ERR:
			printf("Erreur à une Accolade Ouverte"); 
			break;
		case ACCF_ERR:
			printf("Erreur à une Accolade fermée" ); 
			break;
		case SEQ_ERR:
			printf("Erreur à une séquence"); 
			break;
		
		default:
			printf("ERREUR\n");
		
	}
	sym_cour.code = ERREUR_TOKEN;
	exit(0);
}
