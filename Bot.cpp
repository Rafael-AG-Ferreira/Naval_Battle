#include "Bot.h"

Bot::Bot()
{
}

Bot::~Bot()
{
}

void Bot::turno_bot(Jogador& JJ)
{
	gera_tiros_bot(JJ);
	verifica_frota(JJ);
}

void Bot::gera_tiros_bot(Jogador& JJ)
{
	int i, j, x, yy;
	char y;
	char z = 'O';
	bool flag;
	bool is_equal;

	get_sistema().Clear_S();
	cout << "O computador vai lancar os seus tiros" << endl << endl;

	for (i = 0; i < 3; i++)
	{
		flag = false;
		do
		{
			is_equal = false;
			x = gera_num_aleatorio(1, get_tabuleiro().Get_Columns());
			y = gera_char_aleatrio();
			obtem_y_yy(y, yy);

			if (get_total_tiros() == 0)
			{
				flag = true;
			}
			else
			{
				for (j = 0; j < (get_total_tiros()); j++)
				{
					if ((x == get_array_tiros(j).Get_X()) && (y == get_array_tiros(j).Get_Y()))
					{
						flag = false;
						obtem_y_yy(y, yy);
						is_equal = true;
					}
					if (((x != get_array_tiros(j).Get_X()) || (y != get_array_tiros(j).Get_Y())) && (is_equal == false))
					{
						set_tiros(i, x, y, '.');
						flag = true;
					}
				}
			}
		} while (flag == false);
		set_total_tiros(1);
		check_char_tiros(JJ, x, y, i);
		Sleep(1000);
		cout << "Tiro Computador #" << (i + 1) << " ->  " << get_tiros(i).Get_X() << "," << get_tiros(i).Get_Y() << ";" << endl;
		verifica_frota(JJ);
		if (get_winner() == 1) { break; }
	}
}

char Bot::gera_char_aleatrio()
{
	int max, random;

	max = (get_tabuleiro().Get_Columns());
	random = (1 + (rand() % max));
	random += 64;
	return random;
}

void Bot::check_char_tiros(Jogador& JJ, int x, char y, int iteracao)
{
	int j, yy;
	int flag[3] = { 0,0,0 };
	obtem_y_yy(y, yy);

	for (j = 0; j < 25; j++)
	{
		if ((x == JJ.get_array_barcos(j).Get_X()) && y == JJ.get_array_barcos(j).Get_Y())
		{
			set_tiros(iteracao, x, y, 'T');
			set_array_tiros(x, y, 'T');
			
			get_tabuleiro().SetCell_tpv(yy, x, 'T');
			JJ.set_array_barcos(j, x, y, 'T');
			JJ.get_tabuleiro().SetCell(yy, x, 'T');
			flag[iteracao] = 1;
		}

		else if ((x != JJ.get_array_barcos(j).Get_X()) && (y != JJ.get_array_barcos(j).Get_Y()) && (flag[iteracao] == 0))
		{
			set_tiros(iteracao, x, y, 'A');
			set_array_tiros(x, y, 'A');

			get_tabuleiro().SetCell_tpv(yy, x, 'A');
			JJ.get_tabuleiro().SetCell(yy, x, 'A');
		}
	}
}

