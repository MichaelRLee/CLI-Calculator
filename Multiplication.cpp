#include "Multiplication.h"

Multiplication::Multiplication()
{
    //ctor
}

Multiplication::~Multiplication()
{
    //dtor
}

Multiplication::Multiplication(const Multiplication& other)
{
    //copy ctor
}

Multiplication& Multiplication::operator=(const Multiplication& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates the expression.
* \return A string representation of the result of the evaluation of this expression.
*/
string Multiplication::evaluate()
{
    return ""; // Dummy code
}

/** \brief Prints left '*' right.
*/
void Multiplication::print()
{
    int i = 0; // Dummy code
}
