#include "VectorSumStrategy.hpp"

void VectorSumStrategy::process(Vector2D& v1, Vector2D& v2) const {
    Vector2D result = v1 + v2;
    std::cout << "Vector sum: " << result;
}