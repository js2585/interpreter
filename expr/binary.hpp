#pragma once
#include "expr.hpp"
#include "../token/token.hpp"
#include <memory>

class Binary : public Expr
{
public:
    Binary(std::unique_ptr<Expr> left, Token op, std::unique_ptr<Expr> right);
    std::any accept(ExprVisitor<std::any>& visitor) const override;
    const std::unique_ptr<Expr> left;
    const Token op;
    const std::unique_ptr<Expr> right;
};