/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: Finds the difference
*/

#include "Subtraction.h"

Subtraction::Subtraction(Expression* left, Expression* right):ArithmeticExpression(left,right){}//assigns left and right

Subtraction::~Subtraction()//destructor
{
    delete left;
    delete right;
}

Subtraction::Subtraction(const Subtraction& other)// a default constructor
{

}

Subtraction& Subtraction::operator=(const Subtraction& rhs)// copy constructor
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
    cout << "(";//bracket
    left -> print();//lhs
    cout << "-";//minus
    right -> print();//rhs
    cout << ")";//bracket
    //cout << this->evaluate(); //prints evaluated expression
}
void Subtraction::increment()//increments digits by 1
{
    left -> increment();//tell left to do it
    right -> increment();//tell right to do it
}
