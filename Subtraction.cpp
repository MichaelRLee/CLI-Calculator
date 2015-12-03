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
    return *left.evaluate() + "-" + *right.evalute(); //evalute right and left expression before the subtraction occurs
}

/** \brief Prints the expression.
*/
void Subtraction::print()
{
    cout << this.evalute(); //prints evaluated expression 
}
