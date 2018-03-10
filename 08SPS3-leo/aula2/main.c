#include <string.h>
#include <stdio.h>

#define TAM_NOME 50+1

typedef double salario;

typedef struct pessoa{
	
char nome[TAM_NOME];
int idade;
char sexo;
salario _salario;

}pessoa;

//inicializa pessoa. Retorna 1 se ok. <1 se n
int inicializa_pessoa(pessoa * p, char * nome, int idade, char sexo, salario sal);

//imprime todos os dados de pessoa
void imprime_pessoa(pessoa * p);

//copia p2 em p1
void copia_pessoa(pessoa *p1, pessoa *p2);	

int main()
{
	pessoa p1;

	inicializa_pessoa(&p1, "Leo Schlanger", 21, 'M', 120000.99);

	printf("%i", sizeof(pessoa));
	imprime_pessoa(&p1); 

	return 0;
}

void imprime_pessoa(pessoa * p)
{
	printf("\n\nNome: %s\nIdade: %d\nSexo: %c\nSalario: %.2f\n\n", p->nome, p->idade, p->sexo, p->_salario);
}

void copia_pessoa(pessoa *p1, pessoa *p2)
{
	p1->idade = p2->idade;
	strcpy(p1->nome,p2->nome);
	p1->sexo = p2->sexo;
	p1->_salario = p2->_salario;
}

int inicializa_pessoa(pessoa * p, char * nome, int idade, char sexo, salario sal)
{
	if (p == NULL)
		return -1;

	if (strlen(nome) > TAM_NOME)
		return -2;

	if (idade < 0 || sal < 0)
		return -3;

	if (sexo != 'M' || sexo != 'F' || sexo != 'm' || sexo != 'f')
		return -4;

	p->idade = idade;
	strcpy(p->nome, nome);
	p->sexo = sexo;
	p->_salario = sal;

	return 1;
}