/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: Multiplies numbers
*/

#include "Multiplication.h"//header

Multiplication::Multiplication(Expression* left, Expression* right):ArithmeticExpression(left,right){}//assigns left and right

Multiplication::~Multiplication()//destructor
{
    delete left;
    delete right;
}

Multiplication::Multiplication(const Multiplication& other):ArithmeticExpression(other)//constructor for arithemtic expression
{
}

Multiplication& Multiplication::operator=(const Multiplication& rhs)//copy constructor
{
    if (this == &rhs) return *this;
    return *this;
}


string Multiplication::evaluate()//evaluates string
{
    string lEval = left->evaluate(); // Store the evaluated left half
    string rEval = right->evaluate(); // Store the evaluated right half
    float lNum = this->convert(lEval); // Convert the evaluated left half to a float
    float rNum = this->convert(rEval); // Convert the evaluated right half to a float
    stringstream ss; // Stringstream for converted a float to a string
    ss << lNum*rNum; // Store the product of the 2 halves in the stringstream
    return ss.str(); // Convert the sum to a string and return it
}



void Multiplication::print()//prints string
{
    cout << "("; //bracket
    left -> print();//lhs
    cout << "*";//times
    right -> print();//rhs
    cout << ")";//bracket
    //cout << this->evaluate();
}

void Multiplication::increment()
{
    left -> increment();
    right -> increment();
}
