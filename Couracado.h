#pragma once
#include "Navio.h"

class Couracado
{
private:
	Navio couracado;	//Declaração de um objeto tipo Barco
	int vector_size = 4;//Declaração do tamanho desse barco (nrº de canos)
public:
	//Construtor e Destrutor
	Couracado();
	virtual ~Couracado();
	
	//GETTERS
	Navio& get_couracado() { return couracado; };
	int get_vector_size() { return this->vector_size; };
	
	//SETTERS
	void set_couracado(string TIPO, PontoNaval P, int VECTOR_SIZE);

	//Função SHOW
	void show_couracado();
};

