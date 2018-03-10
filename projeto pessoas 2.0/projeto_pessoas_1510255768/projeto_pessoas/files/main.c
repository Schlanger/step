
/*
Escrever um pgm que:

1 - Leia um arquivo, passado como parâmetro, que tem o seguinte formato:
Primeira linha do arquivo: num-pessoas
Proximas linhas do arquivo: 'num-pessoas' linhas
id;nome;idade;cep;salario

2 - Interaja com o usuário, perguntando os dados de novas pessoas.

3 - Ao final da interação, levando em consideração as pessoas lidas do arquivo, e as pessoas informadas pelo usuário, calcular:
a - a media salarial
b - a media de idade
c - qtas pessoas entre 15 e 20 anos; entre 21 e 25; entre 26 e 30; 31 e 35; 36 e 40; e acima de 41

4- Ao final, escrever na saída padrão:
media-salarial;media-idade;num-15-20;num-21-25;num-26-30;num-31-35;num-36-40;num-acima-41

5 - Atualize o arquivo de pessoas com as pessoas informadas
*/



#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "ent.h"
#include "bus.h"
#include "per.h"
#include "lista.h"

#define _DEBUG_



//***************************************************
// bus

/*
	Lê as pessoas do arquivo '_file', carrega em 'p_pessoa', e informa a qtde em 'p_qtde'	

	retorna 1 se ok
	retorna -1 se não conseguiu ler header do arquivo
	retorna -2 se não conseguiu ler header da linha
	retorna -3 se não conseguiu ler a linha
	retorna -4 se não conseguiu alocar o vetor em '*p_pessoa'
*/
//nt carrega_pessoas(FILE *_file, pessoa ** p_pessoa, uint16_t * p_qtde);





int main(int argc, char **argv) {

	if (argc != 2) {
		printf("Sintaxe: %s <nome-arquivo>\n", argv[0]);
		return 1;
	}

	const char * _file_name = "./input.txt"; // argv[1];	
	lista * no = lst_Cria(); 
	int _qtde = 0;
	
	int rc = le_pessoas(no,&_qtde,_file_name);

	if (rc != 1)
		("Erro de leitura de pessoa: %d", rc);

	media m_sal, m_idade;

	calcula_medias(no,_qtde,&m_sal,&m_idade);

	FILE * _file = fopen("./output.txt", "w");

	grava_medias(_file, m_sal, m_idade);
	grava_intervalo(_file, (idade)15, (idade)20, _qtde);
	grava_intervalo(_file, (idade)21, (idade)25, _qtde);
	grava_intervalo(_file, (idade)26, (idade)30, _qtde);
	grava_intervalo(_file, (idade)31, (idade)35, _qtde);
	grava_intervalo(_file, (idade)36, (idade)40, _qtde);
	grava_intervalo(_file, (idade)40, (idade)999, _qtde);

	//int _rc = carrega_pessoas(_file, &_pessoa, &_qtde) ;
	//if (_rc != 1) {
	//	printf("Erro %d\n", _rc);
	//}

	fclose(_file);

}

///////////////

//int carrega_pessoas(FILE *p_file, pessoa ** p_pessoa, uint16_t * p_qtde) {
//
//	uint16_t _qtde_pessoas = 0;
//
//	{
//		char _buf_qtde_pessoas[6];
//		memset(_buf_qtde_pessoas, '\0', 6);
//		if (fread(_buf_qtde_pessoas, 1, 5, p_file) != 5) {
//			return -1;
//		}
//
//		_qtde_pessoas = atoi(_buf_qtde_pessoas);
//	}
//
//#ifdef _DEBUG_
//	printf("# pessoas = %d\n", _qtde_pessoas);
//#endif
//
//	/*
//		alocar o vetor '*p_pessoa'
//	*/
//
//	*p_pessoa = (pessoa *)malloc(_qtde_pessoas * sizeof(pessoa));
//	if (*p_pessoa == NULL) {
//		return -4;
//	}
//
//
//	fseek(p_file, 2, SEEK_CUR);
//	char _buf_tam_linha[3];
//	uint16_t _tam_linha = 0;
//	for (uint16_t _count = 0; _count < _qtde_pessoas; ++_count) {
//		memset(_buf_tam_linha, '\0', 3);
//		if (fread(_buf_tam_linha, 1, 2, p_file) != 2) {
//			return -2;
//		}
//
//		_tam_linha = atoi(_buf_tam_linha);
//#ifdef _DEBUG_
//		printf("tam linha = %d\n", _tam_linha);
//#endif
//
//		fseek(p_file, 1, SEEK_CUR);
//		char * _buf_line = (char *)malloc(_tam_linha + 1);
//		memset(_buf_line, '\0', _tam_linha + 1);
//		if (fread(_buf_line, 1, _tam_linha, p_file) != _tam_linha) {
//			return -3;
//		}
//#ifdef _DEBUG_
//		printf("buf_line = %s\n", _buf_line);
//#endif
//
//		/*
//			copiar o id, nome, idade, cep e salario para uma variável 'pessoa', 
//			e atribuo a '(*p_pessoa)[_count]'
//		*/
//
//
//		free(_buf_line);
//		_buf_line = NULL;
//
//	}
//
//	return 1;
//}