#include "Jogador.h"

Jogador::Jogador()
{
	int i = 0; 
	int k = 1;

	nome = "No Name Inserted";
	this->jogadas = 0;

	for (i = 0; i < 3; i++)
	{
		this->tiros[i].Set_C('.');
		this->tiros[i].Set_X(1);
		this->tiros[i].Set_Y(1);
	}
}

Jogador::Jogador(string NOME, int JOGADAS, int SIZE_TIROS)
{
	int i = 0;
	int k = 1;

	this->nome = NOME;
	this->jogadas = JOGADAS;

	for (i = 0; i < SIZE_TIROS; i++)
	{
		this->tiros[i].Set_C('.');
		this->tiros[i].Set_X(0);
		this->tiros[i].Set_Y(0);
	}
}

Jogador::~Jogador()
{
}

void Jogador::set_nome(string NOME)
{
	this->nome = NOME;
}

void Jogador::set_jogadas(int JOGADAS)
{
	this->jogadas += JOGADAS;
}

void Jogador::set_tiros(int i, int x, char y, char z)
{
	this->tiros[i].Set_C(z);
	this->tiros[i].Set_X(x);
	this->tiros[i].Set_Y(y);
}

void Jogador::set_array_tiros(int x, char y, char z)
{
	this->array_tiros[(total_tiros-1)].Set_PN(x, y, z);
}

void Jogador::set_array_tiros(int pos, int x, char y, char z)
{
	this->array_tiros[pos].Set_PN(x, y, z);
}

void Jogador::set_total_tiros(int TIROS)
{
	this->total_tiros += TIROS;
}

void Jogador::set_winner(int num)
{
	this->winner = num;
}

void Jogador::set_turno(int TURNO)
{
	this->turno = TURNO;
}

void Jogador::set_array_barcos(int pos_barco, int x, char y, char z)
{
	this->array_barcos[pos_barco].Set_PN(x, y, z);
}

string Jogador::get_nome() const
{
	return this->nome;
}

int Jogador::get_jogadas() const
{
	return this->jogadas;
}

Barco& Jogador::get_frota(int pos)
{
	switch (pos)
	{
	case 0:
		return all_boats.get_porta_avioes_().get_porta_avioes();
		break;
	case 1:
		return all_boats.get_couracados().get_couracado();
		break;
	case 2:
		return all_boats.get_cruzadores(0).get_cruzador();
		break;
	case 3:
		return all_boats.get_cruzadores(1).get_cruzador();
		break;
	case 4:
		return all_boats.get_contratorpedeiros(0).get_contratorpedeiro();
		break;
	case 5:
		return all_boats.get_contratorpedeiros(1).get_contratorpedeiro();
		break;
	case 6:
		return all_boats.get_contratorpedeiros(2).get_contratorpedeiro();
		break;
	case 7:
		return all_boats.get_submarinos(0).get_submarino();
		break;
	case 8:
		return all_boats.get_submarinos(1).get_submarino();
		break;
	case 9:
		return all_boats.get_submarinos(2).get_submarino();
		break;
	case 10:
		return all_boats.get_submarinos(3).get_submarino();
		break;
	default:
		return all_boats.get_submarinos(0).get_submarino();
	}
}

PontoNaval Jogador::get_tiros(int num_tiro) const
{
	return this->tiros[num_tiro];
}

PontoNaval Jogador::get_array_tiros(int num_tiro) const
{
	return this->array_tiros[num_tiro];
}

PontoNaval Jogador::get_array_barcos(int num_barco) const
{
	return this->array_barcos[num_barco];
}

int Jogador::get_total_tiros()
{
	return this->total_tiros;
}

int Jogador::get_winner()
{
	return this->winner;
}

int Jogador::get_turno()
{
	return this->turno;
}

Tabuleiro& Jogador::get_tabuleiro()
{
	return this->tabuleiro;
}

Stats& Jogador::get_stats()
{
	return this->stats;
}

void Jogador::Show_tabuleiros()
{
	this->tabuleiro.Print_Two_Tables(tabuleiro);
}

