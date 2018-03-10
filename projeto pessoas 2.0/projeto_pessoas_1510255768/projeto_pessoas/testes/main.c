#include "teste_per.h"
#include "teste_bus.h"
#include "ent.h"
#include <stdio.h>

void teste_parse_pessoa() {
	const char * buf = "36;27;Manuela Alves;22221-198;902.80";
	pessoa p;


	int rc = cria_pessoa_str(&p, buf);

	if (rc != 1) {
		printf("Erro criando pessoa: %d\n", rc);
	}

	imprime_pessoa(&p);

	printf("\n\npessoa criada com sucesso\n");
}

int main() {
	//int argc, char **argv
	//if (argc != 2) {
	//	printf("Sintaxe: %s <o-que-testar>\n", argv[0]);
	//	printf("Onde <o-que-testar> pode ser:\n");
	//	printf("\tP, para persistencia\n");
	//	printf("\tN, para negocio\n");
	//	return 1;
	//}

	//char op = argv[1][0];

	//if ((op == 'P') || (op == 'p')) {
	//	//teste_per();
	//}
	//else if ((op == 'N') || (op == 'n')) {
	//	//teste_bus();
	//}

	////teste_parse_pessoa();


	return 0;
}