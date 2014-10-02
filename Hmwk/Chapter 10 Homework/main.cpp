/* 
 * File:   Chapter 10 Homework
 * Author: Hamza Khan
 *
 * Created on October 2, 2014, 12:15 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//Declare function prototypes
int length(char *sentence)
{
    //Declare local variables
    int length = strlen(sentence);
    int spacecount = 0;
    
    //Do a for loop to get the total length
    for (int i = 0; i <= length; i++)
    {
        if (sentence[i] == ' ')
        {
            spacecount++;
        }
    }
    
}
int main()
{
    const int SIZE = 50;
    char sentence[SIZE];
    int count;
    
    //Ask the user to enter in a sentence
    cout << "Please enter a complete sentence that you want to find the number ";
    cout << "of characters in it." << endl;
    cin.getline(sentence, SIZE);
    
    //Get the length of the sentence
    count= length(sentence);
    
    //Display the total number of characters
    cout << "In your sentence you have a total of " << count; 
    cout << " characters in it." << endl;
    
    return 0;
}


//Chapter 10 Problem 1: Write a function that returns an integer and accepts a 
//pointer to a C-string as an argument. The function should count the number of
//characters in the string and return that number. Demonstrate the function in a
//simple program that asks the user to input a string, passes it to the function,
//and then displays the function's return value.


