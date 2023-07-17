#include "Couracado.h"

Couracado::Couracado()
{
	PontoNaval P(1, 'A', 'O');
	this->couracado.set_navio("Couracado", P, vector_size);
}

Couracado::~Couracado()
{
}

void Couracado::set_couracado(string TIPO, PontoNaval P, int VECTOR_SIZE)
{
	this->couracado.set_navio(TIPO, P, VECTOR_SIZE);
}

void Couracado::show_couracado()
{
	int i = 0;
	cout << couracado.get_tipo() << endl;
	for (i = 0; i < 4; i++)
	{
		couracado.get_ponto_pn(i).ShowPontoNaval();
	}
}
