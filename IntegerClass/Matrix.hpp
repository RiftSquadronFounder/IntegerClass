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

	bool operator==(Matrix matrix);
	void operator=(Matrix matrix);

	void operator+=(Matrix matrix);
	void operator-=(Matrix matrix);
	void operator/=(Matrix matrix); // I don't think this operation even exists, so...
	void operator*=(Matrix matrix);


	Matrix operator+(Matrix matrix);
	Matrix operator-(Matrix matrix);
	Matrix operator/(Matrix matrix); // I don't think this operation even exists, so...
	Matrix operator*(Matrix matrix);
	Integer* operator[](size_t index);

	void MatrixOut();

	friend std::ostream& operator<<(std::ostream& outs, const Matrix& rso); // -- Haven't understood how to make it work yet


};




#endif // !MATRIX_HPP
