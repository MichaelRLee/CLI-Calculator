#include "Expression.h"

Expression::Expression()
{
    value="0";
    exp=NULL;
}


Expression::Expression(Expression* exp)
{
    this->value = exp->value;
    this ->exp = exp->exp;
}


Expression::Expression(string str):value(str),exp(NULL)
{
}

Expression::~Expression()
{
    if (exp!=NULL) delete exp;
}

Expression::Expression(const Expression& other)
{
    //copy ctor
}

Expression& Expression::operator=(const Expression& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    this->value = rhs.value;
    this ->exp = rhs.exp;
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
    value = temp.str();
}

Expression* Expression::retExp()
{
    return this->exp;
}
