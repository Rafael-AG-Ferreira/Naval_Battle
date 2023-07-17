#pragma once
#include <iostream>
#include "PontoNaval.h"

class Barco
{
private:
	string tipo;					//Nome do tipo de barco
	PontoNaval *ponto_pn;			//PontoNaval dinâmico para permitir criar barcos com vários canos
	int vector_size = NULL;			//Variável de controlo do tamanho (nrº de canos) dos barcos
public:
	//Construtor e Destrutor
	Barco();
	~Barco();

	//SETTERS
	void set_tipo(string TIPO);
	void set_ponto_pn(int x, char y, char z);
	void set_vector_size(int VECTOR_SIZE);
	void set_barco(string TIPO, PontoNaval P, int VECTOR_SIZE);
	
	//GETTERS
	string get_tipo() const				{ return this->tipo; };
	PontoNaval& get_ponto_pn(int pos)	{ return ponto_pn[pos]; };
	PontoNaval& get_ponto_pn()			{ return *ponto_pn; };
	int get_vector_size()				{ return this->vector_size; };
};

