#pragma once
#include "Tabuleiro.h"
#include "Jogador.h"
#include "Bot.h"
#include "System.h"
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class Jogo
{
private:
	Jogador Player;
	Bot Computer;
	int primeiro_a_jogar;
	System sistema;
	char sair = NULL;
public:
///////////////////////////////////////Construtor por Defeito e Destrutor
#pragma region Construtor/Destrutor
	Jogo();
	virtual ~Jogo();
#pragma endregion
///////////////////////////////////////Getters
#pragma region Getters
	int get_primeiro_a_jogar();
	Jogador get_player();
	Bot get_computer();
	System get_sistema() { return this->sistema; };
	char get_sair() { return this->sair; };
#pragma endregion
///////////////////////////////////////Setters
#pragma region Setters
	void set_primeiro_a_jogar();
#pragma endregion
///////////////////////////////////////Início do Jogo - Métodos Relacionados com o Menu
#pragma region Menu-Related
	int show_menu();
	bool choose_menu(int escolha);
	void tutorial();
	void Jogo_Novo(int first);
	void re_paint_table_loaded_game();
#pragma endregion
///////////////////////////////////////Métodos Relacionados com o turno do utilizador
#pragma region Turno PL1
	void turno_utilizador();
#pragma endregion
///////////////////////////////////////Métodos Relacionados com o turno do BOT
#pragma region Turno PL2	
	void turno_bot();
#pragma endregion

//////////////////////////////////////Método de Fim de Jogo
#pragma region End
	void fim_jogo();
#pragma endregion
/////////////////////////////////////Leitura e Escrita de/nos ficheiros
#pragma region Read/Save
	void Save(Jogador J);
	void save_nomes(Jogador J, Jogador JJ);
	bool Read(Jogador& J);
	bool read_nomes(Jogador& J, Jogador& JJ);
#pragma endregion
};

