#include "Contratorpedeiro.h"

Contratorpedeiro::Contratorpedeiro()
{
	PontoNaval P(1, 'A', 'O');
	this->contratorpedeiro.set_navio("Contratorpedeiro", P, vector_size);
}

Contratorpedeiro::~Contratorpedeiro()
{
}

void Contratorpedeiro::set_contratorpedeiro(string TIPO, PontoNaval P, int VECTOR_SIZE)
{
	this->contratorpedeiro.set_navio(TIPO, P, VECTOR_SIZE);
}

void Contratorpedeiro::show_contratorpedeiro()
{
	int i = 0;
	cout << contratorpedeiro.get_tipo() << endl;
	for (i = 0; i < 2; i++)
	{
		contratorpedeiro.get_ponto_pn(i).ShowPontoNaval();
	}
}
