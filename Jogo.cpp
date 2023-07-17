#include "Jogo.h"
#include <iostream>
#include <conio.h>


using namespace std;

Jogo::Jogo()
{
	this->primeiro_a_jogar = (Computer.gera_num_aleatorio(1, 2) - 1);
	this->Computer.set_nome("Computador");
}
Jogo::~Jogo()
{

}

void Jogo::set_primeiro_a_jogar()
{
	this->primeiro_a_jogar = (Computer.gera_num_aleatorio(1, 2) - 1);
}

int Jogo::get_primeiro_a_jogar()
{
	return this->primeiro_a_jogar;
}

Jogador Jogo::get_player()
{
	return this->Player;
}

Bot Jogo::get_computer()
{
	return this->Computer;
}

void Jogo::Jogo_Novo(int first)
{
	Player.get_stats().set_start_t();
	Computer.get_stats().set_start_t();
	switch (first)
	{
	case 0:
		Player.set_turno(1);
		Computer.gera_frota_bot();
		Player.escolhe_localizacao();
		get_sistema().Clear_S();
		cout << "Foi aleatoriamente decidido que o " << Player.get_nome() << ", sera o primeiro a jogar" << endl;
		get_sistema().Pausa();
		do
		{
			turno_utilizador();
			
			cin >> sair;
			sair = toupper(sair);
			if ((Player.get_winner() == 0) && (sair != 'X'))
			{
				turno_bot();
			}
		} while ((Player.get_winner() == 0) && (Computer.get_winner() == 0) && (sair != 'X'));
		Player.get_stats().set_end_t();
		Player.get_stats().set_total_t();
		Computer.get_stats().set_end_t();
		Computer.get_stats().set_total_t();
		break;

	case 1:
		Computer.set_turno(1);
		Computer.gera_frota_bot();
		Player.escolhe_localizacao();
		get_sistema().Clear_S();
		cout << "Foi aleatoriamente decidido que o " << Computer.get_nome() << ", sera o primeiro a jogar" << endl;
		get_sistema().Pausa();
		do
		{
			turno_bot();
			if (Computer.get_winner() == 0)
			{
				turno_utilizador();
				cin >> sair;
				sair = toupper(sair);
			}
		} while ((Player.get_winner() == 0) && (Computer.get_winner() == 0) && (sair != 'X'));
		Player.get_stats().set_end_t();
		Player.get_stats().set_total_t();
		Computer.get_stats().set_end_t();
		Computer.get_stats().set_total_t();
		break;

	default:
		get_sistema().Clear_S();
		cout << "Houve um erro na iniciacao do jogo" << endl << "Vamos tentar novamente!" << endl;
		get_sistema().Pausa();
		set_primeiro_a_jogar();
		Jogo_Novo(get_primeiro_a_jogar());
		break;
	}
}

int Jogo::show_menu()
{
	get_sistema().Clear_S();
	int escolha = 0;
	do
	{
		get_sistema().Clear_S();
		cout << endl << "\t\t\t\t\t\t   BATALHA NAVAL" << endl << endl << endl << endl << endl << endl << endl
			<< "\t\t\t\t\tMENU:" << endl << "\t\t\t\t\tConfiguracao do Jogo:" << endl <<
			"\t\t\t\t\t\t1 - Criar um novo jogo" << endl <<
			"\t\t\t\t\t\t2 - Carregar um jogo existente" << endl <<
			"\t\t\t\t\t\t3 - Ver tutorial do jogo" << endl <<
			"\t\t\t\t\t\t4 - Sair" << endl <<
			"\t\t\t\t\tOpcao: ";
		cin >> escolha;

		if (escolha < 1 || escolha > 4)
		{
			cout << endl << "\t\t\t\t\tEscolha nao valida, tem que inserir valores entre 1 e 4, tal como e apresentado no MENU";
			cout << endl << "\t\t\t\t\tPressione qualquer tecla e, de seguida, volte a escolher uma opcao do MENU" << endl;
			get_sistema().Pausa();
		}

	} while (escolha < 1 || escolha > 4);

	return escolha;
}

