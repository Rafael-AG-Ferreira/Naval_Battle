#pragma once
#include "Barco.h"
class Navio: public Barco
{
private:
	
public:
	Navio();
	virtual ~Navio();

	void set_navio(string TIPO, PontoNaval P, int VECTOR_SIZE);
};

