#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "ArithmeticExpression.h"

class Multiplication : public ArithmeticExpression
{
    public:
        /** Constructor **/
        Multiplication();

        /** Destructor **/
        virtual ~Multiplication();

        /** \brief Copy constructor. Copies another Multiplication object's left and right halves
        *           to this one.
        * \param other The other Multiplication to copy.
        * \return A reference to this new object.
        *
        */
        Multiplication (const Multiplication& other);

        /** Assignment operator **/
        Multiplication& operator=(const Multiplication& other);

        /** \brief  Evaluates this Multiplication and returns a string representation of the
         *          result.
         * \return  A string representing the result of the evaluation of this Mutiplication.
         *
         */
        string evaluate();

        /**
        *   \brief Prints this Multiplication expression.
        */
        void print();
    protected:
    private:
};

#endif // MULTIPLICATION_H
