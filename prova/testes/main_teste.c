#include "pessoa.h"
#include "bus.h"
#include "per.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void teste1();

int main() {

	//teste1();

	//const char * _file_name = "./input.txt"; // argv[1];	
	//lista * no = lst_Cria();
	//int _qtde = 0;

	//int rc = le_pessoas(no, &_qtde, _file_name);

	////teste 2: Leitura do no, gravado
	//lst_visita(no, imprime_pessoa_void);

	return 0;
}

void teste1()
{
	//teste 1: criaçao da pessoa
	lista * pessoas = lst_Cria();
	pessoa p1, p2;
	int n;

	n = cria_pessoa(&p1, 1, "Leo", 21, 5000.99, "22021-040");

	if (n != 1)
		printf("Erro na criaçao da pessoa codigo %d", n);

	n = cria_pessoa_str(&p2, "36;27;Manuela Alves;22221-198;902.80");

	if (n != 1)
		printf("Erro na criaçao da pessoa codigo %d", n);

	n = imprime_pessoa(&p1);

	if (n != 1)
		printf("Erro na criaçao da pessoa codigo %d", n);

	n = imprime_pessoa(&p2);

	if (n != 1)
		printf("Erro na criaçao da pessoa codigo %d", n);

	pessoas = lst_insere(pessoas, &p1, sizeof(pessoa));

	pessoas = lst_insere(pessoas, &p2, sizeof(pessoa));

	lst_visita(pessoas, imprime_pessoa_void);
}