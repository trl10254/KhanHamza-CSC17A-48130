/* 
 * File:   SavingsAccount.h
 * Author: Hamza Khan
 *
 * Created on December 7, 2014, 1:05 PM
 */

#ifndef SAVINGSACCOUNT_H
#define	SAVINGSACCOUNT_H

class SavingsAccount
{
    public:
        SavingsAccount(float);               //Constructor
        void  Transaction(float);            //Procedure
        float Total(float,int);	         //Savings Procedure
        float TotalRecursive(float,int);
        void  toString();                    //Output Properties
    private:
        float Withdraw(float);               //Utility Procedure
        float Deposit(float);                //Utility Procedure
        float Balance;                       //Property
        int   FreqWithDraw;                  //Property
        int   FreqDeposit;                   //Property
};

#endif	/* SAVINGSACCOUNT_H */

