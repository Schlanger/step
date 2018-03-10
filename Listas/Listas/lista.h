#ifndef PROGRAMINHA
#define PROGRAMINHA 

#include <stdlib.h>
#include <stdio.h>

typedef struct lista {

	int valor;

	int pos;

	struct lista* antes;

	struct lista* depois;


} lista;

//retorna uma lista criada, retorna NULL se n foi possivel alocar
lista* lst_Cria();

//insere um valor dentro da lista e retorna a lista preenchida, retorna NULL se n foi possivel alocar
lista* lst_insere(lista * lst, int val);

//remove um valor da lista e retorna esse valor, caso n exista na lista retorna -1
int lst_remove_pos(lista * lst, int index);

//remove uma posiçao da lista e retorna essa posiçao, caso n exista na lista retorna -1
int lst_remove_val(lista * lst, int val);

//Retorna a lista de acordo com a posiçao, caso a posiçao nao exista retorna NULL
lista * get_listaInd(lista * lst, int index);

//Retorna a lista de acordo com o valor, caso o valor nao exista retorna NULL
lista * get_listaVal(lista * lst, int val);

//Deleta a existencia da lista
void deleta_lista(lista * lst);

//Imprime a lista 
void lst_imprime(lista * lst);

#endif // !PROGRAMINHA
