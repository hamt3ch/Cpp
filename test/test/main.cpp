#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


int main (void)
{
    ifstream inFile;
    inFile.open("A-small-practice.txt");

    if(inFile.fail())
    {
    	cerr << "Error opening file" << endl;
    	exit(1);
    }

   // int x, y;

  //  inFile >> x >> y;

  //  cout << "Num1: " << x << endl;

  //  cout << "Num2: " << y << endl;

/*    int data;
    inFile >> data;
    while(inFile.good())
    {
    	cout << data << " ";
    	inFile >> data; 
    }
*/
    int table[4]; //[4][4];
    int tests, ans;

    inFile >> tests >> ans;

    for(int i = 0; i < 4; i++) //readline of inputsArg
    {
    	 inFile >> table[i];
    	 cout << table[i] << " " ;
    }

    cout << "Test Cases:" << tests << endl;

    cout << "Answers:" << ans << endl;


   /* for(int i = 0; i < 4; i++)
    { for(int j = 0; j < 4 ; i++)
    	{
    		inFile >> table[i][j];
    		cout << table[i][j];
    	}
    } */
}





