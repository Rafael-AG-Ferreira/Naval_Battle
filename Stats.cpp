#include "Stats.h"

Stats::Stats()
{
	this->start_t = 0;
	this->end_t = 0;
	this->total_t = 0;
	this->percentagem_acerto = 0;
	this->total_tiros = 0;
	this->minutos_jogo = 0;
	this->segundos_jogo = 0;
	this->percentagem_frota_intacta = 0;
}

Stats::~Stats()
{
}

void Stats::set_start_t()
{
	this->start_t = clock();
}

void Stats::set_end_t()
{
	this->end_t = clock();
}

void Stats::set_total_t()
{
	this->total_t = (end_t - start_t) / CLOCKS_PER_SEC;
	this->minutos_jogo = (total_t / 60);
	this->segundos_jogo = (total_t % 60);
}

void Stats::set_minutos(int MIN)
{
	this->minutos_jogo = MIN;
}

void Stats::set_segundos(int SEG)
{
	this->segundos_jogo = SEG;
}

void Stats::set_loaded_total_t(int minutos_jogo, int segundos_jogo)
{
	this->total_t = (end_t - start_t) / CLOCKS_PER_SEC;

	int total_gravado = ((minutos_jogo * 60) + segundos_jogo);

	minutos_jogo = 0;
	segundos_jogo = 0;

	this->total_t += total_gravado;
}

void Stats::set_percentagem_frota_intacta(int NUM)
{
	this->percentagem_frota_intacta = (((float)NUM * 100) / (float)25);
}

float Stats::get_percentagem_acerto()
{
	return this->percentagem_acerto;
}

int Stats::get_minutos_jogo()
{
	return this->minutos_jogo;
}

int Stats::get_segundos_jogo()
{
	return this->segundos_jogo;
}

float Stats::get_percentagem_frota_intacta()
{
	return this->percentagem_frota_intacta;
}

void Stats::set_percentagem_acerto()
{
	this->percentagem_acerto = ((float)2500 / (float)total_tiros);
}

void Stats::set_total_tiros(int TOTAL_TIROS)
{
	this->total_tiros = TOTAL_TIROS;
}

void Stats::show_time_elapsed()
{
	cout << "\t\t      O jogo teve a duração total de " << minutos_jogo << " minutos e " << segundos_jogo << " segundos." << endl << endl;
}
