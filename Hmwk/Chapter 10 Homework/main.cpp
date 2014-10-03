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
int count(string phrase);
void capitalizer(string phrase);
void Chapter10Problem1();
void Chapter10Problem2();
void Chapter10Problem3();
void Chapter10Problem4();
void Chapter10Problem5();

int main()
{
    // Declaring variables
    int problemNumber;
    char cont = 'N';

    // Menu loop to select the problem
    do
    {
        cout << "Please enter the number for the problem you want to run ";
        cout << "or press '0' to exit" << endl;
	cout << "1 = Chapter 10 Problem 1";
        cout << "(I can't get the program to not count the spaces)"<< endl;
        cout << "2 = Chapter 10 Problem 2" << endl;
        cout << "3 = Chapter 10 Problem 3" << endl;
        cout << "4 = Chapter 10 Problem 4" << endl;
        cout << "5 = Chapter 10 Problem 5" << endl;
	cout << "0 = EXIT" << endl;
	cin >> problemNumber;

        // Loop in case the user wants to run the same problem
	do
	{
            switch (problemNumber)
            {
                case 1:
                        Chapter10Problem1();
                        break;
                        
		case 2:
                        Chapter10Problem2();
                        break;
                        
		case 3:
                        Chapter10Problem3();
                        break;
                        
		case 4:
                        Chapter10Problem4();
                        break;
                        
	        case 5:
                        Chapter10Problem5();
                        break;
                        
		case 0:
                        break;
                        
		default:
                        cout<<"That's an invalid entry\n";
                        break;
		}
	}
        
        while(problemNumber < 1 || problemNumber > 7);
                        
        cout << "Do you want to run the ";
        cout << "program again? ('Y' to ";
        cout << "continue or any other key to ";
        cout << "cancel)";
	cin >> cont;

	}while(toupper(cont) == 'Y');
        
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
    
    cin.ignore();
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

//Chapter 10 Problem 3: Write a function that accepts a pointer to a C-string
//as an argument is "Four score and seven years ago" the function should return
//the number 6. Demonstrate the function in a program that asks the user to 
//input a string and then passes it to the function. The number of word in the 
//string should be displayed on the screen.

void Chapter10Problem3()
{
    //Declare local variables
    int SIZE = 100;
    char phrase[SIZE];
    int letters;
    
    cin.ignore();
    //Get the user to enter a phrase
    cout << "Enter a phrase you want to find out how many characters are in";
    cout << " it." << endl;
    cin.getline(phrase,SIZE);
    
    //Determine how many words are in the phrase
    letters = count(phrase);
    
    //Display the number of words are in the phrase
    cout << "In the phrase you typed in there are a total of " << letters;
    cout << " words in it." << endl;
}

int count(string phrase)
{
    //Declare local variables
    int numbercount = 1;
    int length = phrase.length();
    
    //Count how many words are in the sentence
    for (int i = 0; i <= length; i++)
    {
        if(phrase[i] == ' ')
        {
            numbercount++;
        }
    }
    
    return numbercount;
}

//Chapter 10 Problem 4: Modify the program you wrote for Problem 3(Word Counter),
//so it also displays the average number of letters in each word.

void Chapter10Problem4()
{
     //Declare local variables
    int SIZE = 100;
    char phrase[SIZE];
    int letters;
    float wordcount;
    float average;
    
    cin.ignore();
    //Get the user to enter a phrase
    cout << "Enter a phrase you want to find out how many characters are in";
    cout << " it." << endl;
    cin.getline(phrase,SIZE);
    
    //Determine how many words are in the phrase
    letters = count(phrase);
    wordcount = strlen(phrase);
    average = (wordcount - (letters -1))/letters;
    
    //Display the number of words are in the phrase
    cout << setprecision(2) << fixed;
    cout << "In the phrase you typed in, the average is " << letters << endl;
}

//Chapter 10 Problem 5: Write a function that accepts a pointer to a C-string
//as an argument and capitalizes the first character of each sentence in the 
//string. For instance, if the string argument is "hello. my name is Joe. 
//what is your name?" the function should manipulate the string so it contains
//"Hello. My name is Joe. What is your name?" Demonstrate the function in a
//program that asks the user to input a string and then passes it to the 
//function. The modified string should be displayed on the screen.

void Chapter10Problem5()
{
    //Declare local variables
    string uncapped;
    
    cin.ignore();
    //Ask the user to enter a small phrase in lowercase.
    cout << "Please enter a small paragraph that you want to capitalized." << endl;
    getline(cin,uncapped);
    
    //Function to capitalize the phrase
    capitalizer(uncapped);
    
}

void capitalizer(string phrase)
{
    //Declare local variables
    int length = phrase.length();
    
    phrase[0] = toupper(phrase[0]);
    
    //Count how many words
    for(int i = 0; i <= length; i++)
    {
        if(phrase[i] == '.')
        {
            phrase[i + 2] = toupper(phrase[i + 2]);
        }
    }
    
    cout << "Here is the capitalized version of your phrase: " << phrase << endl;
}
