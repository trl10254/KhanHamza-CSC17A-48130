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

//Declare structure
struct charactercreator
{
    string firstname;
    string lastname;
    int choice;
};

//Declare function prototypes

int main()
{
    //Character profile in a structure
    charactercreator creation;
    
    //Declare local variables
    string firstname;
    string lastname;
    int choice;
    
    //Set up the back story to the adventure
    cout << "There was a legend a told by the native Americans saying that ";
    cout << "every time you go to sleep at night your soul travels to ";
    cout << "different worlds and that in the mornings it travels back to your ";
    cout << "body, but if it doesn't get back to your body in time it is trapped ";
    cout << "in that world until nightfall. Until your soul doesn't get back to ";
    cout << "your body you are left in a coma and after three days you and your ";
    cout << "soul start to die." << endl;
    system("read -p \"Press enter...\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Night guys I'm gonna go to sleep." << endl;
    system("read -p \"Press enter...\" -n 1 -s");
    cout << " " << endl << endl;
    
    //Opening scene
    cout << "Tap. . . Tap. . . Tap" << endl;
    cout << "Mysterious voice: Get up stranger or else you'll be in danger. ";
    cout << "Get up now!"<< endl;
    system("read -p \"Press enter...\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Ugh. Where am I and what's up with the bright light?" << endl;
    system("read -p \"Press enter...\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Mysterious person: We need to hurry up or else you'll be captured. ";
    cout << "Your our last hope of survival. Hurry up" << endl;
    system("read -p \"Press enter...\" -n 1 -s");
    cout << " " << endl << endl;
  
    cout << "Both you and the mysterious person hide in a near by bush." << endl;
    cout << "Then a horse with a rider on top of it came out of a bush with ";
    cout << "10 guards following it." << endl;
    system("read -p \"Press enter...\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Horse rider: Look around everywhere look under ever rock, bush, ";
    cout << "cave and tree. If you have to burn this entire forest down, but ";
    cout << "find the chosen one." << endl;
    system("read -p \"Press enter...\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You get a closer look at the mysterious person who saved you and ";
    cout << "reminds you of someone you know." << endl;
    system("read -p \"Press enter to continue...\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Hey are you by any chance Dumbuldore because you look a lot like him.";
    system("read -p \"Press enter to continue...\" -n 1 -s");
    cout << " " << endl << endl;
    
    //Get the players name
    cout << "Mysterious person: Who the hell is Dumbuldore, but forget about that. ";
    cout << "I need to know your name to know whether to not to save you.";
    cout << "What is your first name.";
    getline(cin,creation.firstname);
    
    cout << "What is your last name.";
    getline(cin,creation.lastname);
    
    cout << "Mysterious person: So your name is " << creation.firstname << " ";
    cout << creation.lastname << endl;
    
}