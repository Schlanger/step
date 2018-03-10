#include <stdio.h>

int main()
{
	int * v = NULL;
	int tam;

	printf("Digite o tamnho do vetor: ");
	scanf("%d", &tam); 

	v = (int*)malloc(tam*sizeof(int));

	if (v == NULL)
	{
		printf("Espaco de memoria insuficiente\n");
		return 1;
	}

	for (int i = 0; i < tam; i++)
	{
		printf("\nDigite o numero %d: \n", i + 1);
		scanf("%d", v+i);
	}

	printf("\nO vetor ficou:\n\n");

	for (int i = 0; i < tam; i++)
		printf("%d\n", v[i]);

	free(v);
	v = NULL;

	return 0;

}