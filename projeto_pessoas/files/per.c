#include "per.h"

int grava_medias(FILE * p_file, salario p_media, media p_idade) {
	int _rc = fprintf(p_file, "% 9.2f% 9.2f|", p_media, p_idade);
	return (_rc > 0 ? 1 : _rc);
}

int grava_intervalo(FILE * p_file, idade p_ini, idade p_fim, uint16_t p_qtde) {
	int _rc = fprintf(p_file, "% 5d% 5d% 5d;", p_ini, p_fim, p_qtde);
	return 1;
}
