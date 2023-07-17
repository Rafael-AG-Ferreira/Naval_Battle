#include "Navio.h"

Navio::Navio()
{
	PontoNaval P(1, 'A', 'O');
	set_barco("Navio não Especificado", P, 1);
}

Navio::~Navio()
{
}

void Navio::set_navio(string TIPO, PontoNaval P, int VECTOR_SIZE)
{
	int i = 0;
	this->set_barco(TIPO, P, VECTOR_SIZE);
	for (i = 0; i < VECTOR_SIZE; i++)
	{
		this->get_ponto_pn(i).Set_PN((P.Get_X()+i), P.Get_Y(), P.Get_C());
	}
}