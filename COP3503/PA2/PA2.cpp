
#include "PA2.h"        // import files
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits>

/////stateMethods////////////////////
int parseUser();
void addProgram(linkedList* memoryMap);
void killProgram(linkedList* memoryMap);
void getFragments(linkedList* memoryMap);
void displayMenu();
/////////////////////////////////////

char input; // global variables

int main (void)
{
    linkedList* memoryMap = new linkedList(); // instantiate linkedList
    memoryMap->create();                // create memory map (add Node)
    
    displayMenu(); // print menu to screen
    
    do {
        input = parseUser(); // make sure user is inputting number
        
        switch (input) {
            case 1:
                addProgram(memoryMap); // add program in MM
                break;
            case 2:
                killProgram(memoryMap); // kill progam in MM
                break;
            case 3:
                getFragments(memoryMap); // get fragements in MM
                break;
            case 4:
                memoryMap -> display();  // display MM
                break;
        }

        while (input != 1 && input != 2 && input != 3 && input != 4 && input != 5) {
            input = parseUser(); // make sure user is inputting numbers
        }
        
    } while (input == 1 || input == 2 || input == 3 || input == 4); // if input = 5 -> exit Program
     
}

void displayMenu()
{
    cout << "1. Add Program" << endl;   // create mainMenu
    cout << "2. Kill Program" << endl;
    cout << "3. Fragmentation" << endl;
    cout << "4. Print Memory" << endl;
    cout << "5. Exit" << endl;
}
    
void addProgram(linkedList* memoryMap)
{
    string nameOfProgram; // intialize variables
    int sizeOfProgram;
    char whatFit;
    
    cout << "Program name?" << endl;
    cin >>  nameOfProgram;  // enter string name of program
    
    string upperNameOfProgram = nameOfProgram;     // change everything to upper case
    transform(upperNameOfProgram.begin(), upperNameOfProgram.end(),
              upperNameOfProgram.begin(), ::toupper);
    
    cout << "Size of Program (KB):" << endl; //
    sizeOfProgram = parseUser();  // parse users input
  
    cout << "Enter 1 for Best fit or 0 Worst fit:" << endl;
    cin >> whatFit;

    while (whatFit != '1' && whatFit != '0') {
        cin >> whatFit;
    }
     
    int decision = atoi(&whatFit); // change to integer
    
    if(decision == 1)
        {
            memoryMap -> bestFitAddProgram(sizeOfProgram,upperNameOfProgram); // use bestFit Algorithm
        }   
   
    else 
      {
        memoryMap -> worstFitAddProgram(sizeOfProgram,upperNameOfProgram); // use worstFit Alogorithm
      }
    
}

void killProgram(linkedList* memoryMap)
{
    string name;    //get name of program user wants to kill
    cout << "Whats the name of the program you want to kill?" << endl;
    cin >> name;
    
    string upperNameOfProgram = name;             // change everything to upper case
    transform(upperNameOfProgram.begin(), upperNameOfProgram.end(),
                   upperNameOfProgram.begin(), ::toupper);
    
    int removed = memoryMap ->removeProgram(upperNameOfProgram); // call remove function
    cout << "Program " << upperNameOfProgram << " successfully killed" << endl;
}

void getFragments(linkedList* memoryMap)
{
     int fragments = memoryMap -> fragmentation();  // get number of fragments from MM
     cout << "Number of Fragements: " << fragments << endl;  // print value

}

int parseUser()
{
    int input = 0;
    while(!(cin >> input))
    {
        cin.clear();    // make sure input is a valid number
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Try again: ";
        cout << endl;
    }
    
    return input;  // return parsedInput
}