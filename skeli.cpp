//skeliNotes
                                     //compile g++ -o [runname] [filename].cpp
                                                // ./[runme]
void readFromFile (void) 
{    
    ifstream inFile;  // instantiate file object
    inFile.open("A-small-practice.txt");    // open file

    if(inFile.fail())   // error if file is invalid
    {
    	cerr << "Error opening file" << endl;
    	exit(1);
    }

    int x, y; // read indivdual numbers

    inFile >> x >> y; // read from file 2 separate files
                        // input.txt
                        //  4
                        //  5
                        //     -- x = 4,  y = 5

    cout << "Num1: " << x << endl;  // print out both outputs
    cout << "Num2: " << y << endl; 


    int data;       // reading multiple values
    inFile >> data;
    while(inFile.good()) // reading the whole til ending
    {
    	cout << data << " "; // prints all chars with a space between 
    	inFile >> data;       // read in a line at a time
    }

    for(int i = 0; i < 4; i++) //readline of inputsArg
    {
         inFile >> table[i];
         cout << table[i] << " " ; // place each element on the line into array 
    }                               // input.txt
                                    // 12 3 5 6 
                                    //
                                    //       -- table[4] = {12,10,11,3}

}