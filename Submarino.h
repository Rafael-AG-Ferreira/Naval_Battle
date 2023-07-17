#pragma once
#include "Barco.h"
class Submarino
{
private:
	Barco submarino;		//Declara��o de um objeto tipo Barco
	int vector_size = 1;	//Declara��o do tamanho desse barco (nr� de canos)
public:
	//Construtor e Destrutor
	Submarino();
	virtual ~Submarino();
	
	//GETTERS
	Barco& get_submarino();
	int get_vector_size();
	
	//SETTERS
	void set_submarino(string TIPO, PontoNaval P, int VECTOR_SIZE);

	//Fun��o SHOW
	void show_submarino();
};

