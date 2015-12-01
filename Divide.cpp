#include "Divide.h"

Divide::Divide()
{
    //ctor
}

Divide::~Divide()
{
    //dtor
}

Divide::Divide(const Divide& other)
{
    //copy ctor
}

Divide& Divide::operator=(const Divide& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates the expression and returns a string containing the result.
* \return A string representation of the result of the division.
*/
string evaluate();

/** \brief Prints leftExpr '/' rightExpr.
*/
void print();
