/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: Header for multiplication stuff
*/

#ifndef MULTIPLICATION_H 
#define MULTIPLICATION_H 

#include "ArithmeticExpression.h" 


/*
* This class will inherit methods and variables from Arithmetic Expression
*/
class Multiplication : public ArithmeticExpression
{
    public: //initialize public variables/methods
        //Constructor
        Multiplication(Expression* left, Expression* right); 

        //Destructor
        virtual ~Multiplication();

        Multiplication (const Multiplication& other); 

        Multiplication& operator=(const Multiplication& other); 

        string evaluate ();

        void print ();
        void increment(); 

    protected:
    private: 
};

#endif 
