#ifndef _ENT_H_
#define _ENT_H_

#include <stdint.h>
#include <string.h>
#include <stdlib.h> 

//***************************************************
// ent
#define TAM_NOME 50 + 1
#define TAM_CEP 9 + 1

typedef uint16_t id;
typedef uint8_t idade;
typedef double salario;
typedef double media;

#define OK 1


typedef struct {
	id m_id;
	idade m_idade;
	char m_nome[TAM_NOME];
	char m_cep[TAM_CEP];
	salario m_salario;
} pessoa;


/* fçs de criação, copia e comparação de 'pessoa' 

retorna 1 se ok, < 1 se nao ok 

*/

int cria_pessoa(pessoa * p, id _id, char * _nome, idade _idade, salario _salario, char * _cep);

/*
cria uma pessoa a partir de um string no formato:
36;27;Manuela Alves;22221-198;902.80
*/
int cria_pessoa_str(pessoa * p, const char * const buf);

//retorna 1 caso sucesso e 0 caso n
int imprime_pessoa(const pessoa * p);


#endif