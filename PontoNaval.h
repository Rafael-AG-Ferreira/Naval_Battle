#pragma once
#include <fstream>

using namespace std;

class PontoNaval
{
private:
	int x; //1 -- 10
	char y; //A -- J
	char c; // carateres possíveis '.' 'O' 'T' 'A'

public:
	#pragma region  Constructor/Dest
	PontoNaval();
	PontoNaval(int m_x, char m_y, char m_c);
	PontoNaval(int m_x, int m_y, char m_c);
	virtual ~PontoNaval();
	#pragma endregion

	#pragma region  Setters
	bool Set_X(int m_x);
	bool Set_Y(char m_y);
	bool Set_Y(int m_y);
	bool Set_C(char m_c);
	bool Set_PN(int m_x, char m_y, char m_c);
	void Set_PN(PontoNaval m_PN);
	
	#pragma endregion

	#pragma region  Getters
	int Get_X() const	{ return x; };
	char Get_Y() const	{ return y; };
	char Get_C() const	{ return c; };
	int Get_Int_Y();
	PontoNaval Get_PN() const;
	#pragma endregion
	
	void ShowPontoNaval(void);
	
	#pragma region  Operator Overload
	bool operator == (const PontoNaval ponto) const;
	bool operator != (const PontoNaval ponto) const;
	void operator = (PontoNaval& ponto);

	friend ostream& operator <<(ostream& os, const PontoNaval p);
	friend istream& operator >>(istream& is, PontoNaval& p);
	#pragma endregion

	#pragma region  Read/Save
	void Save(ofstream& os);
	void Read(ifstream& is);
	#pragma endregion
};

