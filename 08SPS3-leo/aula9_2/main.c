#include <stdio.h>

void percorre_matriz(int * const m, int tam, void(*f)(int));
void percorre_matriz_1(int * const m, int tam, int target, int(*f)(int,int));
void imprime_1(int i);
void imprime_2(int i);
void par_impar(int i);
int alvo(int a, int b);

int main() 
{
	int matriz[] = {-7,13,19,213,2};

	percorre_matriz(matriz, sizeof(matriz) / sizeof(int), imprime_1);
	printf("\n****************************************************************************\n");
	percorre_matriz(matriz, sizeof(matriz) / sizeof(int), imprime_2);
	printf("\n****************************************************************************\n");
	percorre_matriz(matriz, sizeof(matriz) / sizeof(int), par_impar);
	printf("\n****************************************************************************\n");
	percorre_matriz_1(matriz, sizeof(matriz) / sizeof(int), 213, alvo);

	return 0;
}

void percorre_matriz(int * const m, int tam, void(*f)(int))
{
	int * end = m + tam;

	for (int * i = m; i != end; i++)
		f(*i);
}

void percorre_matriz_1(int * const m, int tam, int target, int(*f)(int, int))
{
	int * end = m + tam;

	for (int * i = m; i != end; i++)
		if (f(*i, target) == 1)
			break;
}

void imprime_1(int i)
{
	printf("%d ", i);
}
void imprime_2(int i)
{
	printf("\nO valor eh %d\n", i);
}

void par_impar(int i)
{
	i % 2 == 0 ? printf("\nO valor %d eh par\n", i) : printf("\nO valor %d nao eh par\n", i);
}

int alvo(int a, int b)
{
	if (a == b)
	{
		printf("\nAlvo %d encontrado!!\n", b);
		return 1;
	}

	printf("\nAlvo %d nao encontrado...\n", b);
	return 0;
}
