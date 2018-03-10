#include "itf.h"

int add_pessoas(lista * no, int * qtd)
{
	char n;
	int conf;

	pessoa * p = NULL;
	id _id;
	idade _idade;
	char nome[TAM_NOME];
	char cep[TAM_CEP];
	salario _salario;

	printf("\nDeseja cadastrar uma nova pessoa? (digite 's' ou 'S' para sim ou 'n' ou 'N' para nao)");
	scanf("%c", &n);

	getchar();

	while (n == 's' || n == 'S')
	{

		printf("\nDigite o id da pessoa:");
		scanf("%u", &_id);

		getchar();

		printf("\nDigite o nome da pessoa:");
		scanf(" %[^\n]s", nome);

		getchar();

		printf("\nDigite a idade da pessoa:");
		scanf("%u", &_idade);

		getchar();

		printf("\nDigite o cep da pessoa:");
		scanf(" %s", cep);

		getchar();

		printf("\nDigite o salario da pessoa:");
		scanf("%lf", &_salario);

		getchar();

		p = (pessoa *) malloc(sizeof(pessoa));
		conf = cria_pessoa(p,_id,nome,_idade,_salario,cep);

		if (conf != 1)
			return conf;

		no = lst_insere(no,(void*)p,sizeof(pessoa));

		free(p);

		if (no == NULL)
			return -1;

		(*qtd)++;

		printf("\nDeseja cadastrar uma nova pessoa? (digite 's' ou 'S' para sim ou 'n' ou 'N' para nao)");
		scanf("%c", &n);
		
	}

	return 1;

}
