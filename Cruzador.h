#pragma once
#include "Navio.h"

class Cruzador
{
private:
	Navio cruzador;		//Declaração de um objeto tipo Barco
	int vector_size = 3;//Declaração do tamanho desse barco (nrº de canos)
public:
	//Construtor e Destrutor
	Cruzador();
	virtual ~Cruzador();

	//GETTERS
	Navio& get_cruzador() { return cruzador; };
	int get_vector_size() { return this->vector_size; };
	
	//SETTERS
	void set_cruzador(string TIPO, PontoNaval P, int VECTOR_SIZE);

	//Função SHOW
	void show_cruzador();
};

