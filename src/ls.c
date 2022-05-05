#include "header/lex.h"
#include "header/token.h"
#include "header/ls.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
init(LS_t **ls)
{
	(*ls) = malloc(sizeof(LS_t));
	(*ls)->lex = malloc(sizeof(Lex_t));
	(*ls)->lex->i = 1;
}

void
setstdin(LS_t **ls, char *stdin)
{
	(*ls)->lex->stdin = malloc(strlen(stdin) * sizeof(char));
	strcpy((*ls)->lex->stdin, stdin);
}

void
ls() 
{
	LS_t *ls;
	init(&ls);

	setstdin(&ls, "int8 var, varB :3\n10;");

	//printf("%s\n", ls->lex->stdin);
	//Token_t *tk = lex(&ls->lex);
	parser(&ls->lex);

	//printf("%s\n", ls->lex->stdin);
}