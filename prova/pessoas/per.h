#ifndef _PER_H_
#define _PER_H_

#include <stdio.h>
#include <stdint.h>

#include "pessoa.h"
#include "lista.h"
#include "bus.h"


/*
media - salarial; media - idade; idade1 idade2 qdte ; idade1 idade2 qdte ;
*/

int le_pessoas(lista * no, int * p_tam, const char * p_file_name);

int mostra_medias(lista * no, int _qtde);

int mostra_intervalo(lista * no, idade p_ini, idade p_fim, uint16_t p_qtde);

int mostra_dados(lista * no, int _qtde);

int preenche_novo(lista * no, int p_tam, const char * p_file_name);

#endif
