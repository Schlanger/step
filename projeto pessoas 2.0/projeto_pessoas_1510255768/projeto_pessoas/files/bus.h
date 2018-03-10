#ifndef _BUS_H_
#define _BUS_H_

#include "ent.h"

/*
Calcular:
1 - a media salarial
2 - a media de idade
3 - qtas pessoas entre 15 e 20 anos; entre 21 e 25; entre 26 e 30; 31 e 35; 36 e 40; e acima de 41

*/

/*
Calcula a media salaria das pessoas em p_vet

retorna 1 se ok
retorna < 0 se !ok
*/
int calcula_medias(const pessoa * p_vet, uint16_t p_qtde, media * p_media_sal, media * p_media_idade);

/*
retorna 1 se ok
retorna < 0 se !ok
*/
int qtde_pessoas(const pessoa * p_vet, uint16_t p_qtde, idade p_inicial, idade p_final, uint16_t * p_qtde_pes);




#endif