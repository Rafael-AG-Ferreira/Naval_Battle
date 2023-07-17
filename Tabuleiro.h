#pragma once
#include <iostream>
#include "PontoNaval.h"
#include <fstream>
using namespace std;

class Tabuleiro
{
private:
	int x0, y0, rows, columns;	//Localização X, Localização Y, Nº Linhas, Nº Colunas
	int space_between_tables;	//Espaço entre tabelas
	PontoNaval M[10][10];
	PontoNaval third_p_v[10][10];
public:
	#pragma region Constructors
    Tabuleiro();
    Tabuleiro(int X0, int Y0, int ROWS, int COLUMNS);
	~Tabuleiro();
	#pragma endregion

	#pragma region Setters
	void Set_X0(int X0)											{x0 = X0;}												
	void Set_Y0(int Y0)											{y0 = Y0;}												
	void Set_Rows(int ROWS)										{rows = ROWS;}											
	void Set_Columns(int COLUMNS)								{columns = COLUMNS;}									
	void Set_Space_Between_Tables(int SPACE_BETWEEN_TABLES)     {space_between_tables = SPACE_BETWEEN_TABLES;}								
	void SetCell(int m_y, int m_x, char m_c);
	void SetCell(PontoNaval P) { M[P.Get_X() - 1][P.Get_Int_Y() - 1] = P; }
	void SetCell_tpv(int m_y, int m_x, char m_c);
	#pragma endregion

	#pragma region Getters
	int Get_X0()												{return this->x0;}											
	int Get_Y0()												{return this->y0;}											
	int Get_Rows()												{return this->rows;}											
	int Get_Columns()											{return this->columns;}										
	int Get_Space_Between_Tables()								{return this->space_between_tables;}																
	PontoNaval GetCell(int lin, int col)						{return this->M[lin - 1][col - 1];}
	PontoNaval GetCell_tpv(int lin, int col)					{return this->third_p_v[lin - 1][col - 1]; }
	PontoNaval GetCell(PontoNaval P)							{return this->M[P.Get_X() - 1][P.Get_Int_Y() - 1];}
	#pragma endregion

	#pragma region Print Table(s)
	void One_First_Row();
	void One_Middle_Rows();
	void One_Last_Row();
	void Two_First_Row();
	void Two_Middle_Rows(Tabuleiro T);
	void Two_Last_Row();
	void Print_One_Table();
	void Print_Two_Tables(Tabuleiro T);
	#pragma endregion
};

