/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This file defines the properties common to all Expressions.
*/

#ifndef EXPRESSION_H
#define EXPRESSION_H


#include <string> 
#include <iostream> 
#include <sstream> 

#include <cstdlib> 
#include <cstdio> 

using namespace std; 
class Expression
{
    public:
        /** Creates an unintialised Expression. */
        //Expression(ArithmeticExpression* ae); // Copies a given arithmeticExpression into this one
        Expression ();

        // Copies another Expression's variables into this one.
        Expression(Expression* exp);

        // Creates an Expression given a value.
        Expression (string str);

        // Destroys an Expression object.
        virtual ~Expression();

        // Copy constructor
        Expression(const Expression& other);

        // Assign from other object
        Expression& operator=(const Expression& other);

        // Evaluate Expression
        virtual string evaluate(); // Evaluates the expression

        // Prints the Expression to the standard output recursively.
      
        virtual void print();

        //Converts a string (as returned by evaluate) to a float.
        float convert ();

      /* Increments the numbers in this Expression
         */
        virtual void increment();
    protected:
    private:
        string value; // The value of this Expression, if it has already been evaluated.
        Expression* exp; // The Expression contained in this Expression
};

#endif // EXPRESSION_H
