/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This file defines the class which represents an Addition.
*/


#ifndef ADDITION_H
#define ADDITION_H

#include "ArithmeticExpression.h" 
using namespace std; // Need types in this namespace

/*
* This class will inherit methods and variables from Arithmetic Expression
*/
class Addition : public ArithmeticExpression 
{
    public: //initialize public variables/methods
        //Constructor
        Addition(Expression* left, Expression* right);

        //Destructor
        virtual ~Addition();

        Addition(const Addition& other);

        Addition& operator=(const Addition& other);

        string evaluate();

        void print();

        void increment();

    protected:
    private:
};

#endif 
