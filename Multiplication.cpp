/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This class will handle the multiplication section of BEDMASS operations.
*/

#include "Multiplication.h"

//This constructor will  assign values to the left and to the right of the multiplication
Multiplication::Multiplication(Expression* left, Expression* right):ArithmeticExpression(left,right){}

//Destructor will delete the left and right values
Multiplication::~Multiplication()
{
    delete left;
    delete right;
}

//Assigns arithmetic expression to default constructor
Multiplication::Multiplication(const Multiplication& other):ArithmeticExpression(other)
{
}

//Copies another Multiplication object's members to this one.
Multiplication& Multiplication::operator=(const Multiplication& rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

/** 
* This method will evaluate the arithmetic expression from the left half and the right half then return the ouptut as a string
*/
string Multiplication::evaluate()//evaluates string
{
    string lEval = left->evaluate();
    string rEval = right->evaluate(); 
    float lNum = this->convert(lEval);
    float rNum = this->convert(rEval);  
    stringstream ss; 
    ss << lNum*rNum; 
    return ss.str();  
}


/** This method will print the multiplication expression
*/
void Multiplication::print()
{
    cout << "("; 
    left -> print();
    cout << "*";
    right -> print();
    cout << ")";
}

//Increment values in this Addition's left or right-hand sides by 1.
void Multiplication::increment()
{
    left -> increment();
    right -> increment();
}
