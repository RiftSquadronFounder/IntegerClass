#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP
#include "IntegerH.hpp"




class Vector2D {
public:
	Vector2D();
	Vector2D(Integer CoordinateX, Integer CoordinateY);


	friend std::ostream& operator<< (std::ostream& out, Vector2D& read);

	friend std::istream& operator>>(std::istream& in, Vector2D& write);

	void operator=(Vector2D other);
	Vector2D operator+(Vector2D other);
	Vector2D operator-(Vector2D other);
	Vector2D operator*(Vector2D other);
	Vector2D operator/(Vector2D other);

	Vector2D Normalize();

	Integer GetX();
	Integer GetY();

private:
	Integer coordinateX_ = 0;
	Integer coordinateY_ = 0;
};



#endif // !VECTOR2D_HPP
