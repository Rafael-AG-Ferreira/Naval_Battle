#include <cstdio>
#include <cstring>
#include "Jogo.h"
#include "System.h"
#include "lab.h"
using namespace std;
void imagem_inicial();

//Aluno:					Rafael António Gonçalves Ferreira
//Número Mecanográfico: 	72951
//Email:					al72951@utad.eu

int main(void)
{
	System sistema;
	char fim_jogo = NULL;															//Variável de controlo que permite realizar um novo jogo imediatamente após a finalização de um jogo anterior
	int escolha;																	//Variável que representa a escolha do MENU
	bool conseguiu_ler_ficheiro = false;											//Variável relativa à leitura de ficheiros;
	string aux_filename;															//Variável para auxiliar a eliminação de ficheiros
	char* FILENAME_PL;																//Variável para auxiliar a eliminação de ficheiros
	char FILENAME_BOT[] = { "Computador.txt" }, FILENAME_NAMES[] = { "nomes.txt" }; //Variável para auxiliar a eliminação de ficheiros
	Jogo *A = new Jogo;																// Jogo dinâmico para que possa ser jogado sucessivamente sem fechar a consola;
	imagem_inicial();																// Parte "estética" na iniciação do jogo
	Sleep(5000);

	srand(unsigned int(time(NULL)));

	escolha = (A->show_menu());
	do
	{
		conseguiu_ler_ficheiro = A->choose_menu(escolha);
		if (!conseguiu_ler_ficheiro)
		{
			do
			{
				A->~Jogo();
				Jogo* A;
				A = new Jogo;
				escolha = 0;
				escolha = (A->show_menu());
				conseguiu_ler_ficheiro = A->choose_menu(escolha);
			} while (!conseguiu_ler_ficheiro);
		}

		if ((A->get_player().get_winner() == 1) || (A->get_computer().get_winner() == 1))
		{
			A->fim_jogo();
			aux_filename = (A->get_player().get_nome() + ".txt");
			FILENAME_PL = &aux_filename[0];

			remove(FILENAME_PL);
			remove(FILENAME_BOT);
			remove(FILENAME_NAMES);
		
		sistema.Clear_S();
		cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tDeseja disputar um novo jogo?" <<
			"\n\t\t\t\t\t\tSim = S, Nao = N: " << endl << "\t\t\t\t\t\t";
		cin >> fim_jogo;
		fim_jogo = toupper(fim_jogo);
		A->~Jogo();
		Jogo A;
		escolha = 1;
		}
	} while ((fim_jogo != 'N') && (A->get_sair() != 'X'));
	sistema.Clear_S();
	if (A->get_sair() == 'X')
	{
		cout << "\n\t\t\t\t\t\t     Ate a proxima!" << endl;
	}
	sistema.Pausa();
	return 0;
}

void imagem_inicial()
{
	lab L;
	L.setColor(8, 0);
	cout << endl;
	cout <<
		"--    .-""-.                                                     ";																							L.setColor(6, 0); cout << "  BBBBBBBB" << "    " << "NNN    NNN" << endl; L.setColor(8, 0); cout <<
		"   ) (     )                                                     ";																							L.setColor(6, 0); cout <<   "BBB  BBBB" << "   " << "NNNN   NNN" << endl; L.setColor(8, 0); cout <<
		"  (   )   (                                                      ";																							L.setColor(6, 0); cout <<   "BBB  BBB" << "    " << "NNNNN  NNN" << endl; L.setColor(8, 0); cout <<
		"     /     )                                                     ";																							L.setColor(6, 0); cout <<   "BBBBBBB" << "     " << "NNNNNN NNN" << endl; L.setColor(8, 0); cout <<
		"    (_    _)                     "; L.setColor(10, 0); cout << "0_,-.__                         ";																L.setColor(6, 0); cout <<   "BBB  BBB" << "    " << "NNN  NNNNN" << endl; L.setColor(8, 0); cout <<
		"      (_  )_                     "; L.setColor(10, 0); cout << "|"; L.setColor(4, 0); cout << "_.-._"; L.setColor(10, 0); cout << "/                         ";	L.setColor(6, 0); cout <<   "BBB  BBBB" << "   " << "NNN   NNNN" << endl; L.setColor(8, 0); cout <<
		"       (    )                    "; L.setColor(10, 0); cout << "|"; L.setColor(4, 0); cout << "_--.."; L.setColor(10, 0); cout << "\\                        ";	L.setColor(6, 0); cout <<  " BBBBBBBB" << "    " << "NNN    NNN" << endl; L.setColor(8, 0); cout <<
		"        (__)                     "; L.setColor(10, 0); cout << "|"; L.setColor(2, 0); cout << "__--_/                         " << endl; L.setColor(7, 0); cout <<
		"     |''   ``\\                   "; L.setColor(10, 0); cout << "|"; L.setColor(7, 0); cout << "                              " << endl <<
		"     |        \\                  "; L.setColor(10, 0); cout << "|"; L.setColor(7, 0); cout << "                              "; L.setColor(14, 0); cout << "      Batalha Naval" << endl; L.setColor(7, 0); cout <<
		"     |         \\  ,,,---===|\\\\\\  "; L.setColor(10, 0); cout << "|"; L.setColor(7, 0); cout << "  ///|\\\\                 " << endl <<
		" ____|,,,,,---==""\\          |\\\\\\\\|"; L.setColor(10, 0); cout << "|"; L.setColor(7, 0); cout << "|////|\\\\\\_           " << endl <<
		"           _   _   \\   ___,|==============""""==)               " << endl <<
		"    o  O  (_) (_)   \\ /          "; L.setColor(14, 0); cout << "_"; L.setColor(7, 0); cout << "         /                    " << endl <<
		"                     /         "; L.setColor(14, 0); cout << "_("; L.setColor(12, 0); cout << "+"; L.setColor(14, 0); cout << ")_"; L.setColor(7, 0); cout << "      /                      " << endl <<
		"      \\@_,,,,,,---==""           "; L.setColor(14, 0); cout << "\\\\|//"; L.setColor(7, 0); cout << "     /                  " << endl <<
		"--''''""                          "; L.setColor(14, 0); cout << "==="; L.setColor(7, 0); cout << "     /                      " << endl <<
		"                                       /                         " << endl <<
		"                                      /"; L.setColor(3, 0); cout << "______________________________________________________________________________  " << endl; L.resetColor(); cout <<
		"   \\    \\    \\     \\                 /"; L.setColor(3, 0); cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  " << endl; L.resetColor(); cout <<
"                         _____      / "; L.setColor(3, 0); cout << " ~~~   .-""-.~~~~~~  .-""-.         .-""-.         .-""-.         .-""-.         .-""-."		<< endl <<
"      .-""-.           ///==---   /`-._ ..-'      -.__..-'    '-.__..-'    '-.__..-'    '-.__..-'    '-.__..-'    '-.__."			<< endl <<
"__..-'      `-.__..-' =====\\\\\\\\\\\\ V/  .---\\.                      " << endl <<
"                      ~~~~~~~~~~~~, _',--/_.\\  .-""-.         .-""-.         .-""-.         .-""-.         .-""-.         .-""-." << endl <<
"                            .-""-.___` --  \\|         -.__..-      -.__..-      -.__..-      -.__..-      -.__..-      -"			<< endl; L.resetColor();
}