#include "Expression.h"

Expression::Expression()
{
    value="0";
    exp=NULL;
}


Expression::Expression(Expression* exp)
{
    this->exp=exp;
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
    if (exp!=NULL) return exp->evaluate();
    else return value;
}

void Expression::print()
{
    if (exp!=NULL) exp->print();
    else {
        if (convert()<0) cout << "(" << value << ")";
        else cout << value;
    }
}

float Expression::convert() // Convert this number to a floating-point representation
{
    if (exp!=NULL) return exp->convert();
    else return atof(this->value.c_str()); // Convert it to a float
}

void Expression::increment()
{
    if (exp!=NULL) exp->increment();
    else
    {
        stringstream temp;
        temp << atoi(value.c_str())+1;
        value = temp.str();
    }
}
