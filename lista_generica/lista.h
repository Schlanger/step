#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct lista {

	struct lista* antes;

	void * elemento;
	int tam; //tamanho em bytes do vetor elemento

	struct lista* depois;


} lista;

//retorna uma lista criada, retorna NULL se n foi possivel alocar
lista* lst_Cria();

//insere um elemento dentro da lista e retorna a lista preenchida, retorna NULL se n foi possivel alocar no elemento
lista* lst_insere(lista * lst, void * ele, int tam);

//remove um elemento da lista e retorna 1 caso tenha encontrado, caso n exista na lista retorna 0
int lst_remove(lista * lst, void * ele, int tam, int(*cmp)(void * e1, int tame1, void * e2, int tame2));

//Retorna a lista de acordo com o elemento buscado, caso a posiçao nao exista retorna NULL
lista * get_lista_busca(lista * lst, void * ele, int tam, int(*cmp)(void * e1, int tame1, void * e2, int tame2));

//Deleta a existencia da lista
void deleta_lista(lista * lst);

//Imprime a lista 
void lst_imprime(lista * lst);

#endif 
