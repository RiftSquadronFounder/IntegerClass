#include "Vector2D.hpp"




Vector2D::Vector2D() {
	coordinateX_ = Real();
	coordinateY_ = Real();
}
Vector2D::Vector2D(Real CoordinateX, Real CoordinateY) {
	coordinateX_ = CoordinateX;
	coordinateY_ = CoordinateY;
}


std::ostream& operator<< (std::ostream& out, Vector2D& read) {
	std::cout << "(X:" << read.coordinateX_ << "; Y:" << read.coordinateY_ << ")";
	return out;
}






void Vector2D::operator=(Vector2D other) {
	this->coordinateX_ = this->coordinateX_ + other.coordinateX_;
	this->coordinateY_ = this->coordinateY_ + other.coordinateY_;
}

Vector2D Vector2D::operator+(Vector2D other) {
	Vector2D answer;

	answer.coordinateX_ = this->coordinateX_ + other.coordinateX_;
	answer.coordinateY_ = this->coordinateY_ + other.coordinateY_;


	return answer;
}
Vector2D Vector2D::operator-(Vector2D other) {
	Vector2D answer;

	answer.coordinateX_ = this->coordinateX_ - other.coordinateX_;
	answer.coordinateY_ = this->coordinateY_ - other.coordinateY_;

	return answer;
}
Vector2D Vector2D::operator*(Vector2D other) {
	Vector2D answer;

	answer.coordinateX_ = this->coordinateX_ * other.coordinateX_;
	answer.coordinateY_ = this->coordinateY_ * other.coordinateY_;

	return answer;
}
Vector2D Vector2D::operator/(Vector2D other) {
	Vector2D answer;

	answer.coordinateX_ = this->coordinateX_ / other.coordinateX_;
	answer.coordinateY_ = this->coordinateY_ / other.coordinateY_;

	return answer;
}




Real Vector2D::GetX() {
	return coordinateX_;
}
Real Vector2D::GetY() {
	return coordinateY_;
}