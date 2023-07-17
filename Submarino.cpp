#include "Submarino.h"

Submarino::Submarino()
{
	PontoNaval P(1, 'A', 'O');
	this->submarino.set_barco("Submarino", P, vector_size);
}

Submarino::~Submarino()
{
}

Barco& Submarino::get_submarino()
{
	return this->submarino;
}

int Submarino::get_vector_size()
{
	return this->vector_size;
}

void Submarino::set_submarino(string TIPO, PontoNaval P, int VECTOR_SIZE)
{
	this->submarino.set_barco(TIPO, P, VECTOR_SIZE);
}

void Submarino::show_submarino()
{
	cout << submarino.get_tipo() << " ";
	submarino.get_ponto_pn().ShowPontoNaval();
}
