#include "Subtraction.h"

Subtraction::Subtraction(Expression* left, Expression* right):ArithmeticExpression(left,right){}

Subtraction::~Subtraction()
{
    delete left;
    delete right;
}

Subtraction::Subtraction(const Subtraction& other)
{

}

Subtraction& Subtraction::operator=(const Subtraction& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates the expression.
* \return A string representation of the result.
*/
string Subtraction::evaluate()
{
    return left->evaluate() + "-" + right->evaluate(); //evalute right and left expression before the subtraction occurs
}

/** \brief Prints the expression.
*/
void Subtraction::print()
{
    cout << this->evaluate(); //prints evaluated expression
}
