#pragma once
#include "Submarino.h"
#include "Contratorpedeiro.h"
#include "Cruzador.h"
#include "Couracado.h"
#include "Porta_Avioes.h"
class Frota
{
//Declaração da quantidade e tipo de barcos
private:
	Submarino submarinos[4];
	Contratorpedeiro contratorpedeiros[3];
	Cruzador cruzadores[2];
	Couracado couracados;
	Porta_Avioes porta_avioes_;
public:
	//Construtor e Destrutor
	Frota();
	virtual ~Frota();

	//GETTERS
	Submarino& get_submarinos(int num_sub);
	Contratorpedeiro& get_contratorpedeiros(int num_contra);
	Cruzador& get_cruzadores(int num_cruz);
	Couracado& get_couracados();
	Porta_Avioes& get_porta_avioes_();
};


