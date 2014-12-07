#include "SavingsAccount.h"
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>

float SavingsAccount::Deposit(float cash)
{
    Balance += cash;
    FreqDeposit++;
}
float SavingsAccount::Total(float savint, int time)
{
    if(time<=0)
    {
        return Balance;
    }
    float exponent = (1.0 + savint);
    for(int i=1; i<time; i++)
    {
        exponent *= (1.0 + savint);
    }
    
    return Balance * exponent;
}
float SavingsAccount::TotalRecursive(float savint, int time)
{
    if(time<=0)
    {
        return Balance;
    }
    else if(time==1)
    {
        return Balance * (1.0 + savint);
    }
    else
    {
        return (1.0 + savint) * TotalRecursive(savint,--time);
    }   
}
void SavingsAccount::Transaction(float check)
{
    if(check > 0)
    {
        Deposit(check);
    }
    else
    {
        Withdraw(check);
    }
}
float SavingsAccount::Withdraw(float check)
{
    if(check > Balance)
    {
        std::cout<<std::endl<<"INSUFFICIENT FUNDS $("<<check<<") AMOUNT INVALID"<<std::endl<<std::endl;
    }
    else
    {
        Balance -= check;
        FreqWithDraw++;
    }
    
}
void SavingsAccount::toString()
{
    //Create string stream and push values to create a giant string
    std::stringstream data;
    data<<"||  Transaction History                                       ||"<<std::endl
        <<"||============================================================||"<<std::endl
        <<"||  Current Balance  :  $"<<Balance<<std::endl
        <<"||  Deposits Made    :   "<<FreqDeposit<<std::endl
        <<"||  Checks Written   :   "<<FreqWithDraw<<std::endl
        <<"||============================================================||"<<std::endl;   
    
   
    std::cout<<data.str()<<std::endl;
}
SavingsAccount::SavingsAccount(float cash)
{
    if(cash < 0)
    {
        Balance = 0;
        std::cout<<std::endl<<"VALUE OF BALANCE ("<<cash<<") INVALID, INITIALIZING TO ZERO"<<std::endl<<std::endl;
    }
    else
    {
        Balance = cash;
    }
  //Initialize everything else to 0
    FreqWithDraw = 0;
    FreqDeposit = 0;
}
