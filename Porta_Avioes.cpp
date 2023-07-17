#include "Porta_Avioes.h"

Porta_Avioes::Porta_Avioes()
{
	PontoNaval P(1, 'A', 'O');
	this->porta_avioes.set_navio("Porta Aviões", P, vector_size);
}

Porta_Avioes::~Porta_Avioes()
{
}

void Porta_Avioes::set_porta_avioes(string TIPO, PontoNaval P, int VECTOR_SIZE)
{
	this->porta_avioes.set_navio(TIPO, P, VECTOR_SIZE);
}

void Porta_Avioes::show_porta_avioes()
{
	int i = 0;
	cout << porta_avioes.get_tipo() << endl;
	for (i = 0; i < 5; i++)
	{
		porta_avioes.get_ponto_pn(i).ShowPontoNaval();
	}
}