bool Jogador::proteje_sobreposicao_barcos(int pos_frota, bool& flag, int X, char Y)
{
	flag = true;
	int i;
	if (pos_frota != 0)
	{
		for (i = 0; i < pos_frota; i++)
		{
			if ((X == (get_array_barcos(i).Get_X() - 1)) && (Y == (get_array_barcos(i).Get_Y() - 1)))		//[X][ ][ ]
			{																								//[ ][ ][ ]
				flag = false;																				//[ ][ ][ ]
			}

			if ((X == (get_array_barcos(i).Get_X() - 1)) && (Y == (get_array_barcos(i).Get_Y())))			//[ ][X][ ]
			{																								//[ ][ ][ ]
				flag = false;																				//[ ][ ][ ]
			}

			if ((X == (get_array_barcos(i).Get_X() - 1)) && (Y == (get_array_barcos(i).Get_Y() + 1)))		//[ ][ ][X]
			{																								//[ ][ ][ ]
				flag = false;																				//[ ][ ][ ]
			}

			if ((X == (get_array_barcos(i).Get_X())) && (Y == (get_array_barcos(i).Get_Y() - 1)))			//[ ][ ][ ]
			{																								//[X][ ][ ]
				flag = false;																				//[ ][ ][ ]
			}

			if ((X == get_array_barcos(i).Get_X()) && (Y == get_array_barcos(i).Get_Y()))					//[ ][ ][ ]
			{																								//[ ][X][ ]
				flag = false;																				//[ ][ ][ ]
			}

			if ((X == (get_array_barcos(i).Get_X())) && (Y == (get_array_barcos(i).Get_Y() + 1)))			//[ ][ ][ ]
			{																								//[ ][ ][X]
				flag = false;																				//[ ][ ][ ]
			}

			if ((X == (get_array_barcos(i).Get_X() + 1)) && (Y == (get_array_barcos(i).Get_Y() - 1)))		//[ ][ ][ ]
			{																								//[ ][ ][ ]
				flag = false;																				//[X][ ][ ]
			}

			if ((X == (get_array_barcos(i).Get_X() + 1)) && (Y == (get_array_barcos(i).Get_Y())))			//[ ][ ][ ]
			{																								//[ ][ ][ ]
				flag = false;																				//[ ][X][ ]
			}

			if ((X == (get_array_barcos(i).Get_X() + 1)) && (Y == (get_array_barcos(i).Get_Y() + 1)))		//[ ][ ][ ]
			{																								//[ ][ ][ ]
				flag = false;																				//[ ][ ][X]
			}
		}
	}
	return flag;
}

void Jogador::verifica_frota(Jogador& JJ)
{
	int i;
	int counter = 0;

	for (i = 0; i < 25; i++)
	{
		if (JJ.get_array_barcos(i).Get_C() == 'T')
		{
			counter++;
		}
	}

	if (counter == 25)
	{
		set_winner(1);
	}
}

void Jogador::obtem_y_yy(char& y, int& yy)
{
	if ((y > 96) && (y < 123))
	{
		y -= 32;
	}
	yy = (y - 64);
}

int Jogador::gera_num_aleatorio(int min, int max) const
{
	int random;

	random = min + (rand() % (max - min + 1));

	return random;
}

