#include "Matrix.h"

Matrix::Matrix(int a, int b)
{
    std::vector<int> tab;
    for (int j = 0; j < b; j++)
        tab.push_back(0);//wype³niam zerami


    for (int i = 0; i < a; i++)
    {
        vector_dwuwymiarowy.push_back(tab); //wype³niam vector vectorami
    }
}

int Matrix::get_vector(int a, int b)
{
    return vector_dwuwymiarowy[a][b];
}

void Matrix::set_vector(int a, int b, int c)
{
    vector_dwuwymiarowy[a][b] = c;
}
