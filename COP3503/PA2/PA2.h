//
//  PA2_header.h
//  PA2
//
//  Created by Hugh A. Miles on 10/23/14.d
//  Copyright (c) 2014 HAMtech. All rights reserved.
//

#ifndef PA2_PA2_header_h
#define PA2_PA2_header_h

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Node {

private:
int memAlloc;           //properties of Node

public:
    int index;
    bool free;
    string name;
    Node * nextMemUnit;
    
    Node(int size, int n){      // constructor
        free = true;
        //memAlloc = size;
        nextMemUnit = NULL;
        index = n;
    }
    
    string description()       // returns characters of Node
    {
        if(free)
        {
            return "Free";  // if node is free set name as "Free"
        }
        
        else
        {
            return name;  // if not free return name
        }
    }
};

class linkedList {
    Node* head;  // properties of LinkedList
    
public:
    linkedList()    // constructor
    {
        head = NULL;
    }
    
    Node* getHead() // returns head of linkedList
    {
        return head;
    }

    void create()  // creates set of linkedList
    {
        int memSize = 4;
        Node* newMemUnit;    // instance of program
        
        for (int i = 1; i <= 32; i++)
        {
            if (head == NULL) // start of list
            {
                head = new Node(memSize,i); // new Program = head of linkedList
            }
            
            else // head already created
            {
                newMemUnit = head;
                while(newMemUnit->nextMemUnit != NULL) // check if end of linkedList
                {
                    newMemUnit = newMemUnit->nextMemUnit; // set pointer of nextMemUnit in Node
                }
                
                newMemUnit -> nextMemUnit = new Node(memSize,i); // add node to head
            }
        }
    }
    
    void bestFitAddProgram(int programSize, string programName)
    {
        Node* x;
        x = head;
        
        int unitsNeeded = programSize / 4; // units that need to be filled
        
        if((programSize % 4) != 0)
        {
            unitsNeeded++;  /// if not divisible by 4 add extra unit
        }
        
        while(x != NULL)
        {
            if(x -> free && checkFragment(unitsNeeded, x) && checkIfExist(programName)) // finds first fragement and checks size
            {
                x = findBestFit(unitsNeeded);
                progamAlloc(unitsNeeded,programName, x);
                cout << "Program " << programName << " added successfully: " << unitsNeeded << " page(s) used." << endl; // program was sucessfully added
                break; // stop indexing the linkedList
            }
            
            else if (checkIfExist(programName) == false)
            {
                cout << "Error, "<< programName << " already exist" << endl; // the name of program was already used
                break;
            }
            
            else if (x -> nextMemUnit == NULL)
            {
              cout << "Error, not enough memory for " << programName << endl; // no fit for this program size
              break;
            }
            
            x = x -> nextMemUnit;  // move to next node in list
        }
        
       
    }
    
    Node* findBestFit(int unitsNeeded)
    {
        Node* x = head;     // intialize variables
        Node* bestFitStart;
        int smallest = 32;
        int count = 0;
   
        while (x != NULL)
        {
            if(x -> free) // look for free node
            {
                int temp = sizeOfFragment(x);  // find the size of the fragment
             
                if(temp <= smallest)
                {
                    smallest = temp; // set smallest fragment count
                    bestFitStart = x; // keep fragmentStart
                }
                
                while (x -> free && x -> nextMemUnit != NULL) {
                    x = x -> nextMemUnit; // move to next memUnit
                }
                
                if (x ->nextMemUnit == NULL) {
                    break;  // end of list
                }
                
            }
            
            else
            {
                x = x -> nextMemUnit; // move to next node in list
            }
        }
          return bestFitStart; // return Node with best fit
    }
        
    
    
    void worstFitAddProgram(int programSize, string programName)
    {
        Node * x = head; // intialize linkedList index
        
        int unitsNeeded = programSize / 4; // find unitsNeeded
        
        if((programSize % 4) != 0)
        { 
            unitsNeeded++; // add 1 to unitNeeded
        }
        
        while (x != NULL) {
            
            if( x-> free && checkFragment(unitsNeeded, x) && checkIfExist(programName)) // check if program can fit
            {
               Node* startOfBiggestFragement = findBiggestFragement();
               progamAlloc(unitsNeeded, programName, startOfBiggestFragement);
               cout << "Program " << programName << " added successfully: " << unitsNeeded << " page(s) used." << endl; // program was sucessfully added
               break;
            }
        
            else if (checkIfExist(programName) == false)
            {
                cout << "Error, "<< programName << " already exist" << endl; // the name of program was already used
                break;
            }
        
            else if (x -> nextMemUnit == NULL)
            {
                cout << "Error, not enough memory for " << programName << endl; // no fit for this program size
                break;
            }
            
            x = x -> nextMemUnit;  // move to next node in list
        }
    }


