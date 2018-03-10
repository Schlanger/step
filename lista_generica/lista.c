#include "lista.h"

lista* lst_Cria()
{

	lista * novo = (lista *)malloc(sizeof(lista));

	if (novo == NULL)
		return NULL;

	novo->elemento = NULL;
	novo->antes = NULL;
	novo->depois = NULL;

	return novo;

}

lista* lst_insere(lista * lst, void * ele, int tam)
{

	if (lst->antes == lst->depois && lst->antes == NULL)
	{
		lst->elemento = (void*) malloc(tam);

		if (lst->elemento == NULL)
			return lst;

		memcpy(lst->elemento, ele, tam);

		lst->antes = lst;
		lst->depois = lst->antes;
	}
	else
	{
		lista * novo = lst_Cria();

		if (novo == NULL)
			return NULL;

		lst->elemento = (void*)malloc(tam);

		if (lst->elemento == NULL)
			return lst;

		memcpy(lst->elemento, ele, tam);

		lst->antes->depois = novo;
		novo->antes = lst->antes;
		novo->depois = lst;
		lst->antes = novo;

	}

	return lst;
}

int lst_remove(lista * lst, void * ele, int tam, int(*cmp)(void * e1, int tame1, void * e2, int tame2))
{
	lista * aux;

	aux = get_lista_busca(lst, ele, tam, cmp);

	if (aux == NULL)
		return 0;

	deleta_lista(aux);

	return 1;
}

lista * get_lista_busca(lista * lst, void * ele, int tam, int(*cmp)(void * e1, int tame1, void * e2, int tame2))
{
	lista * aux = lst;

	do
	{

		if (cmp(lst,lst->tam,ele,tam) == 0)
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

	free(lst->elemento);
	free(lst);
}

void lst_imprime(lista * lst, void (*imprime)(void * ele, int tam))
{
	lista * aux = lst;

	do
	{

		imprime(aux->elemento, aux->tam);
		aux = aux->depois;

	} while (aux != lst);
}



