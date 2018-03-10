#include "bus.h"

int calcula_medias(lista *  no, uint16_t p_qtde, media * p_media_sal, media * p_media_idade)
{
	if (no == NULL)
		return -1;

	if (p_media_sal == NULL)
		return -2;

	if (p_media_idade == NULL)
		return -3;

	lista * aux = no;

	pessoa * auxp = NULL;

	*p_media_sal = 0.;
	*p_media_idade = 0.;
	do

	{

		auxp = (pessoa*)aux->elemento;
		*p_media_sal += auxp->m_salario;
		*p_media_idade += auxp->m_idade;
		aux = aux->depois;

	} while (aux != no);

	*p_media_sal /= p_qtde;
	*p_media_idade /= p_qtde;

	return 1;
}

int qtde_pessoas(lista *  no, idade p_inicial, idade p_final, uint16_t * p_qtde_pes)
{
	if (no == NULL)
		return -1;

	if (p_qtde_pes == NULL)
		return -2;

	lista * aux = no;
	*p_qtde_pes = 0;

	pessoa * auxp = NULL;

	do
	{
		auxp = (pessoa*)aux->elemento;
		if ((auxp->m_idade >= p_inicial) && (auxp->m_idade <= p_final))
			(*p_qtde_pes)++;
		aux = aux->depois;
	} while (aux != no);

	return 1;
}