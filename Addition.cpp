/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This class will handle the additon section of BEDMASS operations.
*/

#include "Addition.h"

//This constructor will  assign values to the left and to the right of the addition 
Addition::Addition(Expression* left, Expression* right):ArithmeticExpression(left,right){} 

//Destructor will delete the left and right values
Addition::~Addition()
{
    delete left;
    delete right;
}

//Assigns arithmetic expression to default constructor
Addition::Addition(const Addition& other):ArithmeticExpression(other)
{

}

//Copies another Addition object's members to this one.
Addition& Addition::operator=(const Addition& rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

/** 
* This method will evaluate the arithmetic expression from the left half and the right half then return the ouptut as a string
*/
string Addition::evaluate()
{
    string lEval = left->evaluate(); 
    string rEval = right->evaluate();
    float lNum = this->convert(lEval); 
    float rNum = this->convert(rEval); 
    stringstream ss; 
    ss << lNum+rNum; 
    return ss.str(); 
}

/** This method will print the addition expression
*/
void Addition::print()
{
    cout << "("; 
    left -> print();
    cout << "+";
    right -> print();
    cout << ")";
}

//Increment values in this Addition's left or right-hand sides by 1.
void Addition::increment()
{
    left -> increment();
    right -> increment();
}
