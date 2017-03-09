/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This file defines the class which represents the Division of 2 ArithmeticExpressions.
*/

#ifndef DIVISION_H
#define DIVISION_H

#include "ArithmeticExpression.h"

/*
* This class will inherit methods and variables from Arithmetic Expression
*/
class Division : public ArithmeticExpression 
    public: //initialize public variables/methods
        //Constructor
        Division(Expression* left, Expression* right);

        //Desctructor
        virtual ~Division();

        Division(const Division& other);

        Division& operator=(const Division& other);

        string evaluate();


        void print();

        void increment();
    protected:
    private:
};

#endif 
