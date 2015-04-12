//MagicTrick
//https://code.google.com/codejam/contest/2974486/dashboard
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

void newLine(void){cout << endl;}

int main(void)
{
	ifstream inFile;
	inFile.open("magicInput.txt"); // open file

    if(inFile.fail())   // error if file is invalid
    {
    	cerr << "Error opening file" << endl;
    	exit(1);
    }

    int testCases,rowChosen1,rowChosen2, layout[4][4];
    map<int,bool> myMap;
    map<int,bool>::iterator mapIndex;

    inFile >> testCases >> rowChosen1;
    cout << "testCases = " <<  testCases << endl; // set for amount of test cases
    cout << "rowChosen1 = " <<  rowChosen1 << endl; // rowChoice1

    //create card layout in layout[][]
    for (int i = 0; i < 4; i++)
    {
    	for(int j = 0; j < 4; j++)
    	{
    		inFile >> layout[i][j];
    	//	cout << layout[i][0] << " ";
    	}
    	//cout << endl;
    }

    //fill hashMap with keyValues
    int select1[4];
    cout << "row1 selected: ";
    for(int i = 0; i < 4; i++)
    {
    	int keyValue = layout[rowChosen1-1][i];
    	cout << "Putting into MAP : " << keyValue;
    	myMap.insert(myMap.begin(),pair<int,bool>(keyValue,true));
    	newLine();
    }
   
    cout << endl;  //debugging

    inFile >> rowChosen2; // get next row selected

    int toCheckInMap, likeEle,answer;  // create variables
    
    for(int i = 0; i < 4; i++)
    {
    	inFile >> toCheckInMap; // read in

    	cout << "Checking into MAP :" << toCheckInMap;

    	if (myMap.find(toCheckInMap)->second); // element exist
    	{
    		likeEle++; // count the instances of like elements
    		answer = toCheckInMap; // save value found
    	}

       newLine();
    }

    newLine();

    if(likeEle > 1)
    {
    	cout << "Bad Magician";  // all elements match
    }

    else if(likeEle == 0)
    {
    	cout << "Player Cheated"; //none match
    }

	else
	{
		cout << answer; // print answer
	}

}