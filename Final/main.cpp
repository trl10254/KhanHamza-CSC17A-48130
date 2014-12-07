/* 
 * File:   main.cpp
 * Author: Hamza Khan
 *
 * Created on December 7, 2014, 12:53 PM
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

//Header Files
#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3TableInherited.h"
#include "SavingsAccount.h"
#include "Employee.h"

//Namespace
using namespace std;

//Function Prototypes
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void toContinue();

int main(int argc, char** argv){
    int num;
    do{
        cout<<"||============================================================||"<<endl
            <<"||  Bradd's CSC-17A - FINAL SPRING 2014 - 42448               ||"<<endl
            <<"||============================================================||"<<endl
            <<"||  [1] Problem 1 - Random Sequence                           ||"<<endl
            <<"||  [2] Problem 2 - All Kinds of Sorting                      ||"<<endl
            <<"||  [3] Problem 3 - Spreadsheet Stuff                         ||"<<endl
            <<"||  [4] Problem 4 - Savings Account Class                     ||"<<endl
            <<"||  [5] Problem 5 - Employee Class                            ||"<<endl
            <<"||  [6] FLOAT CONVERSION                                      ||"<<endl
            <<"||  [0] EXIT PROGRAM                                          ||"<<endl
            <<"||============================================================||"<<endl
            <<"||  Enter choice:  ";
        cin>>num;
        cin.ignore();
      //Switch statement
        switch(num)
        {
            case 0: 
                break;
                
            case 1: 
                problem1(); 
                break;
                
            case 2: 
                problem2(); 
                break;
                
            case 3: 
                problem3(); 
                break;
                
            case 4:
                problem4(); 
                break;
                
            case 5: 
                problem5(); 
                break;
                
            case 6: 
                problem6(); 
                break;
        }
    }
    while(num);
  //Exit Stage Right
    return 0;
}

void problem1()
{
    cout<<"||============================================================||"<<endl
        <<"||  Problem 1 - Random Sequence                               ||"<<endl
        <<"||============================================================||"<<endl;
    char n=5;
    char rndseq[]={16,34,57,79,121};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    unsigned seed=time(0);
    srand(seed);
    for(int i=1;i<=ntimes;i++)
    {       
            a.randFromSet(rand()%n);
    }
    int *x=a.getFreq();
    const char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
            cout<<"||  "<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"||  The total number of random numbers is "<<a.getNumRand()<<endl
        <<"||============================================================||"<<endl;
    
    toContinue();
}

void problem2()
{
    cout<<"||============================================================||"<<endl
        <<"||  Problem 2 - All Kinds of Sorting                          ||"<<endl
        <<"||============================================================||"<<endl;
    Prob2Sort<string> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    string ch[10];
    int i=0;
    while(getline(infile,ch[i])){cout<<ch[i]<<endl;i++;}
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column (0-14):  "<<endl;
    int column;
    cin>>column;
    cin.ignore();
    string *zc = rc.sortArray(ch,10,column,ascending);
    for(int i=0;i<10;i++)
    {
        cout<<zc[i]<<endl;
    }
    cout<<endl;
    toContinue();
}

void problem3()
{
    cout<<"||============================================================||"<<endl
        <<"||  Problem 3 - Spreadsheet Stuff                             ||"<<endl
        <<"||============================================================||"<<endl;
    int rows=5;
    int cols=6;
    
    Prob3TableInherited<int> table(const_cast<char*>("Problem3.txt"),rows,cols);
    const int *naugT=table.getTable();
    cout<<"||============================================================||"<<endl
        <<"||  Original Table                                            ||"<<endl
        <<"||============================================================||"<<endl;
    
    for(int i=0;i<rows;i++)
    {
            for(int j=0;j<cols;j++)
            {
                    cout<<"  "<<naugT[i*cols+j];
            }
            cout<<endl;
    }
    cout<<endl;
    const int *augT=table.getAugTable();
    cout<<"||============================================================||"<<endl
        <<"||  Augmented Table                                           ||"<<endl
        <<"||============================================================||"<<endl;
    for(int i=0;i<=rows;i++)
    {
            for(int j=0;j<=cols;j++)
            {
                    cout<<"  "<<augT[i*(cols+1)+j];
            }
            cout<<endl;
    } 
    toContinue();
}

void problem4()
{
    cout<<"||============================================================||"<<endl
        <<"||  Problem 4 - Savings Account Class                         ||"<<endl
        <<"||============================================================||"<<endl;
    srand(time(0));
    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++)
    {
            mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"||============================================================||"<<endl
        <<"||  Non-Recursive Calculation:                                ||"<<endl
        <<"||     Balance after 7 years given 10% interest = $"
        <<mine.Total(0.10,7)<<endl;
    cout<<"||============================================================||"<<endl
        <<"||  Recursive Calculation                                     ||"<<endl
        <<"||     Balance after 7 years given 10% interest = $"
        <<mine.TotalRecursive(0.10,7)<<endl
        <<"||============================================================||"<<endl;
    toContinue();
}

void problem5()
{
    cout<<"||============================================================||"<<endl
        <<"||  Problem 5 - Employee Class                                ||"<<endl
        <<"||      EXTRA CREDIT #1:  toString() returns char*            ||"<<endl
        <<"||============================================================||"<<endl;
    Employee Mark(const_cast<char*>("Mark"),const_cast<char*>("Boss"),215.50);
    Mark.setHoursWorked(-3);
    cout<<string(Mark.toString());
    Mark.CalculatePay(Mark.setHourlyRate(20.0),
            Mark.setHoursWorked(25));
    cout<<string(Mark.toString());
    Mark.CalculatePay(Mark.setHourlyRate(40.0),
            Mark.setHoursWorked(25));
    cout<<string(Mark.toString());
    Mark.CalculatePay(Mark.setHourlyRate(60.0),
            Mark.setHoursWorked(25));
    cout<<string(Mark.toString());

    Employee Mary(const_cast<char*>("Mary"),const_cast<char*>("VP"),50.0);
    cout<<string(Mary.toString());
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(40));
    cout<<string(Mary.toString());
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(50));
    cout<<string(Mary.toString());
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(60));
    cout<<string(Mary.toString());
    
    toContinue();
}

void problem6()
{
    cout<<"||============================================================||"<<endl
        <<"||  Problem 6 - Float Conversion                              ||"<<endl
        <<"||============================================================||"<<endl
        <<"||      4207999a(base 10) = (float)                    ||"<<endl
        <<"||        23.76 =                                             ||"<<endl
        <<"||   Step 1:    = 1  7   .  C    2    8    F    5...(hex)     ||"<<endl
        <<"||   Step 2:    = 1 0111 . 1100 0010 1000 1111 0101 (bin)     ||"<<endl
        <<"||   Step 3:    = 0.101 1111 0000 1010 0011 1101 * 2^5 (bin)  ||"<<endl
        <<"||   Step 4:    =  0101 1111 0000 1010 0011 1101 0000 0101    ||"<<endl
        <<"||   Step 5:    =   5    F    0    A    3    D    0    5      ||"<<endl
        <<"||============================================================||"<<endl;
    toContinue();

}

void toContinue()
{
    cout<<"||  Press ENTER to continue..."<<endl;
    cin.ignore();
}