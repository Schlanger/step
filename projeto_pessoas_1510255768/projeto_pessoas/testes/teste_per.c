//
//#include "teste_per.h"
//#include "ent.h"
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void teste_per_out() {
//	FILE * _file = fopen("./estatisticas.txt", "w");
//
//	if (grava_medias(_file, (salario)2148.324, (media)15.769) == 1) {
//		printf("OK\n");
//	}
//	else {
//		printf("! OK\n");
//	}
//
//	if (grava_intervalo(_file, 15, 20, 8) == 1) {
//		printf("OK 15,20,8\n");
//	}
//	else {
//		printf("! OK 15,20,8\n");
//	}
//
//
//	if (grava_intervalo(_file, 21, 25, 12) == 1) {
//		printf("OK 21, 25, 12\n");
//	}
//	else {
//		printf("! OK 21, 25, 12\n");
//	}
//
//	if (grava_intervalo(_file, 26, 30, 31) == 1) {
//		printf("OK 26, 30, 31\n");
//	}
//	else {
//		printf("! OK 26, 30, 31\n");
//	}
//
//	fclose(_file);
//
//}
//
///*
//Primeira linha do arquivo: num-pessoas
//Proximas linhas do arquivo: 'num-pessoas' linhas
//id;nome;idade;cep;salario
//*/
//void teste_per_in() {
//
//	const char * file_name = "./input.txt";
//	pessoa * p = NULL;
//	int tam = 0;
//
//	int rc = le_pessoas(&p, &tam, file_name);
//
//	if (rc != 1) {
//		printf("Erro lendo arquivo de pessoas: %d", rc);
//	}
//
//	for (pessoa * aux = p; aux < p + tam; aux++)
//		imprime_pessoa(aux);
//
//	if (p)
//		free(p);
//}
//
//
//
//void teste_per() {
//	//teste_per_out();
//	teste_per_in();
//}
