/* 
 * File:   Chapter 12 Homework
 * Author: Hamza Khan
 *
 * Created on October 2, 2014, 4:32 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//Function Prototypes
void readLine(fstream &file);
void showFile(fstream &file);
void Chapter12Problem1();
void Chapter12Problem2();
void Chapter12Problem3();
void Chapter12Problem4();
void Chapter12Problem6();

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
                        Chapter12Problem1();
                        break;
                        
		case 2:
                        Chapter12Problem2();
                        break;
                        
		case 3:
                        Chapter12Problem3();
                        break;
                        
		case 4:
                        Chapter12Problem4();
                        break;
                        
	        case 5:
                        Chapter12Problem6();
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
         
}

//Chapter 12 Problem 1:Write a program that asks the user for the name of a 
//file. The program should display the first 10 lines of the file on the screen 
//(the "head" of the file).If the the file has fewer than 10 lines, the entire 
//file should be displayed, with a message indicating the entire file has been 
//displayed.

void Chapter12Problem1()
{
    ifstream inputFile;
    bool failed;	
    int lineCount=0;	
    string line;	
    string fileName;
    char choice;
    
    //Open file with fail condition. DONT FORGET TO CLOSE THE FILE!!!!!
    do
    {
        failed = false;	//Set the flag to 'false' for a fresh start.
        
        //Get file name from user.
        cout << "Please enter the name of the file you want to open: ";
        cin >> fileName;
		
	cout << endl;
	//Test file opening.
	inputFile.open(fileName.c_str(),ios::in);
	if(inputFile.fail())
        {
            cout << "File opening failed! Be sure to include the file extension." << endl;
            failed=true;
	}
        
        else if(inputFile.eof())
        {
            cout << "This file is empty!" << endl;
            cout << "Give me something with SOMETHING in it!" << endl;
            failed=true;
        }
    }
    while(failed==true);
    
    while(lineCount<10 && !inputFile.eof())
    {
        //	Get line from file
	getline(inputFile,line,'\n');
	//	Write line to console
	cout << line << endl;
	//	Increment counter
	lineCount++;
    }
    
    if (lineCount < 10)
    {
        cout << endl << "The entire file has been displayed." << endl;
    }
    
    else
    {
        cout << endl << "The 10 lines above make up the 'HEAD' of the '" << fileName << "' file." << endl;
    }
    
    inputFile.close();
}

//Chapter 12 Problem 2: Write a program that asks the user for the name of a file.
//The program should display the contents of the file on the screen. If the file's
//contents won't fit on a single screen, the program should display 24 lines of 
//output at a time, and then pause. Each time the program pauses, it should wait
//for the user to strike a key before the next 24 lines are displayed.

void Chapter12Problem2()
{
    ifstream inputFile;
    bool failed;	
    int linePer=24;	
    int lineCount=0;	
    int newCount=0;	
    string line;	
    string fileName;		
    char ch;
    char choice;
    
    do
    {
        failed=false;	//Set the flag to 'false' for a fresh start.
        
        //Get file name from user.
        cout << "Please enter the name of the file you want to open and get a line count: ";
        cin >> fileName;
        cout << endl;
            
        //Test file opening.
        inputFile.open(fileName.c_str(),ios::in);
        if(inputFile.fail())
        {
            cout << "File opening failed! Be sure to include the file extension.\n";
            failed=true;
        }
            
        else if(inputFile.eof())
        {
            cout << "This file is empty!" << endl;
            cout << "Give me something with SOMETHING in it!" << endl;
            failed=true;
        }
    }
    
    while(failed == true);
    inputFile.close();
	
    inputFile.open(fileName.c_str(), ios::in);
    
    while(!inputFile.eof())
    {
        getline(inputFile, line, '\n');
        lineCount++;
    }
    inputFile.close();

    cout << "There are " << lineCount << " line(s) in this file.\n";

    inputFile.open(fileName.c_str(), ios::in);

    while(!inputFile.eof())
    {
        if(lineCount < linePer)
        {
            for(int i = 0; i < lineCount; i++)
            {
                cin.ignore();
                getline(inputFile,line,'\n');
                cout << line << endl;
            }
        }
            
        else if(lineCount >= linePer)
        {
            for(int i = 0; i < linePer; i++)
            {
                getline(inputFile,line,'\n');
                cout << line << endl;
                lineCount--;
            }
            system("pause");
        }
    }
    inputFile.close();
}

//Chapter 12 Problem 3: Write a program that reads and prints a joke and its 
//punch line from two different files. The first file contains a joke, but not its
//punch line. the second file has the punch line as its last line, preceded by 
//"garbage." The main function of your program should open the two files and then 
//call two function, passing each one the file its needs. the first function should
//read and display each line in the file it is passed (the joke file). the second
//function should display only the last line of the file it is passed (the punch line file).
//It should find this line by seeking tot he end of the file and then backing up
//to the the end of the file and then backing up to the beginning of the last
//line. Data to test your program can be found in the joke.txt and punchline.txt
//file.
void Chapter12Problem3()
{
    //Declare local variables
    string input;      
    fstream joke, punch;   
    char choice;        
    do
    {
        //Open Files
        joke.open("joke.txt", ios::in);
        punch.open("punchline.txt", ios::in);

        //Send files to functions
        showFile(joke);
        readLine(punch);
        
    //repeat program?
    do
    {                                                   
        cout << "Would you like to try again? (y|n)";
        cin >> choice;
    }
        while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
    }
    while(choice == 'y' || choice == 'Y');
}

void showFile(fstream &file)
{
    //Declare local variables
    string line;
    
    do
    {
        getline(file, line);
        cout << line << endl;
    } 
    while(!file.eof());
}

void readLine(fstream &file)
{
    //Declare local variable
    string line;
    int numLines;
    
    while(file)
    {
        
        getline(file,line);
        numLines++;
        //cout<<numLines<<endl;
    
    }
    
    cout<<"---This is a real hoot of a joke----" << endl;
    for(int i = 0; i <= numLines; i++)
    {
        
        getline(file,line);
        
        if(i == numLines - 1)
        {
            
            cout << line << endl;
            cout << "Audience reaction: ";
            cout << "BOOO! That joke was utter garbage! Get off the stage!" << endl;
        
        }
    }
}

//Chapter 12 Problem 4: Write a program that asks the user for the name of a file.
//The program should display the last 10 lines of the file on the screen (the "tail" of the file).
//If the file has fewer than 10 lines, the entire file should be displayed, with 
//a message indicating the entire file has been displayed.

void Chapter12Problem4()
{
    fstream file;  
    string name; 
    int SIZE = 1000;  
    string nameArray[1000];  
    int count = 0; 
    char choice;

    cin.ignore();
    // Input name of file
    cout<<"What is the file name? ('numbers.txt') ";
    getline(cin, name);

    //Opens file name from the input
    file.open(name.c_str(),ios::in);
    if(file.fail())
    {
        cout << "Error opening the file" << endl;
    }

    while(file) // Loading array
    {
        getline(file, nameArray[count]);
        count++;
    }
    
    count = (count - 1);
    
    if(count <= 10)  // Case the file has less than 10 lines
    {
        cout << "This is everything in the file" << endl;
        for (int i = 0; i <= count; i++)
        {
            cout << nameArray[i] <<endl;
        }
    }
    
    else if(count > 10) // Printing the last 10 lines in file
    {
        cout << "These are the last 10 lines" << endl;
        for(int f = (count - 10); f < count; f++)
        {
            cout << nameArray[f] <<endl;
        }
    }
    
    file.close();
    
   
}

//Chapter 12 Problem 6: Write a program that asks the user for a file name and a 
//string to search for. The program should search the file for every occurrence 
//of a specified string. When the string is found, the line that contains it 
//should be displayed. After all the occurrences have been located, the program
//should report the number of times the string appeared in the file.

void Chapter12Problem6()
{
    //Declare local variables
    fstream file;    
    string name;     
    int count = 1;   
    string search;   
    int foundTimes = 0;  
    int size = 100;     
    int foundLines[size]; 
    string browsing;  
    char choice;

    cin.ignore();
    // Input file name
    cout << "What is the file name? ('numbers.txt') ";
    getline(cin, name);

    //Opens file name from the input
    file.open(name.c_str(), ios::in);
    
    if(file.fail())
    {
        cout << "\nError opening the file" << endl;
    }
    
    // Input string to search
    cout << "\nWhat string would you like to search in the file? ";
    getline(cin, search);

    while(!file.eof())  // Loop to read file and compare
    {
        getline(file, browsing);
        if(browsing == search)
        {
            foundTimes++;
            foundLines[foundTimes] = count;
        }
        count++;
    }
    
    file.close();
    
    cout << endl;
    
    // Printing the number of times found and the line number it was found
    cout << search << " was found " << foundTimes << " in the file. In lines: ";
    
    for(int g = 1; g <= foundTimes; g++)
    {
        cout << foundLines[g] << " ";
    }
    
    cout << endl;

}