#ifndef _PESSOAS_H_

#define _PESSOAS_H_

//id;nome;idade;cep;salario

#include <stdint.h>
#include <string.h>
#include <stdlib.h> 

//***************************************************
// ent
#define TAM_NOME 50 + 1
#define TAM_CEP 9 + 1

typedef uint32_t id;
typedef uint32_t idade;
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


/* f�s de cria��o, copia e compara��o de 'pessoa'
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

//retorna 1 caso sucesso e 0 caso n
int imprime_pessoa_void(void * p, int tam);

#endif // !_PESSOAS_H_