void Bot::gera_frota_bot()
{
	int i, x, yy;
	int generated_x[11];
	int pos_vetor_barcos = 0;
	char y, z;
	char generated_y[11];
	char orientacao = NULL;
	z = 'O';
	bool controlo_sobreposicao_adjacencia = false;
	bool controlo_barco_orientado = false;
	string computador_pensante = "O computador esta a pensar, por favor, aguarde um pouco";
	int conta_computador_pensante = 0;
	get_sistema().Clear_S();
	cout << "O computador vai posicionar os seus barcos" << endl;

	for (i = 0; i < 11; i++)
	{
		controlo_sobreposicao_adjacencia = false;
		controlo_barco_orientado = false;
		do
		{
			get_sistema().Clear_S();
			conta_computador_pensante += 1;
			computador_pensante += '.';
			if ((conta_computador_pensante % 3) == 0)
			{
				computador_pensante += '\n';
			}
			cout << computador_pensante << endl;
			Sleep(80);
			x = gera_num_aleatorio(1, get_tabuleiro().Get_Columns());
			y = gera_char_aleatrio();
			generated_x[i] = x;
			generated_y[i] = y;

			obtem_y_yy(y, yy);
			if (i == 0)
			{
				orientacao = gera_orientacao_nseo_aleatrio();
				controlo_barco_orientado = false;
				set_pos_porta_orientado_bot(x, y, z, orientacao, i, controlo_barco_orientado, pos_vetor_barcos, controlo_sobreposicao_adjacencia);
				controlo_sobreposicao_adjacencia = true;
			}

			if ((i > 0) && (i < 7))
			{
				orientacao = gera_orientacao_se_aleatrio();
				controlo_barco_orientado = false;
				set_pos_barco_orientado_bot(x, y, z, orientacao, i, controlo_barco_orientado, pos_vetor_barcos, controlo_sobreposicao_adjacencia);
			}

			if (i > 6)
			{
				controlo_sobreposicao_adjacencia = false;
				proteje_sobreposicao_barcos(pos_vetor_barcos, controlo_sobreposicao_adjacencia, x, y);
				controlo_barco_orientado = true;

				if ((controlo_sobreposicao_adjacencia) && (controlo_barco_orientado))
				{
					get_tabuleiro().SetCell(yy, x, z);
					get_frota(i).set_ponto_pn(x, y, z);
					set_array_barcos(pos_vetor_barcos, x, y, z);

					if (i < 10)
					{
						pos_vetor_barcos++;
					}
				}
			}

			if ((!controlo_sobreposicao_adjacencia) || (!controlo_barco_orientado))
			{
				x = gera_num_aleatorio(1, get_tabuleiro().Get_Columns());
				y = gera_char_aleatrio();
				generated_x[i] = x;
				generated_y[i] = y;
				if ((i > 4) && (i < 10))
				{
					orientacao = gera_orientacao_se_aleatrio();
				}
				if (i > 9)
				{
					orientacao = gera_orientacao_nseo_aleatrio();
				}
				obtem_y_yy(y, yy);
			}
		} while ((!controlo_sobreposicao_adjacencia) || (!controlo_barco_orientado));
	}
	cout << "O computador ja posicionou os seus barcos." << endl ;
	get_sistema().Pausa();
	get_sistema().Clear_S();
}

char Bot::gera_orientacao_se_aleatrio() const
{
	int random;
	char orientacao;

	random = (gera_num_aleatorio(1, 10));

	if (random % 2 == 0)
	{
		orientacao = 'S';
	}
	else
	{
		orientacao = 'E';
	}

	return orientacao;
}

char Bot::gera_orientacao_nseo_aleatrio() const
{
	int random;
	char orientacao = NULL;

	random = (gera_num_aleatorio(1, 4));

	switch (random)
	{
	case 1:
		orientacao = 'N';
		break;
	case 2:
		orientacao = 'S';
		break;
	case 3:
		orientacao = 'E';
		break;
	case 4:
		orientacao = 'O';
		break;
	}

	return orientacao;
}

void Bot::set_pos_barco_orientado_bot(int X, char Y, char Z, char ORIENTACAO, int ITERACAO, bool& controlo_dentro_tabuleiro, int& pos_vetor_barcos, bool& sobreposicao_adjacencia)
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
}

void Bot::set_pos_porta_orientado_bot(int X, char Y, char Z, char ORIENTACAO, int ITERACAO, bool& controlo_dentro_tabuleiro, int& pos_vetor_barcos, bool& sobreposicao_adjacencia)
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
				controlo_dentro_tabuleiro = true;
				pos_vetor_barcos++;
				j = 0;
			}
		}
		break;
	}
}
