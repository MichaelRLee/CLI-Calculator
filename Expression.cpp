#include "Expression.h"

Expression::Expression()
{
    value="0";
}

Expression::Expression(Expression* exp)
{
    value=exp->evaluate();
}

Expression::Expression(string str):value(str)
{
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
    return value;
}

void Expression::print()
{
    cout << value;
}

float Expression::convert() // Convert this number to a floating-point representation
{
    return atof(this->value.c_str()); // Convert it to a float
}

void Expression::increment()
{
    stringstream temp;
    temp << atoi(value.c_str())+1;
    cout << temp.str() <<endl;
    value = temp.str();
}
