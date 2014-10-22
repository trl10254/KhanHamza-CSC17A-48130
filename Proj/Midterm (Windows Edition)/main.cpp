/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 22, 2014, 11:13 AM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

//Structure for bank account information
struct account 
{
    int acctNum;     // holds account number
    int balance;      // holds balance at beginning of month
    int chkTotal;     // total of all checks written this month
    int deposits;     // total of all deposits credited this month
};

struct statsResult 
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

//Declare function prototypes
void Problem1();
void Problem2();
void Problem3();
void Problem4();
void Problem5();
void Problem6();

//Functions for Problem 1
void AcctInfo(account *c);
void newBalance(account *c);
bool isOvrdrwn(account *c);

//Functions for Problem 4
int *intArray(int, int=4);
int encrypt(int *, int=4);
int decrypt(int *, int=4);
void swap(int &a, int &);
bool isValid(int*, int =4);

//Functions for Problem 5
template<class T>
T factorial(T);
template<class T>
T maxFac(T);

int main(int argc, char** argv) 
{
    // Declaring variables
    int problemNumber;
    char cont = 'N';

    // Menu loop to select the problem
    do
    {
        cout << "Please enter the number for the problem you want to run ";
        cout << "or press '0' to exit" << endl;
	cout << "1 = Problem 1" << endl; //done
        cout << "2 = Problem 2" << endl; //still need to finish
        cout << "3 = Problem 3" << endl; //still need to finish
        cout << "4 = Problem 4" << endl; //still need to finish
        cout << "5 = Problem 5" << endl; //done
        cout << "6 = Problem 6" << endl; //done
	cout << "0 = EXIT" << endl;
	cin >> problemNumber;

        // Loop in case the user wants to run the same problem
	do
	{
            switch (problemNumber)
            {
                case 1:
                    Problem1();
                    break;
                        
		case 2:
                    Problem2();
                    break;
                        
		case 3:
                    Problem3();
                    break;
                        
		case 4:
                    Problem4();
                    break;
                        
	        case 5:
                    Problem5();
                    break;
                    
                case 6:
                    Problem6();
                    break;
                 
		case 0:
                        break;
                        
		default:
                        cout<<"That's an invalid entry\n";
                        break;
		}
	}
        
        while(problemNumber < 1 || problemNumber > 8);
                        
        cout << "Do you want to run the ";
        cout << "program again? ('Y' to ";
        cout << "continue or any other key to ";
        cout << "cancel)";
	cin >> cont;

	}
    
    while(toupper(cont) == 'Y');
         
}

//Problem 1: Develop an application using structures for a customer that will 
//determine if he/she has exceeded his/her checking account balance. For each 
//customer, the following facts are available:
//a. Account number (Five digits only, i.e. test for this)
//b. Balance at the beginning of the month 
//c. Total of all checks written by this customer this month. Loop until 
//   customer is through entering checks.
//d. Total of all deposits credited to this customer's account this month.  
//   Loop until customer is through entering deposits.
//The program should input each of these facts from input dialogs as integers, 
//store in a structure, calculate the new balance, display the new balance and 
//debit the account $12 if overdrawn. Also, if overdrawn, tell the customer the 
//additional $12 fee has been accessed and what the balance would be with this 
//fee included.

