/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: Header for finding the difference
*/

#ifndef SUBTRACTION_H 
#define SUBTRACTION_H 

#include "ArithmeticExpression.h"


/*
* This class will inherit methods and variables from Arithmetic Expression
*/
class Subtraction : public ArithmeticExpression
{
    public:  //initialize public variables/methods
        // Constructor
        Subtraction(Expression* left, Expression* right);

        //Destructor
        virtual ~Subtraction();

        Subtraction(const Subtraction& other);

        Subtraction& operator=(const Subtraction& other);

        string evaluate();

        void print();
        void increment();

    protected: 
    private: 
};

#endif 
