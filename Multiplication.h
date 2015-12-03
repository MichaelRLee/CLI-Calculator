#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "ArithmeticExpression.h"



class Multiplication : public ArithmeticExpression
{
    public:
        Multiplication();

        virtual ~Multiplication();

        Multiplication (const Multiplication& other);

        Multiplication& operator=(const Multiplication& other);

        string evaluate ();

        void print ();
    protected:
    private:
};

#endif // MULTIPLICATION_H
