/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This class will handle the subtraction section of BEDMASS operations.
*/

#include "Subtraction.h"

//This constructor will  assign values to the left and to the right of the subtraction 
Subtraction::Subtraction(Expression* left, Expression* right):ArithmeticExpression(left,right){}

//Destructor will delete the left and right values
Subtraction::~Subtraction()
{
    delete left;
    delete right;
}

//Assigns arithmetic expression to default constructor
Subtraction::Subtraction(const Subtraction& other)
{

}

//Copies another Subtraction object's members to this one.
Subtraction& Subtraction::operator=(const Subtraction& rhs)
{
    if (this == &rhs) return *this; 
    return *this;
}

/** 
* This method will evaluate the arithmetic expression from the left half and the right half then return the ouptut as a string
*/
string Subtraction::evaluate()
{
    string lEval = left->evaluate(); 
    string rEval = right->evaluate(); 
    float lNum = this->convert(lEval);
    float rNum = this->convert(rEval);
    stringstream ss; 
    ss << lNum-rNum; 
    return ss.str();
}

/** This method will print the subtraction expression
*/
void Subtraction::print()
{
    cout << "(";
    left -> print();
    cout << "-";
    right -> print();
    cout << ")";
}

//Increment values in this Addition's left or right-hand sides by 1.
void Subtraction::increment()
{
    left -> increment();
    right -> increment();
}
