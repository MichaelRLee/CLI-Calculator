/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: Stores equations
*/

#include "ArithmeticExpression.h"

//blank constructor
ArithmeticExpression::ArithmeticExpression()
{
    left=NULL;
    right=NULL;
}

ArithmeticExpression::ArithmeticExpression(Expression* left, Expression* right):left(left), right (right){}//assigns left and right

ArithmeticExpression::ArithmeticExpression(Expression* finalExp):left(finalExp), right(NULL){}//if equation

ArithmeticExpression::~ArithmeticExpression()//doesn't need to delete, children will do it for it
{
}

//Copy constructor into left and right components
ArithmeticExpression::ArithmeticExpression(const ArithmeticExpression& other)
{
    this->left = new ArithmeticExpression(other.left); // Copy the left side of other Expression to left
    this->right = new ArithmeticExpression(other.right); // Copy the right side of other Expression to right
}

//Copy whole constructor dependent on self assignment
ArithmeticExpression& ArithmeticExpression::operator=(const ArithmeticExpression& rhs)
{
    if (this == &rhs) return *this; // Handle self assignment
    return *this;
}

/** 
* Evaluates left and right expression and combines them with the appropriate operator return a string of the result.
*/
string ArithmeticExpression::evaluate()
{
    return left->evaluate(); // Evaluate the left half of the Expression
}

// Prints the evaluated expression.
void ArithmeticExpression::print()
{
    left->print();
}

// Converts a string (as returned by evaluate) to a float.
float ArithmeticExpression::convert(string s) 
{
    float input = atof (s.c_str());
    return input; 
}

//Increases digits by one
void ArithmeticExpression::increment()
{
    left -> increment();//increase the left-hand side
    if (right!=NULL)right -> increment();//increase the right-hand side
}

