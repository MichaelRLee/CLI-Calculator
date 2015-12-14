/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This file defines the properties common to all Expressions.
*/

/* Include guard */
#ifndef EXPRESSION_H
#define EXPRESSION_H

// C++ includes
#include <string> // string
#include <iostream> //cout
#include <sstream> // Stringstream

// C includes
#include <cstdlib> // atof
#include <cstdio> // printf

using namespace std; // For the types in the standard namespace

class Expression
{
    public:
        /** Creates an unintialised Expression. */
        //Expression(ArithmeticExpression* ae); // Copies a given arithmeticExpression into this one
        Expression ();

        /** \brief Copy constructor. Copies another Expression's variables into this one.
         *
         * \param exp THe other Expression to copy from.
         */
        Expression(Expression* exp);

        /** \brief Creates an Expression given a value.
         *
         * \param str The value to store in this Expression.
         */
        Expression (string str);

        /** Destroys an Expression object. */
        virtual ~Expression();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Expression(const Expression& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Expression& operator=(const Expression& other);

        /** \brief Evaluates an Expression. Made virtual to allow for polymorphic overriding.
         *
         * \return A string representing the result of the evaluation of this Expression.
         *
         */
        virtual string evaluate(); // Evaluates the expression

        /** \brief Prints the Expression to the standard output recursively.
         */
        virtual void print();

        /** \brief Converts a value returned by an Expression or its children to floating-point
         *          representation.
         * \return A floating-point representation of the evaluated value of an Expression or its
         *          children.
         */
        float convert ();

        /** \brief Increments the numbers in an Expression.
         */
        virtual void increment();
    protected:
    private:
        string value; // The value of this Expression, if it has already been evaluated.
        Expression* exp; // The Expression contained in this Expression
};

#endif // EXPRESSION_H
