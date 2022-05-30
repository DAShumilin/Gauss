#include "Vector.h"
#include <ostream>
#include <iostream>

Vector::Vector() {

}

Vector::Vector(int n) {

	this->n = n;
	data = new double[n];
	for (int i = 0; i < n; ++i) {
		data[i] = 0.;
	}
}

Vector::Vector(const Vector& v) {

	this->resize(v.n);

	for (int i = 0; i < this->n; ++i) {
		this->data[i] = v.data[i];
	}
}

Vector::~Vector() {

	delete[] data;
}

void Vector::resize(int newSize) {

	delete[] data;
	data = new double[newSize];
	this->n = newSize;

	for (int i = 0; i < n; ++i) {
		data[i] = 0.;
	}
}

double& Vector::operator[](int i) {

	return data[i];
}

double& Vector::operator[](int i) const{

	return data[i];
}

void Vector::print(){

	for (int i = 0; i < this->n; ++i) {
		std::cout << this->data[i] << " ";
	}
	std::cout << std::endl;
}

Vector& Vector::operator=(const Vector& v) {

	if (this->n != v.n) {
		this->resize(v.n);
	}
	for (int i = 0; i < n; ++i) {
		this->data[i] = v.data[i];
	}
	return *this;
}

Vector& Vector::operator*=(double d){
	
	for (int i = 0; i < n; ++i) {
		this->data[i] = d * this->data[i];
	}
	return *this;
}

Vector& Vector::operator-=(const Vector& v){
	
	for (int i = 0; i < n; ++i) {
		this->data[i] = this->data[i] - v.data[i];
	}
	return *this;
}

Vector Vector::operator*(double d) const{

	Vector c(n);
	for (int i = 0; i < n; ++i) {
		c.data[i] = d * this->data[i];
	}
	return c;
}