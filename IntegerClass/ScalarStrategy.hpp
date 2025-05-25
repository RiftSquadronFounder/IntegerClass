#ifndef SCALAR_STRATEGY_HPP
#define SCALAR_STRATEGY_HPP
#include "VectorProcessingStrategy.hpp"

class ScalarStrategy : public VectorProcessingStrategy {
public:
    void process(Vector2D& v1, Vector2D& v2) const override;
};

#endif // !SCALAR_STRATEGY_HPP
