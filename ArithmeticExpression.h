/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This file defines all methods and properties common to all ArithmeticExpressions.
*/

/* Beginning of include guard */
#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H

#include "Expression.h" // Parent class

class ArithmeticExpression : public Expression // Inherits from the Expression class
{
    public:

        /** Constructs an ArithmeticExpression object with empty left and right sides. */
        ArithmeticExpression();

        /** Constructs an ArithmeticExpression object with copies of the given expressions stored as its
        left and right hand sides. **/
        ArithmeticExpression(Expression* left, Expression* right);

        /** \brief Constructs a top-level ArithmeticExpression.
         *
         * \param finalExp The expression contained in this top-level ArithmeticExpression.
         *
         */
        ArithmeticExpression(Expression* finalExp);

        /** Destroys an ArithmeticExpression. Made virtual to allow for polymorphic destruction. */
        virtual ~ArithmeticExpression();

        /** Copy constructor
         *  \param other Object to copy from
         */
        ArithmeticExpression(const ArithmeticExpression& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        ArithmeticExpression& operator=(const ArithmeticExpression& other);

        /** Access left
         * \return The current value of left
         */
        Expression* Getleft() { return left; }

        /** Set left
         * \param val New value to set
         */
        void Setleft(Expression* val) { left = val; }

        /** Access right
         * \return The current value of right
         */
        Expression* Getright() { return right; }

        /** Set right
         * \param val New value to set
         */
        void Setright(Expression* val) { right = val; }

        /** \brief Evaluates left and right expression and combines them with the appropriate operator.
         * \return A string representation of the result.
         */
        string evaluate();

        /** \brief Prints the evaluated expression.
         */
        void print();

        /** \brief Converts a string (as returned by evaluate) to a float.
         *
         * \param s The string representing the value to convert to a floating-point number.
         * \return A floating-point representation of the string.
         */
        float convert(string s);

        /** \brief Increments the numbers in this ArithmeticExpression
         */
        void increment();
    protected:
        Expression *left; //!< The left half of the ArithmeticExpression
        Expression *right; //!< The right half of the ArithmeticExpression.
};

/* End include guard */
#endif // ARITHMETICEXPRESSION_H
