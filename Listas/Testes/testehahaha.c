#include "lista.h"

int main()
{
	lista * lst;
	int val, pos;

	lst = lst_Cria();

	lst = lst_insere(lst, 11);
	lst = lst_insere(lst, 12);
	lst = lst_insere(lst, 13);
	lst = lst_insere(lst, 14);
	lst = lst_insere(lst, 15);
	lst = lst_insere(lst, 16);

	lst_imprime(lst);

	printf("------------------------------------------------------------------------");

	val = lst_remove_pos(lst, 4);

	printf("\nRemovido valor %d\n",val);

	lst_imprime(lst);

	printf("------------------------------------------------------------------------");

	pos = lst_remove_val(lst, 16);

	printf("\nRemovido posicao %d\n", pos);

	lst_imprime(lst);

	printf("------------------------------------------------------------------------");
}