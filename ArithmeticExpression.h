/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This file defines all methods and properties common to all ArithmeticExpressions.
*/

#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H

#include "Expression.h" 

// Inherits from the Expression class
class ArithmeticExpression : public Expression 
{
    public:

        /** Constructs an ArithmeticExpression object with empty left and right sides. */
        ArithmeticExpression();

        /** Constructs an ArithmeticExpression object with copies of the given expressions stored as its
        left and right hand sides. **/
        ArithmeticExpression(Expression* left, Expression* right);

        /** 
         * Constructs a top-level ArithmeticExpression.
         */
        ArithmeticExpression(Expression* finalExp);

        /** Destroys an ArithmeticExpression */
        virtual ~ArithmeticExpression();

        // Copy constructor
        ArithmeticExpression(const ArithmeticExpression& other);

        // Assign from other object
        ArithmeticExpression& operator=(const ArithmeticExpression& other);

        /** 
         * return The current value of left
         */
        Expression* Getleft() { return left; }

        /** 
         * New value to set the left hand side
         */
        void Setleft(Expression* val) { left = val; }

         /** 
         * return The current value of right
         */
        Expression* Getright() { return right; }

        /** 
         * New value to set the right hand side
         */
        void Setright(Expression* val) { right = val; }

        /** Evaluates left and right expression and combines them with the appropriate operator.
         * A string representation of the result.
         */
        string evaluate();

        /* Prints the evaluated expression.
         */
        void print();

        //Converts a string (as returned by evaluate) to a float.
        float convert(string s);

        /* Increments the numbers in this ArithmeticExpression
         */
        void increment();
    protected:
        Expression *left; //!< The left half of the ArithmeticExpression
        Expression *right; //!< The right half of the ArithmeticExpression.
};

#endif 
