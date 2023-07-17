#pragma once
#include "Navio.h"

class Couracado
{
private:
	Navio couracado;	//Declara��o de um objeto tipo Barco
	int vector_size = 4;//Declara��o do tamanho desse barco (nr� de canos)
public:
	//Construtor e Destrutor
	Couracado();
	virtual ~Couracado();
	
	//GETTERS
	Navio& get_couracado() { return couracado; };
	int get_vector_size() { return this->vector_size; };
	
	//SETTERS
	void set_couracado(string TIPO, PontoNaval P, int VECTOR_SIZE);

	//Fun��o SHOW
	void show_couracado();
};