bool Jogo::choose_menu(int escolha)
{
	bool conseguiu_ler = true;
	int i = 0;
	string aux_filename;
	char* FILENAME_PL;
	switch (escolha)
	{
	case 1:
		Player.inserir_nome_pl1();
		Player.fase_inicial();
		save_nomes(Player, Computer);
		set_primeiro_a_jogar();
		Jogo_Novo(get_primeiro_a_jogar());
		break;
	case 2:
		conseguiu_ler = false;
		conseguiu_ler = read_nomes(Player, Computer);
		if (conseguiu_ler == true)
		{
			re_paint_table_loaded_game();
			Player.get_stats().set_start_t();
			Computer.get_stats().set_start_t();
			aux_filename = (Player.get_nome() + ".txt");
			FILENAME_PL = &aux_filename[0];
			remove(FILENAME_PL);
			remove("Computador.txt");
			remove("nomes.txt");
			if (Player.get_turno() == 1)
			{
				do
				{
					turno_utilizador();
					cin >> sair;
					sair = toupper(sair);
					if ((Player.get_winner() == 0) && (sair != 'X'))
					{
						turno_bot();
					}
				} while ((Player.get_winner() == 0) && (Computer.get_winner() == 0) && (sair != 'X'));
				Player.get_stats().set_end_t();
				Player.get_stats().set_total_t();
				Computer.get_stats().set_end_t();
				Computer.get_stats().set_total_t();
			}

			else if (Computer.get_turno() == 1)
			{
				do
				{
					turno_bot();
					if (Computer.get_winner() == 0)
					{
						turno_utilizador();
						cin >> sair;
						sair = toupper(sair);
					}
				} while ((Player.get_winner() == 0) && (Computer.get_winner() == 0) && (sair != 'X'));
				Player.get_stats().set_end_t();
				Player.get_stats().set_total_t();
				Computer.get_stats().set_end_t();
				Computer.get_stats().set_total_t();
			}
		}
		break;
	case 3:
		tutorial();
		break;
	case 4:
		cout << "Ate a proxima!" << endl;
		exit(0);
		break;
	default:
		cout << "Out of range";
		break;
	}
	return conseguiu_ler;
}

void Jogo::re_paint_table_loaded_game()
{
	int i = 0;

	for (i = 0; i < 25; i++)
	{
		this->Player.get_tabuleiro().SetCell(Player.get_array_barcos(i).Get_PN());
		this->Computer.get_tabuleiro().SetCell(Computer.get_array_barcos(i).Get_PN());
	}

	for (i = 0; i < Player.get_total_tiros(); i++)
	{
		this->Player.get_tabuleiro().SetCell_tpv((Player.get_array_tiros(i).Get_Int_Y()), (Player.get_array_tiros(i).Get_X()), (Player.get_array_tiros(i).Get_C()));
		this->Computer.get_tabuleiro().SetCell(Player.get_array_tiros(i));
	}
	for (i = 0; i < Computer.get_total_tiros(); i++)
	{
		this->Computer.get_tabuleiro().SetCell_tpv((Computer.get_array_tiros(i).Get_Int_Y()), (Computer.get_array_tiros(i).Get_X()), (Computer.get_array_tiros(i).Get_C()));
		this->Player.get_tabuleiro().SetCell(Computer.get_array_tiros(i));
	}
}

