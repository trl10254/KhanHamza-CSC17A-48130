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

//Declare structures
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
    int defense;
};

//Declare function prototypes
void weaponchoice(weaponselection *);
void guard (weaponselection *, int);
void display(int, int);
int villianXP(int);
int heroXP(int);
int guarddeath(int, int &);
int playerdeathbyguard(int, int &);

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
    weaponchoice(&weapon);
    
    cout << "Your weapon of choice is now in your inventory.";
    cout << "(Inventory is still being made)" << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    //Guard taunt
    cout << "Guard: So you can beat me with that weapon. I laugh at that ";
    cout << "chosen one. Let's fight." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl; 
    
    //Goes to the attack menu
    guard(&weapon, baseHP);
    
    cout << baseHP;
 
}


 void weaponchoice(weaponselection *w)
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
        w -> attack = 3;
        w -> defense = 5;
    }
    
    else if (choice == 2)
    {
        w -> attack = 8;
        w -> defense = 3;        
    }
    
}

 void guard (weaponselection *w, int baseHP)
 {
     //Declare local variables
     int guardAttk;
     int guardHP = 15;
     int choice;
     
     while(baseHP > 0 && guardHP > 0)
     {
         //Get the attack points of the guard
         guardAttk = (rand()%2)+1;
         
         cout << "What do you want to do" << endl;
         cout << "1. Attack" << endl;
         cout << "2. Defense" << endl;
         cout << "3. Do nothing" << endl;
         cin >> choice;
         
         do
         {
             switch(choice)
             {
                 case 1:
                     cout << "You choose to attack the guard" << endl;
                     break;
                     
                 case 2:
                     cout << "You choose to shield yourself" << endl;
                     break;
                     
                 case 3:
                     cout << "You choose to do nothing" << endl;
                     break;
                     
                 default:
                     cout << "That is in invalid choice please chose either enter 1 or 2";
                     break;
                
             }
         }
         while(choice < 1 || choice > 4);
         
         if (choice == 1)
         {
             //Display damage done and life left on the guard
             guardHP = guardHP - (w -> attack);
             cout << "You did " << w -> attack << " damage on the guard." << endl;
             cout << "The guard has " << guardHP << " HP left." << endl;
         
             //Display your life left after guard attacks
             baseHP = baseHP - guardAttk;
             cout << "You have " << baseHP << " HP left." << endl;
             system("read -p \"Press enter to continue\" -n 1 -s");
             cout << " " << endl << endl;
         }
         
         else if (choice == 2)
         {
             baseHP = (w -> defense) - guardAttk;
             cout << "You have " << baseHP << " HP left." << endl;
             system("read -p \"Press enter to continue\" -n 1 -s");
             cout << " " << endl << endl;
         }
         
         else if (choice == 3)
         {
             baseHP = baseHP - guardAttk;
             cout << "You have " << baseHP << " HP left." << endl;
             system("read -p \"Press enter to continue\" -n 1 -s");
             cout << " " << endl << endl;
         }
         
         guarddeath(guardHP, baseHP);
         playerdeathbyguard(guardHP, baseHP);
     }
 }
 
 int playerdeathbyguard(int guardHP, int &baseHP)
 {
     if (guardHP > 0 && baseHP <= 0)
     {
         cout << "Guard: So you thought you could beat me huh. ";
         cout << "You couldn't even destroy me. HaHaHa" << endl;
         cout << "Game Over" << endl;
     }
     
     return 0;
 }
 
 int guarddeath(int guardHP, int &baseHP) 
 {
     //Declare local variables
     int choice;
     int antagonist;
     int protagonist;
     
     if (guardHP <= 0 && baseHP > 0)
     {
         cout << "The guard has fallen" << endl;
         
         cout << "You have two options you can choose from" << endl;
         cout << "1. You can kill the guard" << endl;
         cout << "2. Or you can let the guard live" << endl;
         cout << "Please make a selection";
         cin >> choice;
         
         do
         {
             switch (choice)
             {
                 case 1:
                     cout << "You have decided to kill the guard." << " ";
                     cout << "This may effect you later on." << endl;
                     break;
                 
                 case 2:
                     cout << "You have decided to let the guard live." << " ";
                     cout << "This may effect you later on." << endl;
                     break;
                 
                 default:
                     cout << "That is in invalid choice please chose either enter 1 or 2";
                     break;    
             }
         }
         
         while (choice < 1 || choice > 3);
             
             if (choice == 1)
             {
                 villianXP(antagonist);
             }
             
             else if (choice == 2)
             {
                 heroXP(protagonist);
             }
     }
     
     return (antagonist, protagonist);
 }
 
 void villianXP(int antagonist)
 {
     //Declare local variables
     const int SIZE = 10;
     int *antagonist = new int [SIZE]; 
 }
 
 int heroXP(int protagonist)
 {
     
 }
 
