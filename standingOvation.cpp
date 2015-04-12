// Google Jam 2015 Qualifications -- Standing Ovation
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{	

	ifstream inFile;
	inFile.open("standingInput.txt"); // open file

	if(inFile.fail()) // error opening file
	{
		cerr << "Error opening file" << endl;
    	exit(1);
	}

	int testCases;
	int maxPeople = 6; // for small dataset
	int maxShyness;
	string audience;
	inFile >> testCases; // readin test cases

	cout << "<<<<<<<<<<<<<<<<<Start>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	while(inFile.good() && testCases > 0)
	{
		cout << "//////////////////////////////////////////" << endl;
		for(int i = 0; i < 2; i++) // reading in arguements
		{	
			string temp;
			inFile >> temp;

			if(i < 1)
			{
				cout << "Max Value: " << temp << endl;
			    maxShyness = stoi(temp); // set max shyness level in audience
			}

			else
			{
				cout << "Audience: " << temp<< endl;
				audience = temp; // convert in to string
			}
		}                                                                                                                                                                       

		int need = 0;
		int standing = 0;

		for(int i = 0; i < audience.length(); i++)
		{	
				cout << i << endl;
				
			if (audience.length() == 1 || standing > maxShyness)
			{
				break; // only one peson in the audience will always stand
			}

			// else if(standing >= i)
			// {
			// 	stringstream ss;
			// 	int adding;
			// 	char num = audience.at(i);
			// 	ss << num;   // char to string
			// 	ss >> adding; // string to int
			// 	cout << "adding this value: " << adding << endl;
			// 	standing += adding;
			// }

			else if(standing < i)
			{
				need = i - standing; // see difference need to make everyone stand
			}

				stringstream ss; // adding people standing up in row
				int adding;
				char num = audience.at(i);
				ss << num;   // char to string
				ss >> adding; // string to int
				cout << "adding this value: " << adding << endl;
				standing += adding;



			cout << "Standing: " << standing << endl;
			cout << "Need: " << need << endl;
		}

		cout << "Minimum Need for" << " TestCase " << testCases << ": " << need << endl;
		testCases--;
	}

	cout << "<<<<<<<<<<<<<<<<<Fin>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;




	return 0;
}