void Jogador::set_pos_porta_orientado_pl1(int X, char Y, char Z, char ORIENTACAO, int ITERACAO, bool& controlo_dentro_tabuleiro, int& pos_vetor_barcos, bool& sobreposicao_adjacencia)
{
	int i = 0;
	int j = 1;
	int k = 0;
	int l = 0;
	int yy = (Y - 64);
	int vector_size = (get_frota(ITERACAO).get_vector_size());
	int aux_pos_vetor_barcos = pos_vetor_barcos;
	bool keep_cicle = true;

	switch (ORIENTACAO)
	{
	case ('N'):
		for (i = 0; i < vector_size; i++)//////////////// Verifica Sobreposição e Adjacência (NORTE)
		{
			if (i == 2) { k = 1; }
			if (i > 2) { l++; k = 0; }
			if (keep_cicle)
			{
				proteje_sobreposicao_barcos(aux_pos_vetor_barcos, sobreposicao_adjacencia, (X - l), (Y - j + k));
			}
			if (sobreposicao_adjacencia) { aux_pos_vetor_barcos++; }
			if (!sobreposicao_adjacencia) { keep_cicle = false; }
			j = 0;
		}
		if ((Y == 'A') || (Y == 'J')) { controlo_dentro_tabuleiro = false; break; }
		j = 1;
		k = 0;
		l = 0;
		for (i = 0; i < vector_size; i++)////////////////Cria o Porta-Aviões (NORTE)
		{
			if (((X - 3) >= 0) && (sobreposicao_adjacencia))
			{
				if (i == 2) { k = 1; }
				if (i > 2) { l++; k = 0; }
				get_frota(ITERACAO).get_ponto_pn(i).Set_PN((X - l), (Y - j + k), Z);
				get_tabuleiro().SetCell((yy - j + k), (X - l), Z);
				set_array_barcos(pos_vetor_barcos, (X - l), (Y - j + k), Z);
				controlo_dentro_tabuleiro = true;
				pos_vetor_barcos++;
				j = 0;
			}
		}
		break;
	case ('S'):
		for (i = 0; i < vector_size; i++)//////////////// Verifica Sobreposição e Adjacência (SUL)
		{
			if (i == 2) { k = 1; }
			if (i > 2) { l++; k = 0; }
			if (keep_cicle)
			{
				proteje_sobreposicao_barcos(aux_pos_vetor_barcos, sobreposicao_adjacencia, (X + l), (Y - j + k));
			}
			if (sobreposicao_adjacencia) { aux_pos_vetor_barcos++; }
			if (!sobreposicao_adjacencia) { keep_cicle = false; }
			j = 0;
		}
		if ((Y == 'A') || (Y == 'J')) { controlo_dentro_tabuleiro = false; break; }
		j = 1;
		k = 0;
		l = 0;
		for (i = 0; i < vector_size; i++) ////////////////Cria o Porta-Aviões (SUL)
		{
			if ((((X - 1) + 3) <= 10) && (sobreposicao_adjacencia))
			{
				if (i == 2) { k = 1; }
				if (i > 2) { l++; k = 0; }
				get_frota(ITERACAO).get_ponto_pn(i).Set_PN((X + l), (Y - j + k), Z);
				get_tabuleiro().SetCell((yy - j + k), (X + l), Z);
				set_array_barcos(pos_vetor_barcos, (X + l), (Y - j + k), Z);
				controlo_dentro_tabuleiro = true;
				pos_vetor_barcos++;
				j = 0;
			}
		}
		break;

	case ('E'):
		for (i = 0; i < vector_size; i++)//////////////// Verifica Sobreposição e Adjacência (ESTE)
		{
			if (i == 2) { k = 1; }
			if (i > 2) { l++; k = 0; }
			if (keep_cicle)
			{
				proteje_sobreposicao_barcos(aux_pos_vetor_barcos, sobreposicao_adjacencia, (X - j + k), (Y + l));
			}
			if (sobreposicao_adjacencia) { aux_pos_vetor_barcos++; }
			if (!sobreposicao_adjacencia) { keep_cicle = false; }
			j = 0;
		}
		if ((X == 1) || (X == 10)) { controlo_dentro_tabuleiro = false; break; }
		j = 1;
		k = 0;
		l = 0;
		for (i = 0; i < (vector_size); i++)////////////////Cria o Porta-Aviões (ESTE)
		{
			if ((((yy - 1) + 3) <= 10) && (sobreposicao_adjacencia))
			{
				if (i == 2) { k = 1; }
				if (i > 2) { l++; k = 0; }
				get_frota(ITERACAO).get_ponto_pn(i).Set_PN((X - j + k), (Y + l), Z);
				get_tabuleiro().SetCell((yy + l), (X - j + k), Z);
				set_array_barcos(pos_vetor_barcos, (X - j + k), (Y + l), Z);
				controlo_dentro_tabuleiro = true;
				pos_vetor_barcos++;
				j = 0;
			}
		}
		break;
	case ('O'):
		for (i = 0; i < vector_size; i++) //////////////// Verifica Sobreposição e Adjacência (OESTE)
		{
			if (i == 2) { k = 1; }
			if (i > 2) { l++; k = 0; }
			if (keep_cicle)
			{
				proteje_sobreposicao_barcos(aux_pos_vetor_barcos, sobreposicao_adjacencia, (X - j + k), (Y - l));
			}
			if (sobreposicao_adjacencia) { aux_pos_vetor_barcos++; }
			if (!sobreposicao_adjacencia) { keep_cicle = false; }
			j = 0;
		}
		if ((X == 1) || (X == 10)) { controlo_dentro_tabuleiro = false; break; }
		j = 1;
		k = 0;
		l = 0;
		for (i = 0; i < (vector_size); i++) ////////////////Cria o Porta-Aviões (OESTE)
		{
			if (((yy - 3) >= 0) && (sobreposicao_adjacencia))
			{
				if (i == 2) { k = 1; }
				if (i > 2) { l++; k = 0; }
				get_frota(ITERACAO).get_ponto_pn(i).Set_PN((X - j + k), (Y - l), Z);
				get_tabuleiro().SetCell((yy - l), (X - j + k), Z);
				set_array_barcos(pos_vetor_barcos, (X - j + k), (Y - l), Z);
				controlo_dentro_tabuleiro = true;;
				pos_vetor_barcos++;
				j = 0;
			}
		}
		break;
	}

	if ((!controlo_dentro_tabuleiro) && (sobreposicao_adjacencia))
	{
		cout << "As coordenadas inseridas, quando conjugadas com a orientacao pretendida, colocam o barco fora do tabuleiro" << endl;
		get_sistema().Pausa();
	}
}

