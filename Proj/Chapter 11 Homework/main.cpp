/* 
 * File:   main.cpp
 * Author: hamzakhan
 *
 * Created on October 18, 2014, 4:25 PM
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * Structures go here
*/
struct Customer 
{
    int acctNum;     // holds account number
    int balance;      // holds balance at beginning of month
    int chkTotal;     // total of all checks written this month
    int deposits;     // total of all deposits credited this month
};


/*
 *  Menu and problemlem protoypes
 */
void problem1();
void problem5();
/*
 * Functions for problem 1
 */
void AcctInfo(Customer *);
void newBalance(Customer *);
bool isOvrdrwn(Customer *);
/*
 * Functions for problem 5
 */
template<class T>
T factorial(T);

template<class T>
T maxFac(T);


int main(int argc, const char * argv[]) 
{
    problem1();
    problem5();
    return 0;
}

void problem1() 
{
    Customer *c = new Customer;
    c->balance=1000;
    AcctInfo(c);
    cout << endl;
    newBalance(c);
    cout << "The current balance on account " << c->acctNum
    << " is: " << c->balance << endl;
    if (isOvrdrwn(c)) 
    {
        cout << "Account was over drawn";
        cout << "An Overdraft fee of 12 dollars was assessed" << endl;
        c->balance-=12;
        cout << "The new balance is: " << c->balance << endl;
    }
    cout << endl;
    delete c;
}


void problem5() 
{
    //Declare local variables
    unsigned uB;
    signed sB;
    unsigned short uS;
    signed short sS;
    signed int sI;
    
    cout << "Largest unsigned byte factorial is: " << maxFac(uB) << endl;
    
    signed sB;
    cout << "Largest signed byte factorial is: " << maxFac(sB) << endl;
    
    unsigned short uS;
    cout << "Largest unsigned short factorial is: " << maxFac(uS) << endl;
    
    signed short sS;
    cout << "Largest signed short factorial is: " << maxFac(sS) << endl;
    
    unsigned int uI;
    cout << "Largest unsigned int factorial is: " << maxFac(uI) << endl;
    
    signed int sI;
    cout << "Largest signed int factorial is: " << maxFac(sI) << endl;
    
    float fl;
    cout << "Largest float factorial is: " << maxFac(fl) << endl;
    
}


// Function calculates factorials
template<class T>
T factorial(T n) 
{
    if (n==0)
        return 1;
    return n*factorial(n-1);
}

template<class T>
T maxFac(T) 
{
    T n=2; // can't use 1, factorial(1) == factorial(0)
    while (factorial(n-1) < factorial(n)) 
    {
        ++n;
    }
    // current n overflows go back one
    return --n;
}

void AcctInfo(Customer *c) 
{
    bool valid = false;
    do 
    {
        cout << "Enter the account number: ";
        cin >> c->acctNum;
        // if account number is more than 5 digits
        // this result will be >= to 1
        if (c->acctNum / 100000 < 1)
            valid=true;
    } while (!valid);
    
    cout << "Enter the current balance: ";
    cin >> c->balance;
    
    cout << endl;
    
    cout << "Were any checks written this month. 'y' for yes: ";
    char response;
    cin >> response;
    if (response == 'y') 
    {
        int amnt;
        do 
        {
            cout << "Enter the amount of the check. -1 to quit: ";
            cin >> amnt;
            c->chkTotal +=amnt;
        } 
        while(amnt>0);
    }
    cout << endl;
    cout << "Were any deposits made this month. 'y' for yes: ";
    cin >> response;
    if (response == 'y') 
    {
        int amnt;
        do 
        {
            cout << "Enter the amount of the deposit. -1 to quit: ";
            cin >> amnt;
            c->deposits += amnt;
        }
        
        while(amnt>0);
    }
}

void newBalance(Customer *c) 
{
    c->balance -= c->chkTotal;
    c->balance += c->deposits;
}

bool isOvrdrwn(Customer *c) 
{
    return (c->balance < 0) ? true: false;
}
//Display answers for problem 6
    cout << "For 2.125 in base 2 is 10.001" << end;
    cout << "For 2.125 in base 8 is 2.1" << endl;
    cout << "For 2.125 in base 16 is 2.2" << endl;
    cout << "For 0.06640625 in base 2 is 0.00010001" << endl;
    cout << "For 0.06640625 in base 8 is 0.042" << endl;
    cout << "For 0.06640625 in base 16 is 0.11" << endl;
    cout << "For -2.125 in float is C0080000" << endl;
    cout << "For 0.06640625 in float is 3D880000" << endl;
    cout << "For 46666601 in decimal is 1.47455009765625E4" << endl;
    cout << "For 46666602 in decimal is 1.4745501953125E4" << endl;
    cout << "For B9999AFE in decimal is -2.92979122605174779891967773438E-4" << endl; 
