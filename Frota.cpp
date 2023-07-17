#include "Frota.h"
#include <string>

Frota::Frota()
{
	int i = 0;
	PontoNaval P(1, 'A', 'O');

	for (i = 0; i < 4; i++)
	{
		get_submarinos(i).get_submarino().set_barco("Submarino #" + to_string(i + 1), P, 1);
	}
	for (i = 0; i < 3; i++)
	{
		this->contratorpedeiros[i].set_contratorpedeiro("Contratorpedeiro #" + to_string(i + 1), P, 2);
	}
	for (i = 0; i < 2; i++)
	{
		this->cruzadores[i].set_cruzador("Cruzador #" + to_string(i + 1), P, 3);
	}
	this->couracados.set_couracado("Couracado #1", P, 4);
	this->porta_avioes_.set_porta_avioes("Porta Aviões #1", P, 5);
}

Frota::~Frota()
{
}

Submarino& Frota::get_submarinos(int num_sub)
{
	return this->submarinos[num_sub];
}

Contratorpedeiro& Frota::get_contratorpedeiros(int num_contra)
{
	return this->contratorpedeiros[num_contra];
}

Cruzador& Frota::get_cruzadores(int num_sub)
{
	return this->cruzadores[num_sub];
}

Couracado& Frota::get_couracados()
{
	return this->couracados;
}

Porta_Avioes& Frota::get_porta_avioes_()
{
	return this->porta_avioes_;
}
