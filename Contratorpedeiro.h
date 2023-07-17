#pragma once
#include "Navio.h"

class Contratorpedeiro
{
private:
	Navio contratorpedeiro; //Declaração de um objeto tipo Barco
	int vector_size = 2;	//Declaração do tamanho desse barco (nrº de canos)

public:
	//Construtor e Destrutor
	Contratorpedeiro();
	virtual ~Contratorpedeiro();

	//GETTERS
	Navio& get_contratorpedeiro() { return contratorpedeiro; };
	int get_vector_size() { return this->vector_size; };
	
	//SETTERS
	void set_contratorpedeiro(string TIPO, PontoNaval P, int VECTOR_SIZE);
	
	//Função SHOW
	void show_contratorpedeiro();
};

