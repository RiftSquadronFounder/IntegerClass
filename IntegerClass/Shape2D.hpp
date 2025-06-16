#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Point2D.hpp"


class Shape2D {
public:
	Shape2D(int amountOfPoints);

	void Clear();

	void AddNewPoint(Point2D point);

	void RemoveDotAt(Integer index);

private:
	Point2D* shape_;

};

#endif // !SHAPE_HPP
