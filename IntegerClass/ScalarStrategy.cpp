#include "ScalarStrategy.hpp"

void ScalarStrategy::process(Vector2D& v1, Vector2D& v2) const {
    Real scalar_product = v1.GetX() * v2.GetX() + v1.GetY() * v2.GetY();
    std::cout << "Scalar (dot): " << scalar_product << std::endl;
}