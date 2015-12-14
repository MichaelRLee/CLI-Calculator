#include "Division.h"

Division::Division(Expression* left, Expression* right):ArithmeticExpression(left,right){}

Division::~Division()
{
    delete left;
    delete right;
}

Division::Division(const Division& other): ArithmeticExpression(other)
{
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
string Division::evaluate()
{
    string lEval = left->evaluate(); // Store the evaluated left half
    string rEval = right->evaluate(); // Store the evaluated right half
    float lNum = this->convert(lEval); // Convert the evaluated left half to a float
    float rNum = this->convert(rEval); // Convert the evaluated right half to a float
    stringstream ss; // Stringstream for converted a float to a string
    ss << lNum/rNum; // Store the quotient of the 2 halves in the stringstream
    return ss.str(); // Convert the quotient to a string and return it
}

/** \brief Prints the expression.
*/
void Division::print()
{
    cout << "(";
    left -> print();
    cout << "/";
    right -> print();
    cout << ")";
    //cout<< this->evaluate(); // Dummy code
}

void Division::increment()
{
    left -> increment();
    right -> increment();
}
