#include "Multiply.h"

Multiply::Multiply()
{
    //ctor
}

Multiply::~Multiply()
{
    //dtor
}

Multiply::Multiply(const Multiply& other)
{
    //copy ctor
}

Multiply& Multiply::operator=(const Multiply& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates the expression and returns the result as a string.
*
* \return A string representation of the result of the evaluation of this expression
*
*/
string evaluate();

/** \brief Prints leftExpr '*' rightExpr.
*/
void print();
