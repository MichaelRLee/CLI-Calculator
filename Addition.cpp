#include "Addition.h"

Addition::Addition()
{
    //ctor
}

Addition::~Addition()
{
    //dtor
}

Addition::Addition(const Addition& other)
{
    //copy ctor
}

Addition& Addition::operator=(const Addition& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates the expression.
* \return A string representing the result of the evaluation of the expression.
*/
string Addition::evaluate()
{
    return ""; // Dummy code
}

/** \brief Prints the expression.
*/
void Addition::print()
{
    int i = 1; // Dummy
}
