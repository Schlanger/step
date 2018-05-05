#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define T 10

int main() {

	char cont1[T];
	memset(cont1, '\0', T);
	printf("\nDigite o nome da pessoa 1: ");
	gets_s(cont1, T - 1);
	printf("%s\n", cont1);

	int i;
	printf("\nDigite um numero: ");
	scanf("%d", &i);
	printf("%d\n", i);

	char cont2[T];
	memset(cont2, '\0', T);
	printf("\nDigite o nome da pessoa 2: ");
	gets_s(cont2, T - 1);
	printf("%s\n", cont2);

	return 0;

}

