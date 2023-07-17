#include "Cruzador.h"

Cruzador::Cruzador()
{
	PontoNaval P(1, 'A', 'O');
	this->cruzador.set_navio("Cruzador", P, vector_size);
}

Cruzador::~Cruzador()
{
}

void Cruzador::set_cruzador(string TIPO, PontoNaval P, int VECTOR_SIZE)
{
	this->cruzador.set_navio(TIPO, P, VECTOR_SIZE);
}

void Cruzador::show_cruzador()
{
	int i = 0;
	cout << cruzador.get_tipo() << endl;
	for (i = 0; i < 3; i++)
	{
		cruzador.get_ponto_pn(i).ShowPontoNaval();
	}
}
