#include "per.h"

#define TAM_BUF_LEITURA 512

int le_pessoas(lista * no, int * p_tam, const char * p_file_name) {

	FILE * _file = fopen(p_file_name, "r");
	if (_file == NULL) {
		printf("Não consegui abrir arquivo 'input.txt' \n");
		return -1;
	}

	/*
	2
	36;27;Manuela Alves;22221-198;902.80
	4;38;Gustavo Lins;01002-981;19239.15
	*/

	char buf[TAM_BUF_LEITURA + 1];

	memset(&buf[0], '\0', TAM_BUF_LEITURA + 1);

	if (fgets(buf, TAM_BUF_LEITURA, _file) == NULL) {
		printf("Não consegui ler qtde de pessoas de 'input.txt' \n");
		return -2;
	}

	printf("Qtde de pessoas: %s\n", buf);

	*p_tam = atoi(buf);

	for (int i = 0; i < *p_tam; i++)
	{


		memset(&buf[0], '\0', TAM_BUF_LEITURA + 1);

		if (fgets(buf, TAM_BUF_LEITURA, _file) == NULL) {
			printf("Não consegui ler qtde de pessoas de 'input.txt' \n");
			return -2;
		}

		pessoa * p = (pessoa *)malloc(sizeof(pessoa));

		cria_pessoa_str(p, buf);

		no = lst_insere(no, (void*)p, sizeof(pessoa));

		free(p);
	}

	fclose(_file);

	return 1;
}

int mostra_medias(lista * no, int _qtde)
{
	media media_sal, media_idade;
	int rc;

	rc = calcula_medias(no, _qtde, &media_sal, &media_idade);

	if (rc != 1)
		return -1;

	printf("\nMedia de idade: %lf\nMedia salarial: %lf\n", media_idade, media_sal);

	return 1;

}

int mostra_intervalo(lista * no, idade p_ini, idade p_fim, uint16_t p_qtde)
{
	int qtd=0;
	int cont;

	cont = qtde_pessoas(no,p_ini,p_fim,&qtd);

	if (cont != 1)
		return -1;

	printf("\nIntervalo de %u ate %u: %d\n", p_ini, p_fim, qtd);

	return 1;

}

int mostra_dados(lista * no, int _qtde)
{
	mostra_medias(no, _qtde);
	mostra_intervalo(no, 15, 20, _qtde);
	mostra_intervalo(no, 21, 25, _qtde);
	mostra_intervalo(no, 26, 30, _qtde);
	mostra_intervalo(no, 31, 35, _qtde);
	mostra_intervalo(no, 36, 40, _qtde);
	mostra_intervalo(no, 41, 99, _qtde);

	return 1;
}

int preenche_novo(lista * no, int p_tam, const char * p_file_name)
{
	FILE * _file = fopen(p_file_name, "w");
	if (_file == NULL) {
		printf("Não consegui abrir arquivo 'input.txt' \n");
		return -1;
	}

	lista * aux = no;

	/*
	2
	36;27;Manuela Alves;22221-198;902.80
	4;38;Gustavo Lins;01002-981;19239.15
	*/
	
	fprintf( _file,"%05d\n", p_tam);

	do
	{
		
		pessoa * p = (pessoa *)aux->elemento;
		fprintf(_file,"%u;%u;%s;%s;%.2lf\n",p->m_id,p->m_idade,p->m_nome,p->m_cep,p->m_salario);
		aux = aux->depois;

	} while (aux != no);

	fclose(_file);

	return 1;
}