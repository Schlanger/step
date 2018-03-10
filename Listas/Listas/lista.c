#include "lista.h"

lista* lst_Cria() 
{

	lista * novo = (lista *)malloc(sizeof(lista));

	if (novo == NULL)
		return NULL;

	novo->antes = NULL;
	novo->depois = NULL;

	return novo;
	
}

lista* lst_insere(lista * lst, int val)
{

	if (lst->antes == lst->depois && lst->antes == NULL)
	{
		lst->valor = val;
		lst->antes = lst;
		lst->depois = lst->antes;
		lst->pos = 1;
	}
	else
	{
		lista * novo = lst_Cria(); 

		if (novo == NULL)
			return NULL;

		novo->valor = val;
		novo->pos = lst->antes->pos + 1;

		lst->antes->depois = novo;
		novo->antes = lst->antes;
		novo->depois = lst;
		lst->antes = novo;

	}

	return lst;
}

int lst_remove_pos(lista * lst, int index)
{
	lista * aux;
	int val;

	aux = get_listaInd( lst, index);

	if (aux == NULL)
		return -1;

	val = aux->valor;
	
	deleta_lista(aux);

	return val;
}

int lst_remove_val(lista * lst, int val)
{
	lista * aux;
	int index;

	aux = get_listaVal(lst, val);

	if (aux == NULL)
		return -1;

	index = aux->pos;

	deleta_lista(aux);

	return index;
}

lista * get_listaInd(lista * lst, int index)
{
	lista * aux = lst;

	do
	{

		if (aux->pos == index)
			return aux;

		aux = aux->depois;

	} while (aux != lst);

	return NULL;
}

lista * get_listaVal(lista * lst, int val)
{
	lista * aux = lst;

	do
	{

		if (aux->valor== val)
			return aux;

		aux = aux->depois;

	} while (aux != lst);

	return NULL;
}

void deleta_lista(lista * lst)
{
	if (lst != lst->antes)
	{
		lst->antes->depois = lst->depois;
		lst->depois->antes = lst->antes;
	}

	free(lst);
}

void lst_imprime(lista * lst)
{
	lista * aux = lst;

	do
	{

		printf("%d   %d\n", aux->valor, aux->pos);
		aux = aux->depois;

	} while (aux != lst);
}