void Jogo::tutorial()
{
	Tabuleiro Tutorial[5];
	get_sistema().Clear_S();;
	cout << "Jogo da Batalha Naval - Tutorial" << endl << endl;
	cout << "\t" << "A Batalha naval e um jogo de tabuleiro de dois jogadores, no qual os jogadores tem de adivinhar" << endl
		<< "em que quadrados estao os navios do oponente. O seu objetivo e afundar os barcos do adversario, sendo" << endl
		<< "que ganha quem derrubar todos os navios adversarios primeiro." << endl << endl
		<< "\t" << "O jogo e jogado com duas grelhas para cada jogador, uma que representa a disposicao dos barcos" << endl
		<< "do proprio jogador, e outra que representa a do oponente." << endl << endl
		<< "\t" << "As grelhas estao identificadas na horizontal por letras e na vertical por numeros, cuja conjuntura" << endl
		<< "representa as coordenadas do \"plano de jogo\". Na grelha da esuqerda, o jogador coloca os seus barcos e sao" << endl
		<< "sao registados (ao longo do jogo) os tiros dados pelos jogadores (na grelha da esquerda os tiros do adversario" << endl 
		<< "e os proprios tiros na grelha da direita)." << endl << endl
		<< "\t" << "Antes do inicio do jogo, cada jogador coloca os seus barcos no seu tabuleiro. O numero de barcos" << endl
		<< "e igual para ambos jogadores e os barcos nao se podem sobrepor nem ser adjacentes entre si. Ou seja, tem que" << endl
		<< "existir pelo menos uma celula livre entre os barcos (inclusive na diagonal). Apos os barcos terem sido posicionados," << endl
		<< "o jogo continua numa serie de turnos (tres tiros para cada jogador). Em cada turno, um jogador bombardeia" << endl
		<< "um quadrado (coordenadas), o qual e identificado pela letra e numero. Na grelha do oponente, e se houver" << endl
		<< "um barco nesse quadrado, e colocado um \'T\' nesse lugar, se nao houver e colocado um \'A\'." << endl;
	get_sistema().Pausa();
	get_sistema().Pausa();
	get_sistema().Clear_S();
	cout << "\".\" Representa um espaco vazio." << endl << "\"O\" Representa um espaco ocupado por um barco." << endl
		<< "\"T\" Tiro num espaco ocupado por um barco." << endl << "\"A\" Tiro num espaco vazio." << endl;
	get_sistema().Pausa();
	get_sistema().Clear_S();
	cout << endl << "Os tipos de barcos sao:" << endl;
	cout << "Porta Avioes (cinco quadrados) -> 1X" << endl;
	Tutorial[0].SetCell(1, 2, 'O'); Tutorial[0].SetCell(1, 3, 'O'); Tutorial[0].SetCell(1, 4, 'O'); Tutorial[0].SetCell(2, 3, 'O'); Tutorial[0].SetCell(3, 3, 'O');
	Tutorial[0].Print_One_Table(); cout << endl;
	get_sistema().Pausa();
	get_sistema().Clear_S();
	cout << endl << "Couracado (quatro quadrados) -> 1X" << endl;
	Tutorial[1].SetCell(4, 3, 'O'); Tutorial[1].SetCell(4, 4, 'O'); Tutorial[1].SetCell(4, 5, 'O'); Tutorial[1].SetCell(4, 6, 'O');
	Tutorial[1].Print_One_Table(); cout << endl;
	get_sistema().Pausa();
	get_sistema().Clear_S();
	cout << endl << "Cruzador (tres quadrados) -> 2X" << endl;
	Tutorial[2].SetCell(1, 4, 'O'); Tutorial[2].SetCell(1, 5, 'O'); Tutorial[2].SetCell(1, 6, 'O');
	Tutorial[2].SetCell(4, 7, 'O'); Tutorial[2].SetCell(5, 7, 'O'); Tutorial[2].SetCell(6, 7, 'O');
	Tutorial[2].Print_One_Table(); cout << endl;
	get_sistema().Pausa();
	get_sistema().Clear_S();
	cout << endl << "Contratorpedeiro (dois quadrados) -> 3X" << endl;
	Tutorial[3].SetCell(1, 1, 'O'); Tutorial[3].SetCell(2, 1, 'O');
	Tutorial[3].SetCell(5, 5, 'O'); Tutorial[3].SetCell(5, 6, 'O');
	Tutorial[3].SetCell(9, 9, 'O'); Tutorial[3].SetCell(10, 9, 'O');
	Tutorial[3].Print_One_Table(); cout << endl;
	get_sistema().Pausa();
	get_sistema().Clear_S();
	cout << endl << "Submarino (um quadrado) -> 4X" << endl;
	Tutorial[4].SetCell(3, 3, 'O');
	Tutorial[4].SetCell(1, 6, 'O');
	Tutorial[4].SetCell(2, 9, 'O');
	Tutorial[4].SetCell(8, 5, 'O');
	Tutorial[4].Print_One_Table(); cout << endl;
	get_sistema().Pausa();
	get_sistema().Clear_S();
	cout << endl << "\t" << "Tal como foi dito anteriormente, o objetivo e afundar os barcos do adversario." << endl
		<< "O jogo e automaticamente gravado no fim de cada jogada, pelo que pode abandonar o mesmo e" << endl
		<< "retomar o jogo mais tarde." << endl
		<< "Nao se esqueca que ganha quem derrubar todos os navios adversarios primeiro!!!" << endl
		<< "Boa Sorte!" << endl << endl;
	get_sistema().Pausa();
	show_menu();
}

void Jogo::turno_utilizador()
{
	Player.turno_utilizador(Computer);
	Player.get_stats().set_end_t();
	Player.get_stats().set_total_t();
	Computer.set_turno(1);
	Player.set_turno(0);
	Player.set_jogadas(1);
	save_nomes(Player, Computer);
	Save(Player);
	Save(Computer);

	if (Player.get_winner() == 0)
	{
		cout << endl << "A sua jogada terminou, agora e a vez do seu adversario!" << endl;
		get_sistema().Pausa();
	}
	if (Player.get_winner() == 1)
	{
		cout << "O Jogo terminou!" << endl;
		get_sistema().Pausa();
	}
	cout << "Deseja gravar o jogo e sair? Se sim prima \"X\", caso contrario prima outra tecla qualquer: " << endl;
}

