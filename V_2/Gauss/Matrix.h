#pragma once

#include "Vector.h"

class Matrix {

	friend class GaussSolver;
	friend class Vector;

private:

	int lines = 0;
	int columns = 0;
	Vector* data = 0;

public:

	Matrix();
	Matrix(int m, int n);
	Matrix(const Matrix& m);
	~Matrix();

	void print();

	Vector& operator[](int i);
	Vector& operator[](int i) const;
	Matrix& operator=(const Matrix& m);
};