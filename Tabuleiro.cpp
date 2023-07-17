#include "Tabuleiro.h"
#include "lab.h"

#pragma region Constructors
Tabuleiro::Tabuleiro()
{
    int i, j;

	this->x0 = 4;
	this->y0 = 2;
	this->rows = 10;
	this->columns = 10;
	this->space_between_tables = 10;

    for (i = 1; i <= Get_Columns(); i++)
        for (j = 1; j <= Get_Rows(); j++)
        {
            this->M[i-1][j-1].Set_X(j);
            this->M[i-1][j-1].Set_Y(i);
            this->M[i-1][j-1].Set_C('.');
        }
}
//------------------Definição do Construtor com parâmetros
Tabuleiro::Tabuleiro(int X0, int Y0, int ROWS, int COLUMNS)
{
    int i, j;

    this->x0 = X0;
    this->y0 = Y0;
    this->rows = ROWS;
    this->columns = COLUMNS;
    this->space_between_tables = 10;

    for (i = 1; i <= Get_Columns(); i++)
        for (j = 1; j <= Get_Rows(); j++)
        {
            this->M[i-1][j-1].Set_X(j);
            this->M[i-1][j-1].Set_Y(i);
            this->M[i-1][j-1].Set_C('.');
        }
}
Tabuleiro::~Tabuleiro()
{
}
#pragma endregion

void Tabuleiro::SetCell(int m_y, int m_x, char m_c)
{
    this->M[(m_x - 1)][(m_y - 1)].Set_Y(m_y);
    this->M[(m_x - 1)][(m_y - 1)].Set_X(m_x);
    this->M[(m_x - 1)][(m_y - 1)].Set_C(m_c);
}

void Tabuleiro::SetCell_tpv(int m_y, int m_x, char m_c)
{
    this->third_p_v[(m_x - 1)][(m_y - 1)].Set_Y(m_y);
    this->third_p_v[(m_x - 1)][(m_y - 1)].Set_X(m_x);
    this->third_p_v[(m_x - 1)][(m_y - 1)].Set_C(m_c);
}

