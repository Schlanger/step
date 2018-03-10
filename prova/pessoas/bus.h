#ifndef _BUS_H_

#define _BUS_H_

#include "pessoa.h"
#include "lista.h"

int calcula_medias(lista *  no, uint16_t p_qtde, media * p_media_sal, media * p_media_idade);

int qtde_pessoas(lista *  no, idade p_inicial, idade p_final, uint16_t * p_qtde_pes);

#endif
