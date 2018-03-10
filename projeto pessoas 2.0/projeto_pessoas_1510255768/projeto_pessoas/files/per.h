#ifndef _PER_H_
#define _PER_H_

#include <stdio.h>
#include <stdint.h>

#include "ent.h"
#include "lista.h"


/* 
Saida: arquivo 'estatisticas.txt':
media - salarial; media - idade; idade1 idade2 qdte ; idade1 idade2 qdte ;
*/

int grava_medias(FILE * p_file, salario p_media, media p_idade);

int grava_intervalo(FILE * p_file, idade p_ini, idade p_fim, uint16_t p_qtde);

int le_pessoas(lista * no, int * p_tam, const char * p_file_name);

#endif