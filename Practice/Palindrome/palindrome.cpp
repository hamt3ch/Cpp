#include <iostream>
#include <cstring>
using namespace std;

//////functionsUsed////////////
char* validateString(char phrase[], int length);
bool isPalindrome(char phrase[]);
char restartProgram(char decision);
//////////////////////////////

bool usedSymbols = false;
char decision;


int main(void) {
    char runAgain = 'y';
    int length = 80;        //sets length of array
    char phrase[length];       // creates phrase array of length
    
    while(runAgain == 'y' || runAgain == 'Y')
    {

        cout << "This program test if a word/phrase is palindrome\n";  // instructions for program
        cout << "Please enter your phrase(letters and blanks, please)\n";
    
        cin.getline(phrase, 79);   // reads input from user ->>> phrase

        char* newchar = validateString(phrase, 80); // validating the phrase from the user
    
        bool checkPal = isPalindrome(newchar);
    
        if (checkPal)
        {
            cout << "Yes, the phrase is a Palindrome\n";
        }
    
        else
        {
            cout << "No, the phrase isn't a Palindrome\n";
        }
        
        cout << "Would you like to start the program again?\n";
        cin.get(decision);
        char runAgain = restartProgram(decision);
        
        if (runAgain == 'n' || runAgain == 'N') {
            break;
        }
        
        cin.ignore(INT_MAX,'\n');// clear memory before start
        memset(phrase,'\0', length);
    }

}

char* validateString(char message[], int length)
{
    char newchar[79];
    
    for (int i = 0, j = 0; i < strlen(message); i++, j++)
        {
            char letter = tolower(message[i]); // change message into all lowercase
            
            if(!isalpha(letter) && !isspace(letter)) // check if phrase has a symbol
            {
                cout << "you cannot use symbols try again\n"; // Warning
                break;
                
            }
        
            else if (isspace(letter))
            {
                j--; //keep index of newchar
              
            }
        
            else
            {
              newchar[j] = letter;
            }
        }
    return newchar;
}


bool isPalindrome(char phrase[80])
{
    int firstEntry = 0;                         // set index variables and length
    int lastEntry = (int) strlen(phrase)- 1;    //
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

char restartProgram (char decision)
{
   while(decision != 'y' && decision != 'Y' && decision != 'n' && decision != 'N')
   {
       cout << "Invalid entry, Try Again \n";
       cin.get(decision);
   }
    
    if(decision == 'n' || decision == 'N')
    {
       cout << "Ending Program \n";
        
    }
    
    return decision;
    
}




