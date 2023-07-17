#pragma once
#include "Jogador.h"


class Bot: public Jogador  //Classe que Herda a classe Jogador
{
private:

public:
	//Construtor e Destrutor
	Bot();
	virtual ~Bot();

	//Fun��o que executa outras fun��es relativas ao turno do BOT
	void turno_bot(Jogador& JJ);

	//Fun��es Geradoras
	void gera_tiros_bot(Jogador& JJ);
	char gera_char_aleatrio();
	void gera_frota_bot();
	char gera_orientacao_se_aleatrio() const;
	char gera_orientacao_nseo_aleatrio() const;

	//Fun��o que verifica se o tiro acertou num barco ou n�o
	void check_char_tiros(Jogador& JJ, int x, char y, int iteracao);

	//SETTERS
	void set_pos_barco_orientado_bot(int X, char Y, char Z, char ORIENTACAO, int ITERACAO, bool& controlo_dentro_tabuleiro, int& pos_vetor_barcos, bool& sobreposicao_adjacencia);
	void set_pos_porta_orientado_bot(int X, char Y, char Z, char ORIENTACAO, int ITERACAO, bool& controlo_dentro_tabuleiro, int& pos_vetor_barcos, bool& sobreposicao_adjacencia);
};

