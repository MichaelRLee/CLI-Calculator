/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This file defines the class which represents the Division of 2 ArithmeticExpressions.
*/

/* Beginning of include guard */
#ifndef DIVISION_H
#define DIVISION_H

#include "ArithmeticExpression.h" // Parent class

class Division : public ArithmeticExpression // Inherits from the ArithmeticExpression class
{
    public:
        /** Builds a Division expression by initialising its left and right sides to the given
        ones. */
        Division(Expression* left, Expression* right);

        /** Destroys a Division object. Made virtual to allow for polymorphic destruction (unused).
        */
        virtual ~Division();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Division(const Division& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Division& operator=(const Division& other);

        /** \brief Evaluates the expression.
         * \return A string describing the result of the evaluation of the expression.
         */
        string evaluate();

        /** \brief Prints the expression.
         */
        void print();

        /** \brief Increments the values of any numbers in this Division's left or right-hand
         *          sides.
         */
        void increment();
    protected:
    private:
};

/* End of include guard */
#endif // DIVISION_H
