#include "Multiplication.h"

Multiplication::Multiplication(Expression* left, Expression* right):ArithmeticExpression(left,right){}

Multiplication::~Multiplication()
{
    delete left;
    delete right;
}

Multiplication::Multiplication(const Multiplication& other):ArithmeticExpression(other)
{
}

Multiplication& Multiplication::operator=(const Multiplication& rhs)
{
    if (this == &rhs) return *this;
    return *this;
}


string Multiplication::evaluate()
{
    string lEval = left->evaluate(); // Store the evaluated left half
    string rEval = right->evaluate(); // Store the evaluated right half
    float lNum = this->convert(lEval); // Convert the evaluated left half to a float
    float rNum = this->convert(rEval); // Convert the evaluated right half to a float
    stringstream ss; // Stringstream for converted a float to a string
    ss << lNum*rNum; // Store the product of the 2 halves in the stringstream
    return ss.str(); // Convert the sum to a string and return it
}



void Multiplication::print()
{
    cout << "(";
    left -> print();
    cout << "*";
    right -> print();
    cout << ")";
    //cout << this->evaluate();
}
