/* 
 * File:   main.cpp
 * Author: Hamza Khan
 *
 * Created on October 13, 2014, 7:16 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cstring>

using namespace std;

//Structure for the character creator
struct Character
{
    char name;
    char location;
    int age;
};

//Declare function prototypes
Character getInfo();
void startgame();

int main(int argc, char** argv) 
{
    //Declare local variables
    int option;
    char cont = 'N';
    
    cout << " Land of Osirus (alpha) " << endl << endl;
    
    do
    {
        cout << "Please select what you want to do." << endl;
        cout << "1. Start game" << endl;
        cout << "2. Quit" << endl;
        cin >> option; 
        
        do
        {
            switch (option)
            {
                case 1: 
                    startgame();
                    break;
                    
                case 2:
                    break;
                    
                default:
                    cout << "Please chose either 1 or 2. Thank you.";
                    break;
            }
        }
        while (option < 1 || option > 3);
        
        cout << "Do you want to run the game again? If so press 1 if not press 2";
        cin >> cont;  
    }
    
    while (toupper(cont) == 1);
}

void startgame()
{
    //Declare local variables
    
    
    //Set up the legend
    cout << "There's a legend that has been passed around for centuries about ";
    cout << "portals opening up in the middle of no where and taking poor souls ";
    cout << "to an unfamiliar land and when they return that person isn't the same ";
    cout << "person that disappeared. Oh well it's just a legend so it can't be true.";
    cout << "Or is it." << endl << endl;
    
    //Go into the character creator to set up player profile
    getInfo();
    
    
    
    
    
}

Character getInfo()
{
    Character creator;
    
    cout << "Welcome to the character creator v0.1";
            
    //Name your character
    cout << "Please enter a name that you want to be called: ";
    cin >> creator.name;
    
    //Get the age of the character
    cout << "What age do you want to be: ";
    cout << "Just write the number don't spell it out.";
    cin >> creator.age;
    
    //Get the start location of the character
    cout << "Where are you at: ";
    cout << "You can make up the location";
    cin >> creator.location;
    
    //Display the information of the character
    cout << "The name you want to be called is: " << creator.name << endl;
    cout << "You are from: " << creator.location << endl;
    cout << "The age you want to be is: " << creator.age << endl;
    
    return (creator.name, creator.age, creator.location);
}


