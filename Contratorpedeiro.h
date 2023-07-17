#pragma once
#include "Navio.h"

class Contratorpedeiro
{
private:
	Navio contratorpedeiro; //Declara��o de um objeto tipo Barco
	int vector_size = 2;	//Declara��o do tamanho desse barco (nr� de canos)

public:
	//Construtor e Destrutor
	Contratorpedeiro();
	virtual ~Contratorpedeiro();

	//GETTERS
	Navio& get_contratorpedeiro() { return contratorpedeiro; };
	int get_vector_size() { return this->vector_size; };
	
	//SETTERS
	void set_contratorpedeiro(string TIPO, PontoNaval P, int VECTOR_SIZE);
	
	//Fun��o SHOW
	void show_contratorpedeiro();
};

