#pragma once
template<typename R>
class ExprVisitor
{
    virtual ~ExprVisitor() = default;
    virtual R visitBinaryExpr(const Binary& expr) = 0;
    virtual R visitGroupingExpr(const Grouping& expr) = 0;
    virtual R visitLiteralExpr(const Literal& expr) = 0;
    virtual R visitUnaryExpr(const Unary& expr) = 0;
};