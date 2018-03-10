#ifndef _PER_H_
#define _PER_H_

#include <stdio.h>
#include <stdint.h>

#include "ent.h"

/*
Ao final, escrever em um arquivo 'estatisticas.txt':
media-salarial;media-idade;num-15-20;num-21-25;num-26-30;num-31-35;num-36-40;num-acima-41
*/

int grava_medias(FILE * p_file, salario p_media, media p_idade);

int grava_intervalo(FILE * p_file, idade p_ini, idade p_fim, uint16_t p_qtde);







#endif