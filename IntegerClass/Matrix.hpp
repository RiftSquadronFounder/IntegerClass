#pragma once

#ifndef MATRIX_HPP


#include <iostream>
#include "IntegerH.hpp"




class Matrix {
private:
	size_t xSize_;
	size_t ySize_;
	Integer** matrix_;


public:
	Matrix(Integer x, Integer y);

	Matrix operator+(Matrix matrix);
	Matrix operator-(Matrix matrix);
	Matrix operator/(Matrix matrix);
	Matrix operator*(Matrix matrix);
	Integer* operator[](size_t index);

};




#endif // !MATRIX_HPP
