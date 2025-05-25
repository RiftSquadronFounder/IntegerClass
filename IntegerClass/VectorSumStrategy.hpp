#ifndef VECTOR_SUM_STRATEGY_HPP
#define VECTOR_SUM_STRATEGY_HPP
#include "VectorProcessingStrategy.hpp"

class VectorSumStrategy : public VectorProcessingStrategy {
public:
    void process(Vector2D& v1, Vector2D& v2) const override;
};

#endif // !VECTOR_SUM_STRATEGY_HPP