void Jogador::set_pos_barco_orientado_pl1(int X, char Y, char Z, char ORIENTACAO, int ITERACAO, bool& controlo_dentro_tabuleiro, int& pos_vetor_barcos, bool& sobreposicao_adjacencia)
{
	int i = 0;
	int yy = (Y - 64);
	int vector_size = (get_frota(ITERACAO).get_vector_size());
	int difference_south = ((get_tabuleiro().Get_Rows()) - (X));
	int difference_east = ((get_tabuleiro().Get_Columns()) - (yy));
	int aux_pos_vetor_barcos = pos_vetor_barcos;
	bool keep_cicle = true;
	switch (ORIENTACAO)
	{
	case ('S'):
		for (i = 0; i < vector_size; i++)//////////////// Verifica Sobreposição e Adjacência (SUL)
		{
			if (keep_cicle)
			{
				proteje_sobreposicao_barcos(aux_pos_vetor_barcos, sobreposicao_adjacencia, (X + i), Y);
			}
			if (sobreposicao_adjacencia) { aux_pos_vetor_barcos++; }
			if (!sobreposicao_adjacencia) { keep_cicle = false; }
		}
		for (i = 0; i < vector_size; i++)////////////////Cria o Barco (SUL)
		{
			if ((ITERACAO < 10) && (vector_size <= difference_south + 1) && (sobreposicao_adjacencia))
			{
				get_frota(ITERACAO).get_ponto_pn(i).Set_PN((X + i), Y, Z);
				get_tabuleiro().SetCell(yy, (X + i), Z);
				set_array_barcos(pos_vetor_barcos, (X + i), Y, Z);
				controlo_dentro_tabuleiro = true;
				pos_vetor_barcos++;
			}
		}
		break;

	case ('E'):
		for (i = 0; i < vector_size; i++)//////////////// Verifica Sobreposição e Adjacência (ESTE)
		{
			if (keep_cicle)
			{
				proteje_sobreposicao_barcos(aux_pos_vetor_barcos, sobreposicao_adjacencia, X, (Y + i));
			}
			if (sobreposicao_adjacencia) { aux_pos_vetor_barcos++; }
			if (!sobreposicao_adjacencia) { keep_cicle = false; }
		}
		for (i = 0; i < (vector_size); i++)////////////////Cria o Barco (ESTE)
		{
			if ((ITERACAO < 10) && (vector_size <= difference_east + 1) && (sobreposicao_adjacencia))
			{
				get_frota(ITERACAO).get_ponto_pn(i).Set_PN(X, (Y + i), Z);
				get_tabuleiro().SetCell((yy + i), X, Z);
				set_array_barcos(pos_vetor_barcos, X, (Y + i), Z);
				controlo_dentro_tabuleiro = true;
				pos_vetor_barcos++;
			}
		}
		break;
	}

	if ((!controlo_dentro_tabuleiro) && (sobreposicao_adjacencia))
	{
		cout << "As coordenadas inseridas, quando conjugadas com a orientacao pretendida, colocam o barco fora do tabuleiro" << endl;
		get_sistema().Pausa();
	}
}

