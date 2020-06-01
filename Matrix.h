#pragma once
#include <vector>

class Matrix
{
public: 
	std::vector<std::vector<char> > TwoDimensionalVector;
	Matrix(int a, int b);
	int GetValue(int a, int b);
	void SetValue(int a, int b, char c);

};

