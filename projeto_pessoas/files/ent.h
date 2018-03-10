#ifndef _ENT_H_
#define _ENT_H_

#include <stdint.h>

//***************************************************
// ent
#define TAM_NOME 50 + 1
#define TAM_CEP 9 + 1

typedef uint16_t id;
typedef uint8_t idade;
typedef double salario;
typedef float media;

#define OK 1


typedef struct {
	id m_id;
	idade m_idade;
	char m_nome[TAM_NOME];
	char m_cep[TAM_CEP];
	salario m_salario;
} pessoa;


/* fçs de criação, copia e comparação de 'pessoa' */

#endif