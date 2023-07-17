#pragma once
#include <string>
#include <istream>
#include "Frota.h"
#include "PontoNaval.h"
#include "Tabuleiro.h"
#include "Stats.h"
#include "System.h"

using namespace std;

class Jogador
{
private:
	string nome;
	Tabuleiro tabuleiro;
	int jogadas = 0;
	Frota all_boats;
	PontoNaval tiros[3];
	PontoNaval array_tiros[100];
	PontoNaval array_barcos[25];
	int total_tiros = 0;
	int winner = 0;
	int turno = 0;
	Stats stats;
	System sistema;
public:
	//Construtores e Destrutor
	Jogador();
	Jogador(string NOME, int JOGADAS, int SIZE_TIROS);
	~Jogador();
	//SETTERS
	void set_nome(string NOME);
	void set_jogadas(int JOGADAS);
	void set_tiros(int i, int x, char y, char z);
	void set_array_tiros(int x, char y, char z);
	void set_array_tiros(int pos, int x, char y, char z);
	void set_total_tiros(int TIROS);
	void set_winner(int num);
	void set_turno(int TURNO);
	void set_array_barcos(int pos_barco, int x, char y, char z);
	//GETTERS
	string get_nome() const;
	int get_jogadas() const;
	Barco& get_frota(int pos);
	PontoNaval get_tiros(int num_tiro) const;
	PontoNaval get_array_tiros(int num_tiro) const;
	PontoNaval get_array_barcos(int num_barco) const;
	int get_total_tiros();
	int get_winner();
	int get_turno();
	Tabuleiro& get_tabuleiro();
	Stats& get_stats();
	System get_sistema() { return this->sistema; };

	//FUNÇÔES AUXILIARES
	void Show_tabuleiros();
	bool proteje_sobreposicao_barcos(int pos_frota, bool& flag, int X, char Y);
	void verifica_frota(Jogador& JJ);
	void obtem_y_yy(char& y, int& yy);
	int gera_num_aleatorio(int min, int max) const;
	void set_pos_porta_orientado_pl1(int X, char Y, char Z, char ORIENTACAO, int ITERACAO, bool& controlo_dentro_tabuleiro, int& pos_vetor_barcos, bool& sobreposicao_adjacencia);
	void set_pos_barco_orientado_pl1(int X, char Y, char Z, char ORIENTACAO, int ITERACAO, bool& controlo_dentro_tabuleiro, int& pos_vetor_barcos, bool& sobreposicao_adjacencia);
	void fase_inicial();
	void inserir_nome_pl1();
	void escolhe_localizacao();
	void turno_utilizador(Jogador& JJ);
	void lanca_tiros_pl1(Jogador& JJ);
};