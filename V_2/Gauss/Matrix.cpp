#include "Matrix.h"
#include <iostream>

Matrix::Matrix() {

}

Matrix::Matrix(int m, int n) {

	this->lines = m;
	this->columns = n;

	this->data = new Vector[lines];

	for (int i = 0; i < lines; ++i) {
		this->data[i] = Vector(n);
	}
}

Matrix::Matrix(const Matrix& m) {

	delete[] this->data;
	this->data = new Vector[m.lines];

	for (int i = 0; i < this->lines; ++i) {
		this->data[i] = m.data[i];
	}

	this->lines = m.lines;
	this->columns = m.columns;
}

Matrix::~Matrix() {

	delete[] data;
}

void Matrix::print(){

	for (int i = 0; i < this->lines; ++i) {
		for (int j = 0; j < this->columns; ++j) {
			std::cout << this->data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

Vector& Matrix::operator[](int i) {

	return this->data[i];
}

Vector& Matrix::operator[](int i) const{
	
	return this->data[i];
}

Matrix& Matrix::operator=(const Matrix& m) {

	if (this == &m) {
		return *this;
	}

	this->lines = m.lines;
	this->columns = m.columns;
	delete[] this->data;
	this->data = new Vector[this->lines];

	for (int i = 0; i < this->lines; ++i) {
		this->data[i] = m.data[i];
	}

	return*this;
}