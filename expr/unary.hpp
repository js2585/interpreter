#pragma once
#include "expr.hpp"
#include "../token/token.hpp"
#include <memory>
class Unary : public Expr
{
public:
    Unary(Token op, std::unique_ptr<Expr> expression);
    std::any accept(ExprVisitor<std::any>& visitor) const override;
    const Token op;
    const std::unique_ptr<Expr> expression;
};