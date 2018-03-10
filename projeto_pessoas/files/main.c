/*
Escrever um pgm leia um arquivo, passado como parâmetro, que tem o seguinte formato:
Primeira linha do arquivo: num-pessoas
Proximas linhas do arquivo: 'num-pessoas' linhas
id;nome;idade;cep;salario

Calcular:
1 - a media salarial
2 - a media de idade
3 - qtas pessoas entre 15 e 20 anos; entre 21 e 25; entre 26 e 30; 31 e 35; 36 e 40; e acima de 41

Ao final, escrever em um arquivo 'estatisticas.txt':
media-salarial;media-idade;num-15-20;num-21-25;num-26-30;num-31-35;num-36-40;num-acima-41

*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "ent.h"

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
int carrega_pessoas(FILE *_file, pessoa ** p_pessoa, uint16_t * p_qtde);





int main(int argc, char **argv) {

	/*if (argc != 2) {
		printf("Sintaxe: %s <nome-arquivo>\n", argv[0]);
		return 1;
	}
*/
	const char * _file_name = "C:\\16SPS2\\files\\input.txt"; // argv[1];
	FILE * _file = fopen(_file_name, "r");
	if (_file == NULL) {
		printf("Nao foi possivel abrir %s\n", _file_name);
		return 2;
	}

	pessoa * _pessoa = NULL; 
	uint16_t _qtde = 0;
	
	int _rc = carrega_pessoas(_file, &_pessoa, &_qtde) ;
	if (_rc != 1) {
		printf("Erro %d\n", _rc);
	}

}

///////////////

int carrega_pessoas(FILE *p_file, pessoa ** p_pessoa, uint16_t * p_qtde) {

	uint16_t _qtde_pessoas = 0;

	{
		char _buf_qtde_pessoas[6];
		memset(_buf_qtde_pessoas, '\0', 6);
		if (fread(_buf_qtde_pessoas, 1, 5, p_file) != 5) {
			return -1;
		}

		_qtde_pessoas = atoi(_buf_qtde_pessoas);
	}

#ifdef _DEBUG_
	printf("# pessoas = %d\n", _qtde_pessoas);
#endif

	/*
		alocar o vetor '*p_pessoa'
	*/

	*p_pessoa = (pessoa *)malloc(_qtde_pessoas * sizeof(pessoa));
	if (*p_pessoa == NULL) {
		return -4;
	}


	fseek(p_file, 2, SEEK_CUR);
	char _buf_tam_linha[3];
	uint16_t _tam_linha = 0;
	for (uint16_t _count = 0; _count < _qtde_pessoas; ++_count) {
		memset(_buf_tam_linha, '\0', 3);
		if (fread(_buf_tam_linha, 1, 2, p_file) != 2) {
			return -2;
		}

		_tam_linha = atoi(_buf_tam_linha);
#ifdef _DEBUG_
		printf("tam linha = %d\n", _tam_linha);
#endif

		fseek(p_file, 1, SEEK_CUR);
		char * _buf_line = (char *)malloc(_tam_linha + 1);
		memset(_buf_line, '\0', _tam_linha + 1);
		if (fread(_buf_line, 1, _tam_linha, p_file) != _tam_linha) {
			return -3;
		}
#ifdef _DEBUG_
		printf("buf_line = %s\n", _buf_line);
#endif

		/*
			copiar o id, nome, idade, cep e salario para uma variável 'pessoa', 
			e atribuo a '(*p_pessoa)[_count]'
		*/


		free(_buf_line);
		_buf_line = NULL;

	}

	return 1;
}