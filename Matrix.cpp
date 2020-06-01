#include "Matrix.h"

Matrix::Matrix(int a, int b)
{
    std::vector<char> tab;
    for (int j = 0; j < b; j++)
        tab.push_back(0);//wype³niam zerami


    for (int i = 0; i < a; i++)
    {
        TwoDimensionalVector.push_back(tab); //wype³niam vector vectorami
    }
}

int Matrix::GetValue(int a, int b)
{
    return TwoDimensionalVector[a][b];
}

void Matrix::SetValue(int a, int b, char c)
{
    TwoDimensionalVector[a][b] = c;
}
