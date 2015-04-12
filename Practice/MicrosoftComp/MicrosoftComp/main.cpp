//
//  main.cpp
//  MicrosoftComp
//
//  Created by Hugh A. Miles on 2/5/15.
//  Copyright (c) 2015 HAMtech. All rights reserved.
//

#include <CSTRING>
#include <iostream>
#include <sstream>

using namespace std;

bool isPalindrome(char phrase[]);

int main(int argc, const char * argv[]) {
    string input = ".djfalkf;";
    stringstream temp;
        transform(input.begin(), input.end() , input.begin(), ::tolower);
   do
   {
       
   }while (input.at(i) != NULL);
    
    
    for (int i = 0; i < input.length(); i++)
    {
        if(isalnum(input.at(i)))
        {
            temp << input.at(i);  // put into buffer
            
        }
        
        else if(input.at(i) == ' ')
        {
            continue; // skip spaces
        }
        
        else
        {
            break; // take substring
        }
    }

    char phrase[80];
    strcpy(phrase, temp.str().c_str());
    
    bool pal = isPalindrome(phrase);
    
    cout << pal << endl;
    
    cout << temp.str();

}

bool isPalindrome(char phrase[80])
    {
        int firstEntry = 0;                         // set index variables and length
        int lastEntry = (int) strlen(phrase) - 1;    //
        int length = (int) (strlen(phrase)) / 2;    //
        
        for (firstEntry, lastEntry; firstEntry <= length; firstEntry++,lastEntry--)
        {
            if (phrase[firstEntry] != phrase[lastEntry]) // check if Palindrome condtion is met
            {
                return false;
            }
            
            else
            {
                continue;
            }
        }
        
        return true;
    }
