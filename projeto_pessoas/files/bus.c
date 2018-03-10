#include "bus.h"
#include "ent.h"

int calcula_medias(const pessoa * p_vet, uint16_t p_qtde, salario * p_media_sal, media * p_media_idade)
{
	if (p_vet == NULL)
		return -1;

	if (p_media_sal == NULL)
		return -2;

	if (p_media_idade == NULL)
		return -3;

	pessoa * aux;

	*p_media_sal = 0;
	*p_media_idade = 0;

	for (aux = p_vet; aux < p_vet + p_qtde; aux++)
	{
		*p_media_sal += aux->m_salario;
		*p_media_idade += aux->m_idade;
	}

	*p_media_sal /= p_qtde;
	*p_media_idade /= p_qtde;

	return 1;
}

int qtde_pessoas(const pessoa * p_vet, uint16_t p_qtde, idade p_inicial, idade p_final, uint16_t * p_qtde_pes)
{
	if (p_vet == NULL)
		return -1;

	if (p_qtde_pes == NULL)
		return -2;

	pessoa * aux;
	*p_qtde_pes = 0;

	for (aux = p_vet; aux < p_vet + p_qtde; aux++)
		if ((aux->m_idade >= p_inicial) && (aux->m_idade <= p_final))
			* p_qtde_pes++;

	return 1;
}