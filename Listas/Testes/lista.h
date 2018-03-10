#ifndef PROGRAMINHA
#define PROGRAMINHA 

#include <stdlib.h>
#include <stdio.h>

typedef struct lista {

	int valor;

	struct lista* antes;

	struct lista* depois;


} lista;

lista* lst_Cria();

lista* lst_insere(lista * lst, int val);

lista* lst_remove_pos();

lista* lst_remove_val();

void lst_imprime(lista * lst);

#endif // !PROGRAMINHA
