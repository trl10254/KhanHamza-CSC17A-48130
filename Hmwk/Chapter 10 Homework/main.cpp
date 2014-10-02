/* 
 * File:   Chapter 10 Homework
 * Author: Hamza Khan
 *
 * Created on October 2, 2014, 12:15 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;

//Declare function prototypes
int length(char *chararray);
void backward(char *chararray);

void Chapter10Problem1();
void Chapter10Problem2();
void Chapter10Problem3();
void Chapter10Problem4();
void Chapter10Problem5();

int main()
{
    
    return 0;
}


//Chapter 10 Problem 1: Write a function that returns an integer and accepts a 
//pointer to a C-string as an argument. The function should count the number of
//characters in the string and return that number. Demonstrate the function in a
//simple program that asks the user to input a string, passes it to the function,
//and then displays the function's return value.

void Chapter10Problem1()
{
    
    int SIZE = 50;
    char sentence[SIZE];
    int count;
    
    //Ask the user to enter in a sentence
    cout << "Please enter a complete sentence that you want to find the number ";
    cout << "of characters in it." << endl;
    cin.getline(sentence, SIZE);
    
    //Get the length of the sentence
    count = length(sentence);
    
    //Display the total number of characters
    cout << "In your sentence you have a total of " << count; 
    cout << " characters in it." << endl;
   
}
    
int length(char *chararray)
{
    //Declare local variables
    int length = strlen(chararray);
    int spacecount = 0;
    
    //Do a for loop to get the total length
    for (int i = 0; i <= length; i++)
    {
        if (chararray[i] != ' ')
        {
            spacecount++;
        }
    }
    
}

//Chapter 10 Problem 2: Write a function that accepts a pointer to a C-string as  
//an argument and displays its content backward. For instance, if the string 
//argument is "Gravity" the function should display "ytivarG". Demonstrate the 
//function in a program that asks the user to input a string and then passes it  
//to the function.

void Chapter10Problem2()
{
    //Declare local variables
    int SIZE = 100;
    char sentence[SIZE];
    char reflection;
    
    cin.ignore();
    //Get the user to input a line or a word
    cout << "Please enter a phrase or word you want to be read backwards" << endl;
    cin.getline(sentence, SIZE);
    
    //Get the reflection
    backward(sentence);
    
}

void backward(char *chararray)
{
    //Declare local variables
    int stringlength = length(chararray);
    
    cout << "The phrase read backwards is: ";
    
    //Display the backward phase
    for(int i = (stringlength + 1); i >= 0; i--)
    {
        cout << chararray[i];
    }
    
    cout << endl;
}
