/* 
 * File:   main.cpp
 * Author: hamzakhan
 *
 * Created on October 24, 2014, 6:29 PM
 */

#include <cstdlib>
#include<string>  
#include<sstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    cout <<"Data Encyption\n";
    const int MAX_DIGITS = 4; //local constant variable max digits to 4
    int a, b, c, d; //holds the 4 digits as a b c d
    int digit;

    string input; //string input

    cout <<"Please enter a 4-digit number: \n";
    cin  >> input; //digit;
    

    if(input.size() == MAX_DIGITS)
    {
        istringstream buffer(input); //sstream
        buffer >> digit;
                //cout << digit << endl;
        
        a    = (digit/1000)%10;    // thousands
        b    = (digit/100)%10;    // hundreds
        c    = (digit/10)%10;    // tens
        d    = (digit/1)%10;        // ones

        if(a <= 7 && b <= 7 && c <= 7 && d <= 7)
        {
            cout << "GOOD!\n";

            // encyption start...
            a = (a+3)%8;
            b = (b+3)%8;
            c = (c+3)%8;
            d = (d+3)%8;
            
            //swap a and b
            a=a+b;
            b=a-b;
            a=a-b;

            //swap c and d
            c=c+d;
            d=c-d;
            c=c-d;

            cout << "Encryption afterswap: " << a << b << c << d << endl;


            cout << "Time to decrypt: ";
            cin >> digit;

            if(!cin.fail())
            {
                        a    = (digit/1000)%10;    // thousands
                        b    = (digit/100)%10;    // hundreds
                        c    = (digit/10)%10;    // tens
                        d    = (digit/1)%10;        // ones

                        if(a <= 7 && b <= 7 && c <= 7 && d <= 7)
                        {
                            cout << "GOOD!\n";

                            // decryption start...
                            a = (a+3+10)%8;
                            b = (b+3+10)%8;
                            c = (c+3+10)%8;
                            d = (d+3+10)%8;
            
                            //swap a and b
                            a=a+b;
                            b=a-b;
                            a=a-b;

                            //swap c and d
                            c=c+d;
                            d=c-d;
                            c=c-d;

                            /*
                                ( 6 + 7 ) % 10 is 3

                                To get back again, do this
                                ( 3 - 7 + 10 ) % 10 is 6
                            */

                            cout << "Decyption afterswap: " << a << b << c << d << endl;
                        }
            }
            else
            {
                cout << "Invalid Input\n";
            }
        }
        else
        {
            cout << "Invalid Input \n";
        }
    }
    else
    {
        cout << "Invalid Input\n";
    }

    return 0;
}