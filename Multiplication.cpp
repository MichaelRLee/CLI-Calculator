#include "Multiplication.h"

Multiplication::Multiplication(Expression* left, Expression* right):ArithmeticExpression(left,right){}

Multiplication::~Multiplication()
{
    delete left;
    delete right;
}

Multiplication::Multiplication(const Multiplication& other)
{
}

Multiplication& Multiplication::operator=(const Multiplication& rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

string Multiplication::evaluate()
{
    return left->evaluate() + "*" + right->evaluate();
}

void Multiplication::print()
{
    cout << "(" << this->evaluate() << ")";
}