void Jogo::turno_bot()
{
	Computer.turno_bot(Player);
	Computer.get_stats().set_end_t();
	Computer.get_stats().set_total_t();
	Player.set_turno(1);
	Computer.set_turno(0);
	Computer.set_jogadas(1);
	save_nomes(Player, Computer);
	Save(Player);
	Save(Computer);
	if (Computer.get_winner() == 0)
	{
		Sleep(1000);
		cout << endl << "A jogada do Computador terminou, agora e a sua vez!" << endl;
		get_sistema().Pausa();
	}
	else if (Computer.get_winner() == 1)
	{
		cout << "O Jogo terminou!" << endl;
		get_sistema().Pausa();
	}
}

void Jogo::fim_jogo()
{
	int i, counter = 0;
	string nome;
	int jogadas = 0;
	int jogadas_adversario = 0;
	int tiros = 0;
	float acerto = 0;
	float intacto = 0;
	Tabuleiro Final;
	for (i = 0; i < 25; i++)
	{
		Final.SetCell(Player.get_array_barcos(i).Get_Int_Y(), Player.get_array_barcos(i).Get_X(), 'O');
		Final.SetCell_tpv(Computer.get_array_barcos(i).Get_Int_Y(), Computer.get_array_barcos(i).Get_X(), 'O');
	}

	if (Player.get_winner() == 1)
	{	nome = Player.get_nome();
		jogadas = Player.get_jogadas();
		jogadas_adversario = Computer.get_jogadas();
		tiros = Player.get_total_tiros();
		Player.get_stats().set_total_tiros(tiros);
		Player.get_stats().set_percentagem_acerto();
		acerto = Player.get_stats().get_percentagem_acerto();
		for (i = 0; i < 25; i++)
		{
			if (Player.get_array_barcos(i).Get_C() == 'O')
			{
				counter++;
			}
		}
		Player.get_stats().set_percentagem_frota_intacta(counter);
		intacto = Player.get_stats().get_percentagem_frota_intacta();
	}

	if (Computer.get_winner() == 1)
	{
		nome = Computer.get_nome();
		jogadas = Computer.get_jogadas();
		jogadas_adversario = Player.get_jogadas();
		tiros = Computer.get_total_tiros();
		Computer.get_stats().set_total_tiros(tiros);
		Computer.get_stats().set_percentagem_acerto();
		acerto = Computer.get_stats().get_percentagem_acerto();
		for (i = 0; i < 25; i++)
		{
			if (Computer.get_array_barcos(i).Get_C() == 'O')
			{
				counter++;
			}
		}
		Computer.get_stats().set_percentagem_frota_intacta(counter);
		intacto = Computer.get_stats().get_percentagem_frota_intacta();
	}

	get_sistema().Clear_S();
	cout << "\t\t\t\t\tO vencedor e " << nome << "!" << endl
		<< "\t   Parabens. Conseguiu afundar toda a frota do adversario a " << jogadas << char(166) <<" jogada, com " << tiros << " tiros." << endl;
	cout.setf(ios::floatfield, ios::fixed);
	cout << "\t\t       Conseguiu obter " << setprecision(2) << acerto << "% de acerto com os seus tiros." << endl;
	cout << "\t\t         Conseguiu manter " << setprecision(2) << intacto << "% da sua frota intacta." << endl << endl;
	

	sistema.Pausa();
	sistema.Clear_S();
	cout << "\t    Abaixo e possviel perceber a colocacao inicial das frotas de ambos os jogadores." << endl << endl;

	Final.Print_Two_Tables(Final);
	cout << endl << endl;

	if (Player.get_winner())
	{
		Player.get_stats().show_time_elapsed();
	}
	else if (Computer.get_winner())
	{
		Computer.get_stats().show_time_elapsed();
	}

	cout << "\n\t\t\t\t\t   Ate a proxima!" << endl;
	get_sistema().Pausa();

}

