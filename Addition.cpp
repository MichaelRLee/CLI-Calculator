#include "Addition.h"

Addition::Addition(Expression* left, Expression* right):ArithmeticExpression(left,right){}

Addition::~Addition()
{
    delete left;
    delete right;
}

Addition::Addition(const Addition& other):ArithmeticExpression(other)
{

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
    string lEval = left->evaluate(); // Store the evaluated left half
    string rEval = right->evaluate(); // Store the evaluated right half
    float lNum = this->convert(lEval); // Convert the evaluated left half to a float
    float rNum = this->convert(rEval); // Convert the evaluated right half to a float
    stringstream ss; // Stringstream for converted a float to a string
    ss << lNum+rNum; // Store the sum of the 2 halves in the stringstream
    return ss.str(); // Convert the sum to a string and return it
}

/** \brief Prints the expression.
*/
void Addition::print()
{
    cout << "(";
    left -> print();
    cout << "+";
    right -> print();
    cout << ")";
    //cout << this->evaluate(); // Print the evaluated expression
}
