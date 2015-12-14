/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: Header for multiplication stuff
*/

#ifndef MULTIPLICATION_H //def gaurd
#define MULTIPLICATION_H //header def

#include "ArithmeticExpression.h" //child of ArithmeticExpression



class Multiplication : public ArithmeticExpression //class deff
{
    public: //public variables and methods
        Multiplication(Expression* left, Expression* right); //constructor with left and right hand side parameters

        virtual ~Multiplication(); //destructor

        Multiplication (const Multiplication& other); //copy constructor

        Multiplication& operator=(const Multiplication& other); //= opperator def

        string evaluate (); //evaluate expression (multiplies)

        void print (); //prints expression 
        void increment(); //increment digits by 1

    protected: //no protected values
    private: //no private values
};

#endif // MULTIPLICATION_H
