#include "ent.h"
#include "lista.h"

int cria_pessoa(pessoa *  p, id _id, char *_nome, idade _idade, salario _salario, char *_cep) {

	if (_nome == NULL) {
		return -1;
	}

	if (_cep == NULL) {
		return -3;
	}
	if (strlen(_nome) > TAM_NOME) {
		return -4;
	}
	if (strlen(_cep) > TAM_CEP) {
		return -5;
	}

	strcpy(p->m_nome, _nome);
	strcpy(p->m_cep, _cep);
	p->m_idade = _idade;
	p->m_salario = _salario;
	return 1;
}

int cria_pessoa_str(pessoa * p, const char * const buf) {
	// 36;27; Manuela Alves; 22221 - 198; 902.80
	
	if (buf == NULL)
		return -1;
	
	char aux[15 + 1];
	int i = 0;
	int ultimo_ponto_e_virg = i;

	memset(aux, '\0', 15);
	for (;  buf[i] != ';'; ++i) {
		aux[i] = buf[i];
	}

	p->m_id = atoi(aux);
	
	++i; // passa do ';'
	ultimo_ponto_e_virg = i;

	memset(aux, '\0', 15);
	for (; buf[i] != ';'; ++i) {
		aux[i - ultimo_ponto_e_virg] = buf[i];
	}

	p->m_idade = atoi(aux);

	++i; // passa do ';'
	ultimo_ponto_e_virg = i;

	memset(p->m_nome, '\0', TAM_NOME);
	for (; buf[i] != ';'; ++i) {
		p->m_nome[i - ultimo_ponto_e_virg] = buf[i];
	}

	//strcpy(p->m_nome,aux);

	++i; // passa do ';'
	ultimo_ponto_e_virg = i;

	memset(p->m_cep, '\0', TAM_CEP);
	for (; buf[i] != ';'; ++i) {
		p->m_cep[i - ultimo_ponto_e_virg] = buf[i];
	}

	//strcpy(p->m_cep, aux);

	++i; // passa do ';'
	ultimo_ponto_e_virg = i;

	memset(aux, '\0', 15);
	for (; buf[i] != '\0'; ++i) {
		aux[i - ultimo_ponto_e_virg] = buf[i];
	}

	p->m_salario = atof(aux);

	return 1;

}


int imprime_pessoa(const pessoa * p)
{
	if (p == NULL)
		return 0;

	printf("ID: %04i Nome: % 51s Idade: % 3i CEP: %s Salario: % 8.2f\n", p->m_id, p->m_nome, p->m_idade, p->m_cep, p->m_salario);

	return 1;
}


