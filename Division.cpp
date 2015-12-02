#include "Division.h"

Division::Division()
{
    //ctor
}

Division::~Division()
{
    //dtor
}

Division::Division(const Division& other)
{
    //copy ctor
}

Division& Division::operator=(const Division& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates the expression.
* \return A string describing the result of the evaluation of the expression.
*/
string evaluate()
{
    return ""; // Dummy code
}

/** \brief Prints the expression.
*/
void print()
{
    int i = 10; // Dummy code
}
