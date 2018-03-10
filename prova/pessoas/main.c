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

#include "pessoa.h"
#include "bus.h"
#include "per.h"
#include "lista.h"
#include "itf.h"

int main() 
{

	const char * _file_name = "./input.txt"; 	
	lista * no = lst_Cria();
	int _qtde = 0;
	
	int rc = le_pessoas(no, &_qtde, _file_name);

	if (rc != 1)
		return -1;

	lst_visita(no, imprime_pessoa_void);

	rc = add_pessoas(no, &_qtde);

	if (rc != 1)
		return -2;

	printf("\n");
	lst_visita(no, imprime_pessoa_void);

	mostra_dados(no, _qtde);

	rc = preenche_novo(no, _qtde, _file_name);

	if (rc != 1)
		return -3;

	return 0;
}