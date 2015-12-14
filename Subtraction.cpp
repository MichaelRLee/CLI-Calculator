#include "Subtraction.h"

Subtraction::Subtraction(Expression* left, Expression* right):ArithmeticExpression(left,right){}

Subtraction::~Subtraction()
{
    delete left;
    delete right;
}

Subtraction::Subtraction(const Subtraction& other)
{

}

Subtraction& Subtraction::operator=(const Subtraction& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates the expression.
* \return A string representation of the result.
*/
string Subtraction::evaluate()
{
    string lEval = left->evaluate(); // Store the evaluated left half
    string rEval = right->evaluate(); // Store the evaluated right half
    float lNum = this->convert(lEval); // Convert the evaluated left half to a float
    float rNum = this->convert(rEval); // Convert the evaluated right half to a float
    stringstream ss; // Stringstream for converted a float to a string
    ss << lNum-rNum; // Store the difference of the 2 halves in the stringstream
    return ss.str(); // Convert the sum to a string and return it
}

/** \brief Prints the expression.
*/
void Subtraction::print()
{
    cout << "(";
    left -> print();
    cout << "-";
    right -> print();
    cout << ")";
    //cout << this->evaluate(); //prints evaluated expression
}

void Subtraction::increment()
{
    left->increment();
    right->increment();
}
