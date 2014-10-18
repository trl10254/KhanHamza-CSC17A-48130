/* 
 * File:   main.cpp
 * Author: Hamza Khan
 *
 * Created on October 17, 2014, 2:20 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

//Declare function prototypes
void Problem1();
void Problem2();
void Problem3();
void Problem4();
void Problem5();
void Problem6();
void Problem7();

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
	cout << "1 = Chapter 12 Problem 1" << endl;
        cout << "2 = Chapter 12 Problem 2" << endl;
        cout << "3 = Chapter 12 Problem 3" << endl;
        cout << "4 = Chapter 12 Problem 4" << endl;
        cout << "5 = Chapter 12 Problem 6" << endl;
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
                    
                case 7:
                    Problem7();
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

void Problem1()
{
    
}

void Problem2()
{
    
}

void Problem3()
{
    
}

void Problem4()
{
    
}

void Problem5()
{
    
}

void Problem6()
{
    
}

void Problem7()
{
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
}

system("read -p \"Press enter to continue...\" -n 1 -s");