    Node* findBiggestFragement()
    {
        Node* x = head;         // intialize variables
        Node* startLocationOfGreatest;
        int temp = 0;
        int greatest = 0;
        
        while(x != NULL)
        {
            if(x -> free)
            {
              temp =  sizeOfFragment(x); // get size of the fragement
              
              if(temp > greatest)
                {
                    greatest = temp;   //set biggest fragment
                    startLocationOfGreatest = x;
                }
                
                x = x -> nextMemUnit; // move to next Node
            }

            else
            {
                x = x -> nextMemUnit; // find first free node
            }
        }
        
        return startLocationOfGreatest;
    }

    int removeProgram(string programName)
    {
        Node* x = head; // set index pointer (x) to head of linkedList
        int count = 0;
        
        for (int i = 0 ; i < 32; i++)
        {
            if(x -> name == programName)
            {
                count++;
                x -> free = true; // release program
            }
            
            x = x -> nextMemUnit; // move to next Node in linkedList
        }
        
        return count;
        
    }
    

   int fragmentation()
    {   bool flag = true;
        Node* x = head;
        int count = 0;

        while(x != NULL) // index whole linkedList
        {
            if(x -> free == false) // check if free
            {
                flag = true;
                x = x -> nextMemUnit; // catch next false node
            }
            
            if (x -> free && flag == true)
            {
                count++;            // increment fragementCount
                flag = false;
            }
            
            if (flag == false)
            {
                x = x -> nextMemUnit; // move to next Node
            }
        }
       
       return count;
    }
    
    int sizeOfFragment(Node* start)
    {
        Node* x = start -> nextMemUnit;
        int sizeOfFragment = 1;
        
        while(x != NULL && x -> free != false) // index linkedList
        {
            if(x -> free)
            {
                while(x -> free && x -> nextMemUnit != NULL)
                {
                    sizeOfFragment++;
                    x = x -> nextMemUnit; // catch next false node
                }
            }
            
            if (x -> nextMemUnit == NULL) {
                break; // end of list
            }
            
            else
            {
                x = x -> nextMemUnit; // move to next Node
            }
        }
        
        return sizeOfFragment;
    }

    void progamAlloc(int programSize, string name, Node* start)
    {
        int unitsToFill = programSize;
        
        for (int i = 0; i < unitsToFill; i++) // fill units needed
        {
            start -> name = name;   // set name of node
            start -> free = false; // set false
            start = start -> nextMemUnit; // move to next Node
        }
        
    }

    bool checkIfExist(string programName)
    {   Node *x = head;
        
        while (x != NULL) // look programs in memoryMap
        {
            if(x -> name == programName && x -> free == false)
            {
                return false;
            }
            
            x = x -> nextMemUnit; // move to next unit
        }
        
        return true;
        
    }
    
    bool checkFragment(int size, Node* fragmentStart)
    {
        int unitsNeeded = size;  // see the amount of units needed for fragment
        Node* a = fragmentStart;  // a -> to next node in LinkedList
        
        for(int i = 0; i < unitsNeeded; i++)
        {
            if (a == NULL)
            {
                return false; // end of list
            }
            
            else if(a -> free == false)
            {
               return false; // this fragment doesn't have enough space to hold this program
            }

            a = a -> nextMemUnit; // change linkedList pointer index to the next Node in MemoryMap
        }
        
        return true;
        
    }
    
    void display()
    {
        Node* x;    // instance of Node
        x = head;   // set x as index of linkedList
        int count = 0;
        
        while(x != NULL)
        {
            cout << x-> description() << " "; // print memSize of Program
            x = x-> nextMemUnit;     // set program to nextProgam in linkedList
            count++;
            
            if (count == 8) {
                cout << "\n"; // newline after printing 8 nodes
                count = 0;
            }
        }
    }
    
};


#endif
