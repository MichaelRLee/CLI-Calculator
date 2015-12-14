/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This file defines the class which represents an Addition.
*/

/* Beginning of include guard */
#ifndef ADDITION_H
#define ADDITION_H

#include "ArithmeticExpression.h" // Parent class
using namespace std; // Need types in this namespace

class Addition : public ArithmeticExpression // Inherits from ArithmeticExpression
{
    public:
        /** Constructor. Builds an Addition expression by taking a left and a right Expression to hold in
        the Addition. */
        Addition(Expression* left, Expression* right);

        /** Destroys an Addition object. Made virtual to allow for potential polymorphic
        *   children (unused). */
        virtual ~Addition();

        /** Copy constructor. Copies another Addition object's members to this one.
         *  \param other Object to copy from
         */
        Addition(const Addition& other);

        /** Assignment operator.
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Addition& operator=(const Addition& other);

        /** \brief Evaluates the expression.
         * \return A string representing the result of the evaluation of the expression.
         */
        string evaluate();

        /** \brief Prints the expression.
         */
        void print();

        /**
        *   \brief Increments the values of any numbers in this Addition's left or right-hand
        *           sides.
        */
        void increment();

    protected:
    private:
};

/* End of include guard */
#endif // ADDITION_H
