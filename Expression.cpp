#include "Expression.h"

Expression::Expression()
{
    //ctor
}

Expression::~Expression()
{
    //dtor
}

Expression::Expression(const Expression& other)
{
    //copy ctor
}

Expression& Expression::operator=(const Expression& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string Expression::evaluate()
{
}

void Expression::print()
{
}
