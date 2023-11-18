#pragma once
#include "expr.hpp"
#include <memory>

class Grouping : public Expr
{
public:
    Grouping(std::unique_ptr<Expr> expression);
    std::any accept(ExprVisitor<std::any>& visitor) const override;
    const std::unique_ptr<Expr> expression;
};