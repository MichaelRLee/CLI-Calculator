/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This file runs the program
*/

#ifndef ADDITION_H
#define ADDITION_H

#include "ArithmeticExpression.h"
using namespace std;

class Addition : public ArithmeticExpression
{
    public:
        /** Default constructor */
        Addition(Expression* left, Expression* right);

        /** Default destructor */
        virtual ~Addition();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Addition(const Addition& other);

        /** Assignment operator
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
                void increment();

    protected:
    private:
};

#endif // ADDITION_H
