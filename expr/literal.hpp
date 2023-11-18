#pragma once
#include "expr.hpp"
#include <any>

template<class R>
class Literal : public Expr<R>
{
public:
    Literal(std::any value);
    std::any accept(ExprVisitor<std::any>& visitor) const override;
    const std::any value;
};