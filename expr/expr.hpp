#pragma once
#include <any>
#include "exprVisitor.hpp"
class Expr
{
public:
    virtual ~Expr() = default;
    virtual std::any accept(ExprVisitor<std::any>& visitor) const = 0;
};