/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: Header for finding the difference
*/

#ifndef SUBTRACTION_H //include gaurd
#define SUBTRACTION_H //header

#include "ArithmeticExpression.h"//extends ArithmeticExpression

class Subtraction : public ArithmeticExpression//class def
{
    public: //public methods and variables
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
        void increment();//will increment each digit recursively

    protected: //no protected values
    private: //no private values
};

#endif // SUBTRACTION_H
