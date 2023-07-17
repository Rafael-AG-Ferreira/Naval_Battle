/*
Aluno:					Rafael Ant�nio Gon�alves Ferreira
N�mero Mecanogr�fico: 	72951
Email:					al72951@utad.eu

A classe "Basilar" � a classe PontoNaval:
		-PontoNaval.h;
		-PontoNaval.cpp.


As classes que se encontram um n�vel acima (ambas 'dependem' altamente da classe PontoNaval - rela��o de uso) da classe anterior s�o:

		Classe Barco:					Classe Tabuleiro:
		-Barco.h;						-Tabuleiro.h;
		-Barco.cpp.						-Tabuleiro.cpp;
		  -Serve de base para formar		-A classe tabuleiro est� a tabalhar com um ficheiro header:
		 os submarinos e os restantes								-Lab.h-
		barcos.								que foi utilizado o semestre passado para o projeto da 
											cadeira de Laborat�rio de Inform�tica e Computadores.
											O intuito de utilizar este header foi apenas utilizar a
											funcionalidade de mudar as cores do que � impresso na
											consola (para que o jogo seja mais "amig�vel"). As restantes
											funcionalidades foram retiradas desse ficheiro.

		Classe Submarino
		-Forma atrav�s de uso todos os submarinos do jogo;

		Classes (Porta_Avioes, Cruzador, Couracado e Contratorpedeiro)
		-Formam os respetivos barcos com mais de um cano, atrav�s de uma rela��o de uso e da utiliza��o de vetores;

		Classe Frota
		-Forma a frota de cada jogador com a totalidade dos barcos requeridos para realizar o jogo.

		Class Stats
		-Recolhe e fornece dados estat�sticos do jogo;

		Class System
		-Permite realizar fun��es como o "pausar" da consola, ou limpar o ecr� da mesma;

A classe Jogador engloba as classes anteriormente descritas (rela��o de uso):
		-Jogador.h;
		-Jogador.cpp.

		-A classe Bot herda os m�todos da classe Jogador para que o computador possa disputar um jogo autonomamente;


A classe Jogo � a classe que se serve de tudo anteriormente descrito (rela��o de uso) para definir o funcionamento do jogo:
		-Jogo.h;
		-Jogo.cpp


O ficheiro Batalha Naval.cpp � o ficheiro que cont�m a fun��o main, que inicia e termina o jogo.


A descri��o das fun��es das classes encontra-se nos respetivos ficheiros ".h";
*/