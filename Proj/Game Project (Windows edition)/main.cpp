/* 
 * File:   main.cpp
 * Author: Hamza Khan
 *
 * Created on October 13, 2014, 7:16 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>


using namespace std;

//Declare structure
struct charactercreator
{
    string firstname;
    string lastname;
};

struct inventory
{
    string weapon;
    string potions;
    string armor;
};

struct weaponselection
{
    int attack;
    int defence;
    int speed;
};

//Declare function prototypes
float starterguard weaponchoice(weaponselection, *);
void display(int, int);
int death(int , int);
weaponselection weaponchoice(weaponselection);

int main()
{
    //Character profile in a structure
    charactercreator creation;
    weaponselection weapon;
    
    //Declare local variables
    string firstname;
    string lastname;
    int choice;
    int baseHP = 30;
    int maxHP = 120;
    weapon.attack = 0;
    weapon.defence = 0;
    weapon.speed = 0;
    
    //Set up the back story to the adventure
    cout << "There was a legend a told by the native Americans saying that ";
    cout << "every time you go to sleep at night your soul travels to ";
    cout << "different worlds and that in the mornings it travels back to your ";
    cout << "body, but if it doesn't get back to your body in time it is trapped ";
    cout << "in that world until nightfall. Until your soul doesn't get back to ";
    cout << "your body you are left in a coma and after three days you and your ";
    cout << "soul start to die." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Night guys I'm gonna go to sleep." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    //Opening scene
    cout << "Tap. . . Tap. . . Tap" << endl;
    cout << "Mysterious voice: Get up stranger or else you'll be in danger. ";
    cout << "Get up now!"<< endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Ugh. Where am I and what's up with the bright light?" << endl;
   system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Mysterious person: We need to hurry up or else you'll be captured. ";
    cout << "Your our last hope of survival. Hurry up" << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
  
    cout << "Both you and the mysterious person hide in a near by bush." << endl;
    cout << "Then a horse with a rider on top of it came out of a bush with ";
    cout << "10 guards following it." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Horse rider: Look around everywhere look under ever rock, bush, ";
    cout << "cave and tree. If you have to burn this entire forest down, but ";
    cout << "find the chosen one." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You get a closer look at the mysterious person who saved you and ";
    cout << "reminds you of someone you know." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Hey are you by any chance Dumbuldore because you look a lot like him.";
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    //Get the players name
    cout << "Mysterious person: Who the hell is Dumbuldore, but forget about that. ";
    cout << "I need to know your name to know whether to not to save you.";
    cout << "What is your first name: ";
    getline(cin,creation.firstname);
    
    cout << "What is your last name: ";
    getline(cin,creation.lastname);
    
    cout << "Mysterious person: So your name is " << creation.firstname << " ";
    cout << creation.lastname << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Mysterious person: You are the one the prophecy talked about follow ";
    cout << "me." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Guard: Looks like I just hit the jackpot capturing both the chosen ";
    cout << "one and the rogue wizard Nucktuck" << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Nucktuck: Well " << creation.firstname << " I must take your leave. ";
    cout << "I leave you with a sword and a stick. Good Luck and find me if you ";
    cout << "live. Every man for himself!" << endl;
   system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    //Goes to the menu to select a weapon
    weaponchoice(weapon);
    
    cout << "Your weapon of choice is now in your inventory." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl;
    
    //Guard taunt
    cout << "Guard: So you can beat me with that weapon. I laugh at that ";
    cout << "chosen one. Let's fight." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl; 
    
    //Go to the enemy attack menu
    starterguard(weapon *baseHP)
 
}


 weaponselection weaponchoice(weaponselection weapon)
{
    //Declare local variable
    int choice;
    
    //Starter weapons
    cout << "Please choose a weapon of your liking" << endl;
    cout << "1. Basic Sword" << endl;
    cout << "Attack: 3" << endl;
    cout << "Defense: 5" << endl << endl;
    
    cout << "2. Basic Stick" << endl;
    cout << "Attack: 8" << endl;
    cout << "Defense: 3" << endl << endl;
    
    cin >> choice;
    
    do
    {
        switch(choice)
        {
            case 1: 
                cout << "You have chosen the noble and defensive sword. Good luck.";
                cout << endl;
                break;
                
            case 2:
                cout << "You have chosen the strong and mighty stick. Good luck."; 
                cout << endl;
                break;
                
            default:
                cout << "That is in invalid choice please chose either enter 1 or 2";
                break;
        }
    }
    while (choice < 1 || choice > 3);
    
    if (choice == 1)
    {
        weapon.attack = 3;
        weapon.defence = 5;
    }
    
    else if (choice == 2)
    {
        weapon.attack = 8;
        weapon.defence = 3;        
    }
    
    return weapon;
}

 float starterguard(weaponselection *)
 {
     //Declare local variables
     float guardHP;
     float guardAttk;
     
     //Get the guard Attack
     
     
     
 }
 