#pragma region Print Table(s)
void Tabuleiro::One_First_Row()
{
    int i = 0;
    int times = 0;
    unsigned char ul_corner = 218;
    unsigned char ur_corner = 191;
    unsigned char t_type = 194;
    unsigned char h_line = 196;
    unsigned char space = ' ';
    unsigned char letter = 65;
    cout << "\t" << "    Este e o seu tabuleiro" << endl;
    // Y-axis control
    if (y0 != 0)
    {
        for (i = 0; i < (y0 - 1); i++)
        {
            std::cout << "\n";
        }
    }
    // X-axis control
    if (x0 != 0)
    {
        for (i = 0; i < x0; i++)
        {
            std::cout << space;
        }
    }
    for (i = 0; i < columns; i++)
    {
        std::cout << space << space << letter << space;
        letter++;
    }

    std::cout << "\n";
    // X-axis control
    if (x0 != 0)
    {
        for (i = 0; i < x0; i++)
        {
            std::cout << space;
        }
    }

    std::cout << ul_corner;
    for (i = 0; i < columns; i++)
    {
        std::cout << h_line << h_line << h_line;

        if (i < (columns - 1))
        {
            std::cout << t_type;
        }
    }
    std::cout << ur_corner;
}
void Tabuleiro::One_Middle_Rows()
{
    int i, j, k, l;
    int times = 0;
    int y_coord = 1;			//Numeração para Cordenadas
    unsigned char h_line = 196;
    unsigned char v_line = 179;
    unsigned char space = ' ';
    unsigned char cross = 197;
    unsigned char rt_type = 195;
    unsigned char lt_type = 180;


    for (i = 0; i < rows; i++)
    {
        std::cout << "\n";
        if (x0 != 0)
        {
            for (l = 0; l < (x0 - 2); l++)
            {
                std::cout << space;
            }
        }
        if (i < 9)
        {
            std::cout << y_coord << space;
        }
        else
        {
            std::cout << y_coord;
        }

        for (j = 0; j < columns + 1; j++)
        {
            std::cout << v_line;
            if (j < (columns))
            {
                lab L;
                switch (M[i][j].Get_C())
                {
                    case '.':
                        std::cout << space << M[i][j].Get_C() << space;
                        break;
                    case 'O':
                        L.setColor(6, 0);
                        std::cout << space << M[i][j].Get_C() << space;
                        L.resetColor();
                        break;
                    case 'T':
                        L.setColor(12, 0);
                        std::cout << space << M[i][j].Get_C() << space;
                        L.resetColor();
                        break;
                    case 'A':
                        L.setColor(10, 0);
                        std::cout << space << M[i][j].Get_C() << space;
                        L.resetColor();
                        break;
                }
            }
        }

        std::cout << "\n";
        if (i < (rows - 1))
        {
            if (x0 != 0)
            {
                for (l = 0; l < x0; l++)
                {
                    std::cout << space;
                }
            }
            std::cout << rt_type;
            for (k = 0; k < columns - 1; k++)
            {
                std::cout << h_line << h_line << h_line;
                std::cout << cross;
            }
            std::cout << h_line << h_line << h_line;
            std::cout << lt_type;
        }
        y_coord++;
    }
}
void Tabuleiro::One_Last_Row()
{
    int i = 0;
    int times = 0;
    unsigned char dl_corner = 192;
    unsigned char dr_corner = 217;
    unsigned char inv_type = 193;
    unsigned char h_line = 196;
    unsigned char space = ' ';

    if (x0 != 0)
    {
        for (i = 0; i < x0; i++)
        {
            std::cout << space;
        }
    }

    std::cout << dl_corner;
    for (i = 0; i < columns; i++)
    {
        std::cout << h_line << h_line << h_line;

        if (i < (columns - 1))
        {
            std::cout << inv_type;
        }
    }
    std::cout << dr_corner;
}
void Tabuleiro::Two_First_Row()
{
    int i = 0;
    int times = 0;
    unsigned char ul_corner = 218;
    unsigned char ur_corner = 191;
    unsigned char t_type = 194;
    unsigned char h_line = 196;
    unsigned char space = ' ';
    unsigned char letter = 65;
    cout << "\t" << "    Este e o seu tabuleiro";
    do
    {
        std::cout << " ";
        times++;
    } while (times != space_between_tables);
    times = 0;
    cout << "\t\t" << "   Este e o tabuleiro do adversario" << endl;
    // Y-axis control
    if (y0 != 0)
    {
        for (i = 0; i < (y0 - 1); i++)
        {
            std::cout << "\n";
        }
    }
    // X-axis control
    if (x0 != 0)
    {
        for (i = 0; i < x0; i++)
        {
            std::cout << space;
        }
    }
    for (i = 0; i < columns; i++)
    {
        std::cout << space << space << letter << space;
        letter++;
    }

    letter = 65;
    std::cout << space;
    do
    {
        std::cout << " ";
        times++;
    } while (times != space_between_tables);
    times = 0;
    for (i = 0; i < columns; i++)
    {
        std::cout << space << space << letter << space;
        letter++;
    }

    std::cout << "\n";
    // X-axis control
    if (x0 != 0)
    {
        for (i = 0; i < x0; i++)
        {
            std::cout << space;
        }
    }

    std::cout << ul_corner;
    for (i = 0; i < columns; i++)
    {
        std::cout << h_line << h_line << h_line;

        if (i < (columns - 1))
        {
            std::cout << t_type;
        }
    }
    std::cout << ur_corner;
    
    do
    {
        std::cout << " ";
        times++;
    } while (times != space_between_tables);
    times = 0;

    std::cout << ul_corner;
    for (i = 0; i < columns; i++)
    {
        std::cout << h_line << h_line << h_line;

        if (i < (columns - 1))
        {
            std::cout << t_type;
        }
    }
    std::cout << ur_corner;
    
}
void Tabuleiro::Two_Middle_Rows(Tabuleiro T)
{
    int i, j, k, l;
    int times = 0;
    int y_coord = 1;			//Numeração para Cordenadas
    unsigned char h_line = 196;
    unsigned char v_line = 179;
    unsigned char space = ' ';
    unsigned char cross = 197;
    unsigned char rt_type = 195;
    unsigned char lt_type = 180;
    lab L;

    for (i = 0; i < rows; i++)
    {
        std::cout << "\n";
        if (x0 != 0)
        {
            for (l = 0; l < (x0 - 2); l++)
            {
                std::cout << space;
            }
        }
        if (i < 9)
        {
            std::cout << y_coord << space;
        }
        else
        {
            std::cout << y_coord;
        }

        for (j = 0; j < columns + 1; j++)
        {
            std::cout << v_line;
            if (j < (columns))
            {
                switch (M[i][j].Get_C())
                {
                    case '.':
                        std::cout << space << M[i][j].Get_C() << space;
                        break;
                    case 'O':
                        L.setColor(6, 0);
                        std::cout << space << M[i][j].Get_C() << space;
                        L.resetColor();
                        break;
                    case 'T':
                        L.setColor(12, 0);
                        std::cout << space << M[i][j].Get_C() << space;
                        L.resetColor();
                        break;
                    case 'A':
                        L.setColor(3, 0);
                        std::cout << space << M[i][j].Get_C() << space;
                        L.resetColor();
                        break;
                }
            }
        }
        
        do
        {
            std::cout << " ";
            times++;
        } while (times != (space_between_tables - 2));
        times = 0;
        if (i < 9)
        {
            std::cout << y_coord << space;
        }
        else
        {
            std::cout << y_coord;
        }

        for (j = 0; j < columns + 1; j++)
        {
            std::cout << v_line;
            if (j < (columns))
            {
                switch (third_p_v[i][j].Get_C())
                {
                    case '.':
                        std::cout << space << third_p_v[i][j].Get_C() << space;
                        break;
                    case 'T':
                        L.setColor(10, 0);
                        std::cout << space << third_p_v[i][j].Get_C() << space;
                        L.resetColor();
                        break;
                    case 'A':
                        L.setColor(12, 0);
                        std::cout << space << third_p_v[i][j].Get_C() << space;
                        L.resetColor();
                        break;
                    default:
                        L.setColor(14, 0);
                        std::cout << space << third_p_v[i][j].Get_C() << space;
                        L.resetColor();
                        break;
                }
            }
        }

        std::cout << "\n";
        if (i < (rows - 1))
        {
            if (x0 != 0)
            {
                for (l = 0; l < x0; l++)
                {
                    std::cout << space;
                }
            }
            std::cout << rt_type;
            for (k = 0; k < columns - 1; k++)
            {
                std::cout << h_line << h_line << h_line;
                std::cout << cross;
            }
            std::cout << h_line << h_line << h_line;
            std::cout << lt_type;

            
            do
            {
                std::cout << " ";
                times++;
            } while (times != space_between_tables);
            times = 0;

            std::cout << rt_type;
            for (k = 0; k < columns - 1; k++)
            {
                std::cout << h_line << h_line << h_line;
                std::cout << cross;
            }
            std::cout << h_line << h_line << h_line;
            std::cout << lt_type;
            
        }
        y_coord++;
    }
}
void Tabuleiro::Two_Last_Row()
{
    int i = 0;
    int times = 0;
    unsigned char dl_corner = 192;
    unsigned char dr_corner = 217;
    unsigned char inv_type = 193;
    unsigned char h_line = 196;
    unsigned char space = ' ';

    if (x0 != 0)
    {
        for (i = 0; i < x0; i++)
        {
            std::cout << space;
        }
    }

    std::cout << dl_corner;
    for (i = 0; i < columns; i++)
    {
        std::cout << h_line << h_line << h_line;

        if (i < (columns - 1))
        {
            std::cout << inv_type;
        }
    }
    std::cout << dr_corner;

    {
        do
        {
            std::cout << " ";
            times++;
        } while (times != space_between_tables);
        times = 0;

        std::cout << dl_corner;
        for (i = 0; i < columns; i++)
        {
            std::cout << h_line << h_line << h_line;

            if (i < (columns - 1))
            {
                std::cout << inv_type;
            }
        }
        std::cout << dr_corner;
    }
}
void Tabuleiro::Print_One_Table()
{
    One_First_Row();
    One_Middle_Rows();
    One_Last_Row();
}
void Tabuleiro::Print_Two_Tables(Tabuleiro T)
{
    Two_First_Row();
    Two_Middle_Rows(T);
    Two_Last_Row();
}
#pragma endregion



