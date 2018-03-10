//#include "teste_bus.h"
//#include "ent.h"
//#include <stdio.h>
//#define MAX_PESSOAS 8
//
//
//
//void teste_bus() {
//
//	int rc = 0;
//
//	pessoa p[MAX_PESSOAS];
//	
//	rc = cria_pessoa(&p[0], 0, "Pedro Serrano", 20, 10000.45, "22755-200");
//	if (rc != 1) {
//		printf("Não conseguiu cria pessoa 'Pedro Serrano': %d\n", rc);
//		return;
//	}
//
//	cria_pessoa(&p[1], 1, "Leo Schlanger", 45, 10300.24, "22755-200");
//	cria_pessoa(&p[2], 2, "Igor", 34, 10500.67, "22795-100");
//	cria_pessoa(&p[3], 3, "Canellas", 51, 10000.94, "56354-550");
//	cria_pessoa(&p[4], 4, "Rodrigo", 21, 10100.99, "65646-432");
//	cria_pessoa(&p[5], 5, "Pedro Serrano 01", 23, 60060.23, "23132-200");
//	cria_pessoa(&p[6], 6, "Pedro Serrano 02", 22, 7008.14, "34346-193");
//	cria_pessoa(&p[7], 7, "Pedro Serrano 03", 10, 2004.67, "22756-200");
//
//	media media_salario = 0.;
//	media media_idade = 0.;
//
//	// ------------------
//	int retorno = calcula_medias(p, MAX_PESSOAS, &media_salario, &media_idade);
//	if (retorno != 1) {
//		printf("Deu Erro: %d", retorno);
//		return;
//	}
//
//	printf("Media Salario: %.2f\n", media_salario);
//	printf("Media Idade: %.2f\n", media_idade);
//
//	// ------------------
//	idade inicio = 20;
//	idade final = 25;
//	uint16_t qtd_pes = 0;
//	int retorno2 = qtde_pessoas(p, MAX_PESSOAS, inicio, final, &qtd_pes);
//	if (retorno2 != 1) {
//		printf("Deu Erro: %d", retorno2);
//		return;
//	}
//
//	printf("Qtd de pesssoas: %d\n", qtd_pes);
//
//
//
//}