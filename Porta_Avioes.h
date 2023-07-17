#pragma once
#include "Navio.h"

class Porta_Avioes
{
private:
	Navio porta_avioes;		//Declaração de um objeto tipo Barco
	int vector_size = 5;	//Declaração do tamanho desse barco (nrº de canos)
public:
	//Construtor e Destrutor
	Porta_Avioes();
	virtual ~Porta_Avioes();

	//GETTERS
	Navio& get_porta_avioes() { return porta_avioes; };
	int get_vector_size() { return this->vector_size; };
	
	//SETTERS
	void set_porta_avioes(string TIPO, PontoNaval P, int VECTOR_SIZE);

	//Função SHOW
	void show_porta_avioes();
};

