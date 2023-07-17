#pragma once
#include "Barco.h"
class Submarino
{
private:
	Barco submarino;		//Declaração de um objeto tipo Barco
	int vector_size = 1;	//Declaração do tamanho desse barco (nrº de canos)
public:
	//Construtor e Destrutor
	Submarino();
	virtual ~Submarino();
	
	//GETTERS
	Barco& get_submarino();
	int get_vector_size();
	
	//SETTERS
	void set_submarino(string TIPO, PontoNaval P, int VECTOR_SIZE);

	//Função SHOW
	void show_submarino();
};