void Jogador::fase_inicial()
{
	get_sistema().Clear_S();
	cout << "Ola " << get_nome() << ", esta prestes a inciar uma \"Batalha Naval\"!" << endl << endl;
	Show_tabuleiros();
	get_sistema().Pausa();
}

void Jogador::inserir_nome_pl1()
{
	string nome;
	get_sistema().Clear_S();
	cout << "Insira o seu nome: " << endl;
	cin.ignore();
	getline(cin, nome);
	set_nome(nome);
}

void Jogador::escolhe_localizacao()
{
	int i = 0;
	int x = 0;
	int pos_vetor_barcos = 0;
	int yy = 0;
	char y = NULL;
	char z = 'O';
	char orientacao = NULL;

	bool controlo_insercao_coord = NULL;
	bool controlo_char_orientacao = true;

	bool controlo_sobreposicao_adjacencia = NULL;

	bool controlo_barco_orientado = true;


	for (i = 0; i < 11; i++)
	{
		controlo_sobreposicao_adjacencia = false;
		do
		{
			get_sistema().Clear_S();
			Show_tabuleiros();
			cout << endl << "Insira as coordenadas (num,letra) onde quer que fique o " << get_frota(i).get_tipo() << endl;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			}
			cin >> x; cin.ignore(); cin >> y;
			obtem_y_yy(y, yy);

			if (i > 0 && i < 7)
			{
				cout << "Insira a OrientaÇão para o barco, Sul (S) ou Este (E)" << endl;
				cin.ignore();
				cin >> orientacao;
				orientacao = toupper(orientacao);
				if ((orientacao != 'S') && (orientacao != 'E'))
				{
					controlo_char_orientacao = false;
					cout << "Orientação Inválida, insira novamente!" << endl;
					get_sistema().Pausa();
				}
			}

			if (i == 0)
			{
				cout << "Insira a OrientaÇão para o barco, Norte (N), Sul (S), Este (E) ou Oeste (O)" << endl;
				cin.ignore();
				cin >> orientacao;
				orientacao = toupper(orientacao);
				if ((orientacao != 'N') && (orientacao != 'S') && (orientacao != 'E') && (orientacao != 'O'))
				{
					controlo_char_orientacao = false;
					cout << "Orientação Inválida, insira novamente!" << endl;
					get_sistema().Pausa();
				}
			}


			if (((x > 0) && (x < 11)) && ((yy > 0) && (yy < 11)))
			{
				controlo_insercao_coord = true;
				if (i == 0)
				{
					controlo_barco_orientado = false;
					set_pos_porta_orientado_pl1(x, y, z, orientacao, i, controlo_barco_orientado, pos_vetor_barcos, controlo_sobreposicao_adjacencia);
					controlo_sobreposicao_adjacencia = true;
				}

				if ((i > 0) && (i < 7))
				{
					controlo_barco_orientado = false;
					controlo_sobreposicao_adjacencia = false;
					set_pos_barco_orientado_pl1(x, y, z, orientacao, i, controlo_barco_orientado, pos_vetor_barcos, controlo_sobreposicao_adjacencia);
				}

				if (i > 6)
				{
					controlo_sobreposicao_adjacencia = false;
					proteje_sobreposicao_barcos(pos_vetor_barcos, controlo_sobreposicao_adjacencia, x, y);
					controlo_barco_orientado = true;
				}
			}

			else
			{
				controlo_insercao_coord = false;
			}

			if (!controlo_insercao_coord)
			{
				controlo_sobreposicao_adjacencia = true;

				cout << "ERRO NA INTRODUCAO" << endl << "As coordenadas inseridas estao num formato errado ou tem valores nao representados no tabuleiro!" << endl
					<< "Insira novamente as coordenadas" << endl;
				get_sistema().Pausa();
			}

			if ((!controlo_sobreposicao_adjacencia))
			{
				cout << "ERRO NA INTRODUCAO" << endl << "As coordenadas inseridas causam sobreposicao com outro barco ou sao adjacentes a outro barco" << endl
					<< "Insira novamente as coordenadas" << endl;
				get_sistema().Pausa();
			}

			if ((controlo_sobreposicao_adjacencia) && (i > 6))
			{
				get_tabuleiro().SetCell(yy, x, z);
				set_array_barcos(pos_vetor_barcos, x, y, z);
				get_frota(i).set_ponto_pn(x, y, z);
				if (i < 10)
				{
					pos_vetor_barcos++;
				}
			}

		} while ((!controlo_insercao_coord) || (!controlo_char_orientacao) || (!controlo_sobreposicao_adjacencia) || (!controlo_barco_orientado));
	}

	get_sistema().Clear_S();
	Show_tabuleiros();
	get_sistema().Pausa();
	get_sistema().Pausa();
}

