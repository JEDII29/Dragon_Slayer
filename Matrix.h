#pragma once
#include <vector>

class Matrix
{
public: 
	std::vector<std::vector<int> > vector_dwuwymiarowy;//deklaracja
	Matrix(int a, int b);
	int get_vector(int a, int b);
	void set_vector(int a, int b, int c);

};