#pragma region  Read/Save
void Jogo::Save(Jogador J)
{
	int i;
	ofstream os;

	string nome_ficheiro = (J.get_nome() + ".txt");
	os.open(nome_ficheiro);
	if (!os)
	{
		cout << "ERRO: nao e possível abrir o ficheiro " << nome_ficheiro << endl;
	}
	os << J.get_turno() << endl;		//Turno
	os << endl;
	os << J.get_total_tiros() << endl;	//Tiros			
	os << endl;
	os << J.get_jogadas() << endl;		//Jogadas
	os << endl;
	os << J.get_stats().get_minutos_jogo() << ":" << J.get_stats().get_segundos_jogo() << endl;
	os << endl;
	for (i = 0; i < 25; i++)			//Pontos Frota Submarinos (x,y,char)
	{
		os << J.get_array_barcos(i).Get_X() << "," << J.get_array_barcos(i).Get_Y() << "," << J.get_array_barcos(i).Get_C() << "*";
		if ((i == 4) || (i == 8) || (i == 11) || (i == 14) || (i == 16) || (i == 18) || (i == 20) || (i > 20))
		{
			os << endl;
		}
	}
	os << endl;
	if ((J.get_jogadas()) != 0)			//Pontos Total de Tiros (x,y,char)
	{
		for (i = 0; i < J.get_total_tiros(); i++)
		{
			os << J.get_array_tiros(i).Get_X() << "," << J.get_array_tiros(i).Get_Y() << "," << J.get_array_tiros(i).Get_C() << endl;
		}
	}

	os.close();
}


void Jogo::save_nomes(Jogador J, Jogador JJ)
{
	ofstream os;

	string nome_ficheiro = ("nomes.txt");
	os.open("nomes.txt");
	if (!os)
	{
		cout << "ERRO: nao e possível abrir o ficheiro " << nome_ficheiro << endl;
	}

	os << J.get_nome() << endl;
	os << JJ.get_nome();

	os.close();
}


bool Jogo::Read(Jogador& J)
{
	int turno, total_tiros, jogadas, minutos, segundos;
	int a, i, j, k, l, x;
	char b, c, y, z;
	bool ficheiro_dados = true;
	ifstream is;
	

	is.open((J.get_nome() + ".txt"));
	if (!is)
	{
		cout << endl << "ERRO: nao e possivel abrir o ficheiro " << J.get_nome() << ".txt" << endl;
		get_sistema().Pausa();
		ficheiro_dados = false;
	}

	if (ficheiro_dados)
	{
		is >> turno;
		J.set_turno(turno);

		is >> total_tiros;
		J.set_total_tiros(total_tiros);

		is >> jogadas;
		J.set_jogadas(jogadas);

		is >> minutos; is.ignore();
		is >> segundos;

		for (i = 0; i < 25; i++)				//Inserção dos Pontos no Array de Barcos (x,y,char)
		{
			is >> x; is.ignore();
			is >> y; is.ignore();
			is >> z; is.ignore();

			J.set_array_barcos(i, x, y, z);
		}
		l = k = 0;
		for (i = 0; i < 25; i++)				//Inserção dos Pontos nos Barcos propriamente ditos (x,y,char)
		{
			a = J.get_array_barcos(i).Get_X();
			b = J.get_array_barcos(i).Get_Y();
			c = J.get_array_barcos(i).Get_C();
			J.get_frota(k).get_ponto_pn(l).Set_PN(a, b, c);
			l++;
			if ((i == 4) || (i == 8) || (i == 11) || (i == 14) || (i == 16) || (i == 18) || (i == 20) || (i > 20))
			{
				k++;
				l = 0;
			}
		}
		
		for (j = 0; j < total_tiros; j++)
		{
			is >> x; is.ignore();
			is >> y; is.ignore();
			is >> z;
			J.set_array_tiros(j, x, y, z);
		}
	}
	is.close();

	return ficheiro_dados;
}
bool Jogo::read_nomes(Jogador& J, Jogador& JJ)
{
	bool ficheiro_nomes = true;
	bool ficheiro_dados = true;
	ifstream is;

	string nome_player1, nome_player2;

	is.open("nomes.txt");
	if (!is)
	{
		cout << endl << "ERRO: nao e possivel abrir o ficheiro \"nomes.txt\"" << endl;
		get_sistema().Pausa();
		get_sistema().Pausa();
		ficheiro_nomes = false;
	}

	if (ficheiro_nomes)
	{
		getline(is, nome_player1, '\n');
		J.set_nome(nome_player1);

		getline(is, nome_player2, '\n');
		JJ.set_nome(nome_player2);

		if (!ficheiro_dados)
		{
			ficheiro_nomes = false;
		}
	}
	is.close();

	if (ficheiro_nomes == true)
	{
		ficheiro_dados = Read(J);
		ficheiro_dados = Read(JJ);
	}

	return ficheiro_nomes;
}
#pragma endregion


















