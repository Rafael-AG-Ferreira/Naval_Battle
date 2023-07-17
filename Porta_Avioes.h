#pragma once
#include "Navio.h"

class Porta_Avioes
{
private:
	Navio porta_avioes;		//Declara��o de um objeto tipo Barco
	int vector_size = 5;	//Declara��o do tamanho desse barco (nr� de canos)
public:
	//Construtor e Destrutor
	Porta_Avioes();
	virtual ~Porta_Avioes();

	//GETTERS
	Navio& get_porta_avioes() { return porta_avioes; };
	int get_vector_size() { return this->vector_size; };
	
	//SETTERS
	void set_porta_avioes(string TIPO, PontoNaval P, int VECTOR_SIZE);

	//Fun��o SHOW
	void show_porta_avioes();
};

