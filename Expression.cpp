#include "Expression.h"

Expression::Expression()
{
    //ctor
}

Expression::Expression(Expression* exp)
{
    this->value = exp->evaluate();
    cout << value<<endl;
}

Expression::Expression(string str)
{
    this->value = str;
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
    //this -> value = rhs.evaluate();
    return *this;
}

string Expression::evaluate()
{
    return this->value;
}

void Expression::print()
{
    cout << "telksjt" <<endl;
    cout << this -> value;
}

void Expression::increment()
{
    stringstream temp;
    temp << atoi(this->value.c_str())+1; // Convert it to a int
    value = temp.str();
    cout << value << endl;
}


