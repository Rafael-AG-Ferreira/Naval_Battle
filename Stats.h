#pragma once
#include <ctime>
#include <iostream>
#include "PontoNaval.h"

using namespace std;

class Stats
{
private:
	//Variáveis para dados estatísticos
	float percentagem_acerto;
	int total_tiros;
	clock_t start_t;
	clock_t end_t;
	clock_t total_t;
	int minutos_jogo;
	int segundos_jogo;
	float percentagem_frota_intacta;
public:
	//Construtor e Destrutor
	Stats();
	~Stats();

	//SETTERS
	void set_percentagem_acerto();
	void set_total_tiros(int TOTAL_TIROS);
	void set_start_t();
	void set_end_t();
	void set_total_t();
	void set_minutos(int MIN);
	void set_segundos(int SEG);
	void set_loaded_total_t(int minutos_jogo, int segundos_jogo);
	void set_percentagem_frota_intacta(int NUM);
	
	//GETTERS
	float get_percentagem_acerto();
	int get_minutos_jogo();
	int get_segundos_jogo();
	float get_percentagem_frota_intacta();

	//Função SHOW
	void show_time_elapsed();
};

