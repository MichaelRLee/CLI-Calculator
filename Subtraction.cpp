#include "Subtraction.h"

Subtraction::Subtraction()
{
    //ctor
}

Subtraction::~Subtraction()
{
    //dtor
}

Subtraction::Subtraction(const Subtraction& other)
{
    //copy ctor
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
    return ""; // Dummy code
}

/** \brief Prints the expression.
*/
void Subtraction::print()
{
    int i = 1; // Dummy code
}