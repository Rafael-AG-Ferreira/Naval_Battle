/*
Aluno:					Rafael António Gonçalves Ferreira
Número Mecanográfico: 	72951
Email:					al72951@utad.eu

A classe "Basilar" é a classe PontoNaval:
		-PontoNaval.h;
		-PontoNaval.cpp.


As classes que se encontram um nível acima (ambas 'dependem' altamente da classe PontoNaval - relação de uso) da classe anterior são:

		Classe Barco:					Classe Tabuleiro:
		-Barco.h;						-Tabuleiro.h;
		-Barco.cpp.						-Tabuleiro.cpp;
		  -Serve de base para formar		-A classe tabuleiro está a tabalhar com um ficheiro header:
		 os submarinos e os restantes								-Lab.h-
		barcos.								que foi utilizado o semestre passado para o projeto da 
											cadeira de Laboratório de Informática e Computadores.
											O intuito de utilizar este header foi apenas utilizar a
											funcionalidade de mudar as cores do que é impresso na
											consola (para que o jogo seja mais "amigável"). As restantes
											funcionalidades foram retiradas desse ficheiro.

		Classe Submarino
		-Forma através de uso todos os submarinos do jogo;

		Classes (Porta_Avioes, Cruzador, Couracado e Contratorpedeiro)
		-Formam os respetivos barcos com mais de um cano, através de uma relação de uso e da utilização de vetores;

		Classe Frota
		-Forma a frota de cada jogador com a totalidade dos barcos requeridos para realizar o jogo.

		Class Stats
		-Recolhe e fornece dados estatísticos do jogo;

		Class System
		-Permite realizar funções como o "pausar" da consola, ou limpar o ecrã da mesma;

A classe Jogador engloba as classes anteriormente descritas (relação de uso):
		-Jogador.h;
		-Jogador.cpp.

		-A classe Bot herda os métodos da classe Jogador para que o computador possa disputar um jogo autonomamente;


A classe Jogo é a classe que se serve de tudo anteriormente descrito (relação de uso) para definir o funcionamento do jogo:
		-Jogo.h;
		-Jogo.cpp


O ficheiro Batalha Naval.cpp é o ficheiro que contém a função main, que inicia e termina o jogo.


A descrição das funções das classes encontra-se nos respetivos ficheiros ".h";
*/