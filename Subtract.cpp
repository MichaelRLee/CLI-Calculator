#include "Subtract.h"

Subtract::Subtract()
{
    //ctor
}

Subtract::~Subtract()
{
    //dtor
}

Subtract::Subtract(const Subtract& other)
{
    //copy ctor
}

Subtract& Subtract::operator=(const Subtract& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates the expression and returns a string result.
 *
 * \return A string representing the result of the evaluation of this subtraction expression.
 *
 */

string evaluate();

/**
 * \brief Prints the result of the evaluation of this expression.
 */

void print();
