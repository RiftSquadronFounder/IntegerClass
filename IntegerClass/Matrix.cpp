#include "Matrix.hpp"


Matrix::Matrix(Integer x, Integer y) {
	xSize_ = x.ToInt();
	ySize_ = x.ToInt();
	matrix_ = new Integer * [xSize_];
	for (Integer i = 0; i < xSize_; i++) {
		matrix_[i.ToInt()] = new Integer[ySize_];
	}
}





bool Matrix::operator==(Matrix matrix) {
	bool isEqual = true;
	for (size_t i = 0; i < this->xSize_; i++) {
		for (size_t k = 0; k < this->ySize_; k++) {
			if (matrix_[i][k] != matrix[i][k]) {
				isEqual = false;
			}
		}
	}
	return isEqual;
}


void Matrix::operator=(Matrix matrix) {
	for (size_t i = 0; i < this->xSize_; i++) {
		for (size_t k = 0; k < this->ySize_; k++) {
			matrix_[i][k] = matrix[i][k];
		}
	}
}



void Matrix::operator+=(Matrix matrix) {
	for (size_t i = 0; i < this->xSize_; i++) {
		for (size_t k = 0; k < this->ySize_; k++) {
			matrix_[i][k] = matrix_[i][k] + matrix[i][k];
		}
	}
}
void Matrix::operator-=(Matrix matrix) {
	for (size_t i = 0; i < this->xSize_; i++) {
		for (size_t k = 0; k < this->ySize_; k++) {
			matrix_[i][k] = matrix_[i][k] - matrix[i][k];
		}
	}
}
void Matrix::operator/=(Matrix matrix) {}
void Matrix::operator*=(Matrix matrix) {
	if (xSize_ == matrix.ySize_ && ySize_ == matrix.xSize_) {
		Matrix answer = Matrix(this->xSize_, this->ySize_);
		for (size_t i = 0; i < answer.xSize_; i++) {
			for (size_t k = 0; k < answer.ySize_; k++) {

				matrix_[i][k] = matrix_[i][k] * matrix[k][i];
			}
		}
	}
	else { std::cout << "Error: Matrix not match"; }
}





Matrix Matrix::operator+(Matrix matrix) {
	Matrix answer = Matrix(this->xSize_, this->ySize_);
	for (size_t i = 0; i < answer.xSize_; i++) {
		for (size_t k = 0; k < answer.ySize_; k++) {

			answer[i][k] = matrix_[i][k] + matrix[i][k];
		}
	}
	return answer;
};

Matrix Matrix::operator-(Matrix matrix) {
	Matrix answer = Matrix(this->xSize_, this->ySize_);
	for (size_t i = 0; i < answer.xSize_; i++) {
		for (size_t k = 0; k < answer.ySize_; k++) {

			answer[i][k] = matrix_[i][k] - matrix[i][k];
		}
	}
	return answer;
};

Matrix Matrix::operator/(Matrix matrix) {};

Matrix Matrix::operator*(Matrix matrix) {
	if (xSize_ == matrix.ySize_ && ySize_ == matrix.xSize_) {
		Matrix answer = Matrix(this->xSize_, this->ySize_);
		for (size_t i = 0; i < answer.xSize_; i++) {
			for (size_t k = 0; k < answer.ySize_; k++) {

				answer[i][k] = matrix_[i][k] * matrix[k][i];
			}
		}
		return answer;
	}
	else { std::cout << "Error: Matrix not match"; }
};








Integer* Matrix::operator[](size_t index) {
	return matrix_[index];
}


void Matrix::MatrixOut() {
	
	for (size_t i = 0; i < ySize_; i++) {
		std::cout << "[";
		for (size_t k = 0; k < xSize_; k++) {
			std::cout << matrix_[i][k];
			if (k + 1 != xSize_) {
				std::cout << ", ";
			}
		}
		std::cout << "]\n";
	}
}

/*friend std::ostream& Matrix::operator<<(std::ostream& outs, const Matrix& rso) {
	return outs;
	MatrixOut();					-- ���� �� �����, ��� ����������� / Haven't understood how to make it work yet
}*/