void Problem1()
{
    account *c = new account;
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

void AcctInfo(account *c) 
{
    bool valid = false;
    do 
    {
        cout << "Enter the five digit account number: ";
        cin >> c->acctNum;
        // if account number is more than 5 digits
        // this result will be >= to 1
        if (c->acctNum / 100000 < 1)
            valid=true;
    } while (!valid);
    
    cout << "Enter the current balance in the account: ";
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

void newBalance(account *c) 
{
    c->balance -= c->chkTotal;
    c->balance += c->deposits;
}

bool isOvrdrwn(account *c) 
{
    return (c->balance < 0) ? true: false;
}

//Problem 2:  Develop an application using an array of structures that will 
//determine the gross pay for any number of employees input. The company pays 
//"straight-time" for the first 20 hours worked, double time for all hours 
//worked in excess of 20 hours but less than 40 hours, and triple time for any 
//hours worked over 40 hours.
//The program should be able to loop and input the employee's name, hours worked, 
//and the rate of pay.  Once this has been done then the gross pay should be 
//calculated.  Output all the pertinent information with respect to the employee 
//as a check and the process starts all over again until you input an invalid 
//rate of pay or hours worked.  This means a negative rate of pay or negative 
//number of hours worked is not acceptable.

void Problem2()
{
    
}

//Problem 3: Write a function using the following structure and prototype.

//struct statsResult
//{
//    float avg;
//    float median;
//    int *mode;   //array containing the modes
//    int nModes;  //number of modes in the array
//    int maxFreq; //max frequency of modes
//};

//statsResult *avgMedMode(int *,int); 

//The function takes in an integer array and the size of the array. Then returns 
//a pointer to a structure containing the average, median and mode.  You will 
//then write a printStat() function that will print the results contained in the 
//stats structure.  I will input a small array to test this out so ask for how 
//many inputs to fill the array, then the values to place into the array.  
//Make sure you delete the dynamic array creation for the mode when you exit 
//the problem.
        
void Problem3()
{
    
}

//Problem 4: A company wants to transmit data over the telephone, but they are 
//concerned that their phones may be tapped. All of their data is transmitted as 
//four-digit integers. However, they utilize the digits 0,1,2,3,4,5,6,7 only. 
//They have asked you to write a program that will encrypt their data so that it 
//may be transmitted more securely. Your application should read a four-digit 
//integer with the numbers 0 to 7 entered by the user in an input dialog and 
//encrypt it as follows: Replace each digit by (the sum of that digit plus 
//3) modulus 8. Then swap the first digit with the second, and swap the third 
//digit with the fourth. Then print the encrypted integer. Write a separate 
//application that inputs an encrypted four-digit integer and decrypts it to 
//form the original number.
//Note:  sometimes errors occur and the digits 8, and 9 might appear. Detect 
//this condition and flag the error.  Can't read in numbers individually.  
//All the digits must be read with one cin statement.

void Problem4()
{
   cout << "Do you want to encrypt or decrypt a number.\n"
            "Enter 1 to encrypt\n"
            "Enter 2 to decrypt: ";
    int ans;
    cin >> ans;
    int num;
    cout << "Enter your number: ";
    cin >> num;
    int *numArray = intArray(num);
    // check whether number entered is valid
    if (isValid(numArray)) {
        if ( ans == 1) {
            cout << "Your encrypted number is: " << encrypt(numArray);
        }
        else if (ans == 2) {
            cout << "Your decrypted number is: " << decrypt(numArray);
        }
        else
            cout << "Invalid choice: ";
    }
    // number was not valid
    else
        cout << "Number was not valid.\n";
    
    cout << endl; 
}

int *intArray(int num, int size) 
{
    // create the array to hold the numbers
    int *ret = new int [size];
    for (int i = size-1; i >= 0; --i) 
    {
        ret[i] = num % 10;
        num /= 10;
    }
    return ret;
}

bool isValid(int*array, int size) 
{
    for (int i = 0; i != size; ++i)
        // only 0 to 7 are allowed
        if (*(array+i) >7)
            return false;
    return true;
}

int encrypt(int *array, int size) 
{
    for (int i = 0; i != size; ++i)
    {
        // first add three to each digit
        *(array+i) += 3;
        // then mod it by 8
        *(array+i) %= 8;
    }
    
    // swap elements 1,2 and 3,4
    swap(*(array), *(array+1));
    swap(*(array+2), *(array+3));
    
    // turn array back into int;
    int ret=0;
    for (int i = 0, power = size-1; i != size; ++i, --power)
        ret +=(*(array+i)*pow(10,power)); // ret + a[i] * 10^size-1)

    return ret;
}

int decrypt(int *array, int size) 
{
    // swap back elements 1,2 and 3,4
    swap(*(array), *(array+1));
    swap(*(array+2), *(array+3));
    
    // unmod the numbers
    for (int i = 0; i != size; ++i)
    {
        if (*(array+i) <3)
            *(array+i) = 8+ *(array+i);
        else
            *(array+i) = *(array+i);
        cout << *(array+i) << endl;
        // undo the addition
        *(array+i) -= 3;
    }
    
    // turn array back into int;
    int ret=0;
    for (int i = 0, power = size-1; i != size; ++i, --power)
        ret +=(*(array+i)*pow(10,power)); // ret + a[i] * 10^size-1)

    return ret;
}

void swap(int &a, int &b) 
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//Problem 5: a) Using a byte variable, what is the largest factorial that can 
//be calculated.  A factorial is simply: n! = 1 * 2 * 3 * 4 ... * (n-2) * (n-1) * n
//For instance, 1! = 1,  2! = 2,  3! = 6,  4! = 24,  5! = 120 etc....
//b)  What would be the largest factorial using short, int, long, float, double, 
//etc...  Use all the primitive data types that you are familiar with.
//Note:  I want you to have fun investigating this and the program you turn in 
//should just print "cout" the final results.  You don't know how to capture 
//errors yet so run each till it overflows then back off by 1. Don't need the 
//program that tests for this.
        
void Problem5()
{
    //Declare local variables
    unsigned uB;
    signed sB;
    unsigned short uS;
    unsigned int uI;
    signed short sS;
    signed int sI;
    float fl;
    
    //Display output
    cout << "Largest unsigned byte factorial is: " << maxFac(uB) << endl;
    cout << "Largest signed byte factorial is: " << maxFac(sB) << endl;
    cout << "Largest unsigned short factorial is: " << maxFac(uS) << endl;
    cout << "Largest signed short factorial is: " << maxFac(sS) << endl;
    cout << "Largest unsigned integer factorial is: " << maxFac(uI) << endl;
    cout << "Largest signed integer factorial is: " << maxFac(sI) << endl;
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

//Problem 6: a) Convert the following 2 numbers to binary, octal and hex.
//2.125, 0.06640625. When done, convert the following to a float representation.
//-2.125, 0.06640625.  In other words, I want an 8 digit hex number representation 
//using the 4 byte float specification.
//b) Convert the float representations of the following into the decimal number.
//46666601, 46666602, B9999AFE.
//Note:  This doesn't require a program, however, I want you to write a simple 
//function that outputs the answers you did by hand with "cout".
        
void Problem6()
{
    //Display answers for problem 6
    cout << "2.125 in base 2 is 10.001" << endl;
    cout << "2.125 in base 8 is 2.1" << endl;
    cout << "2.125 in base 16 is 2.2" << endl;
    cout << "0.06640625 in base 2 is 0.00010001" << endl;
    cout << "0.06640625 in base 8 is 0.042" << endl;
    cout << "0.06640625 in base 16 is 0.11" << endl;
    cout << "-2.125 in float is C0080000" << endl;
    cout << "0.06640625 in float is 3D880000" << endl;
    cout << "46666601 in decimal is 1.47455009765625E4" << endl;
    cout << "46666602 in decimal is 1.4745501953125E4" << endl;
    cout << "B9999AFE in decimal is -2.92979122605174779891967773438E-4" << endl;
}