void Jogador::turno_utilizador(Jogador& JJ)
{
	lanca_tiros_pl1(JJ);
	verifica_frota(JJ);
}

void Jogador::lanca_tiros_pl1(Jogador& JJ)
{
	int i, j, k, x, yy;
	int flag[3] = { 0,0,0 };
	int is_equal;
	char y;
	bool ok;

	for (i = 0; i < 3; i++)
	{
		ok = false;
		do
		{
			is_equal = 0;
			get_sistema().Clear_S();
			Show_tabuleiros();
			cout << endl << "Insira as coordenadas (num,letra) do(s) tiro(s) com que pretende atingir o adversario." << endl
				<< "TIRO " << (i + 1) << " de 3" << endl;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			}
			cin >> x; cin.ignore();
			cin >> y;
			obtem_y_yy(y, yy);

			if (((x > 0) && (x < 11)) && ((yy > 0) && (yy < 11)))
			{
				if (get_total_tiros() == 0)
				{
					ok = true;
				}
				else
				{
					for (k = 0; k < (get_total_tiros()); k++)
					{
						if ((x == get_array_tiros(k).Get_X()) && (y == get_array_tiros(k).Get_Y()))
						{
							cout << "As coordenadas inseridas ja foram utilizadas no tiro #" << k + 1 << "!" << endl << "Insira novamente" << endl;
							get_sistema().Pausa();
							ok = false;
							is_equal = 1;
						}
						if (((x != get_array_tiros(k).Get_X()) || (y != get_array_tiros(k).Get_Y())) && (is_equal == 0))
						{
							ok = true;
						}
					}
				}
			}
		} while (ok == false);
		set_total_tiros(1);
		for (j = 0; j < 25; j++)
		{
			if ((x == JJ.get_array_barcos(j).Get_X()) && y == JJ.get_array_barcos(j).Get_Y())
			{
				set_tiros(i, x, y, 'T');
				set_array_tiros(x, y, 'T');

				get_tabuleiro().SetCell_tpv(yy, x, 'T');
				JJ.set_array_barcos(j, x, y, 'T');
				JJ.get_tabuleiro().SetCell(yy, x, 'T');
				flag[i] = 1;
			}

			else if ((x != JJ.get_array_barcos(j).Get_X()) && (y != JJ.get_array_barcos(j).Get_Y()) && (flag[i] == 0))
			{
				set_tiros(i, x, y, 'A');
				set_array_tiros(x, y, 'A');

				get_tabuleiro().SetCell_tpv(yy, x, 'A');
				JJ.get_tabuleiro().GetCell(x, yy).Set_C('A');
			}
		}
		verifica_frota(JJ);
		if (get_winner() == 1) { break; }
	}
	get_sistema().Clear_S();
	Show_tabuleiros();
	cout << endl;
	get_sistema().Pausa();
}




