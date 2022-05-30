#pragma once

class Vector {

	friend class GaussSolver;
	friend class Matrix;

private:

	double* data = 0;
	int n = 0;

public:

	Vector();
	Vector(int n);
	Vector(const Vector& v);
	~Vector();

	void resize(int newSize);
	double& operator[](int i);
	double& operator[](int i) const;
	void print();

	Vector& operator=(const Vector& v);
	Vector& operator*=(double d);
	Vector& operator-=(const Vector& v);
	Vector operator*(double d) const;
};