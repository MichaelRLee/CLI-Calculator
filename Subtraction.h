/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This file runs the program
*/

#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "ArithmeticExpression.h"

class Subtraction : public ArithmeticExpression
{
    public:
        /** Default constructor */
        Subtraction(Expression* left, Expression* right);

        /** Default destructor */
        virtual ~Subtraction();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Subtraction(const Subtraction& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Subtraction& operator=(const Subtraction& other);

        /** \brief Evaluates the expression.
         * \return A string representation of the result.
         */
        string evaluate();

        /** \brief Prints the expression.
         */
        void print();
                void increment();

    protected:
    private:
};

#endif // SUBTRACTION_H
