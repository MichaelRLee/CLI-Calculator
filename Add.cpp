#include "Add.h"

Add::Add()
{
    //ctor
}

Add::~Add()
{
    //dtor
}

Add::Add(const Add& other)
{
    //copy ctor
}

Add& Add::operator=(const Add& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates this expression.
 *
 * \return A string representation of the result of the evaluation of this addition expression.
 *
 */

string Add::evaluate()
{
}

/**
 *\brief Prints this expression as a string.
 */

void Add::print()
{
}
