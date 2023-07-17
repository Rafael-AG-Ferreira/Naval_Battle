#include "PontoNaval.h"
#include <iostream>

#pragma region  Constructor/Dest
PontoNaval::PontoNaval() 
{
	this->x = NULL;
	this->y = NULL;
	this->c = '.';
}
PontoNaval::PontoNaval(int m_x, char m_y, char m_c)
{
	this->x = m_x;
	this->y = m_y;
	this->c = m_c;
}
PontoNaval::PontoNaval(int m_x, int m_y, char m_c)
{
	this->x = m_x;
	this->y = (m_y+64);
	this->c = m_c;
}
PontoNaval::~PontoNaval()
{
}
#pragma endregion

#pragma region  Setters
bool PontoNaval::Set_X(int m_x)
{
	if (m_x >= 1 && m_x <= 10) 
	{
		this->x = m_x;
		return true;
	}
	else
	{
		return false;
	}
	cout << "Valor de X invalido" << endl;
}
bool PontoNaval::Set_Y(char m_y)
{
	if (m_y >= 'A' && m_y <= 'J') 
	{
		this->y = m_y;
		return true;
	}
	else
	{
		return false;
	}
	cout << "Valor de Y invalido" << endl;
}
bool PontoNaval::Set_Y(int m_y)
{
	if (m_y >= 1 && m_y <= 10) 
	{
		this->y = char(m_y + 64);
		return true;
	}
	else
	{
		return false;
	}
	cout << "Valor de Y invalido" << endl;
}
bool PontoNaval::Set_C(char m_c)
{
	if (m_c == 'A' || m_c == 'T' || m_c == 'O' || m_c == '.') {
		this->c = m_c;
		return true;
	}
	else
	{
		return false;
	}
	cout << "Valor de C invalido" << endl;
}
bool PontoNaval::Set_PN(int m_x, char m_y, char m_c)
{
	if ((Set_X(m_x) == false) || (Set_Y(m_y) == false) || Set_C(m_c) == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void PontoNaval::Set_PN(PontoNaval m_PN)
{
	Set_X(m_PN.x);
	Set_Y(m_PN.y);
	Set_C(m_PN.c);
}
#pragma endregion

#pragma region  Getters
int PontoNaval::Get_Int_Y(void)
{
	int aux;
	aux = int(y) - 64;
	return aux;
}
PontoNaval PontoNaval::Get_PN() const
{
	return PontoNaval(this->x, this->y, this->c);
}
#pragma endregion

void PontoNaval::ShowPontoNaval(void)
{
	cout << "X = " << Get_X() << "; Y = " << Get_Y() << "; C = " << Get_C() << endl;
}

#pragma region  Operator Overload
bool PontoNaval::operator==(const PontoNaval ponto) const
{
	if ((x != ponto.x) || (y != ponto.y))
	{
		return false;
	}

	return true;
}
bool PontoNaval::operator!=(const PontoNaval ponto) const
{
	if ((x == ponto.x) && (y == ponto.y))
	{
		return false;
	}

	return true;
}
void PontoNaval::operator=(PontoNaval& ponto)
{
	this->x = ponto.x;
	this->y = ponto.y;
	this->c = ponto.c;
}

ostream& operator<<(ostream& os, const PontoNaval p)
{
	os << "x = " << p.x << " ,y = " << p.y << " ,c = " << p.c;
	return os;
}
istream& operator>>(istream& is, PontoNaval& p)
{
	cout << "Insira os valores de x e y, respetivamente (x,y)." << endl;
	is >> p.x; is.ignore();
	is >> p.y;
	return is;
}
#pragma endregion

#pragma region  Read/Save
void PontoNaval::Save(ofstream& os)
{
	os << "(" << Get_X() << "," << Get_Y() << "," << Get_C() << ")";
}
void PontoNaval::Read(ifstream& is)
{
	char aux[3];

	is.getline(aux, 3, '(');
	is.getline(aux, 3, ',');
	Set_X(atoi(aux));
	is.getline(aux, 3, ',');
	Set_Y(aux[0]);
	is.getline(aux, 3, ')');
	Set_C(aux[0]);
}
#pragma endregion
