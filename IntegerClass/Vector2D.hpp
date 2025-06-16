#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP
#include "Real.hpp"




class Vector2D {
public:
	Vector2D();
	Vector2D(Real CoordinateX, Real CoordinateY);


	friend std::ostream& operator<< (std::ostream& out, Vector2D& read);

	friend std::istream& operator>>(std::istream& in, Vector2D& write);

	void operator=(Vector2D other);
	Vector2D operator+(Vector2D other);
	Vector2D operator-(Vector2D other);
	Vector2D operator*(Vector2D other);
	Vector2D operator/(Vector2D other);

	Vector2D Normalize();

	Real GetX();
	Real GetY();

private:
	Real coordinateX_;
	Real coordinateY_;
};



#endif // !VECTOR2D_HPP
