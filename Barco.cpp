#include "Barco.h"
#include <string>

Barco::Barco()
{
	this->tipo = "barco não especificado";
	ponto_pn = new PontoNaval;
	this->ponto_pn->Set_PN(1, 'A', 'O');
}

void Barco::set_ponto_pn(int x, char y, char z)
{
	ponto_pn->Set_PN(x, y, z);
}

void Barco::set_vector_size(int VECTOR_SIZE)
{
	this->vector_size = VECTOR_SIZE;
}

void Barco::set_barco(string TIPO, PontoNaval P, int VECTOR_SIZE)
{
	this->tipo = TIPO;
	this->ponto_pn = new PontoNaval[VECTOR_SIZE];
	this->vector_size = VECTOR_SIZE;
	ponto_pn->Set_PN(P);
}

void Barco::set_tipo(string TIPO)
{
	this->tipo = TIPO;
}

Barco::~Barco()
{
}
