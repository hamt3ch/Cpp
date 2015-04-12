class DynamicStringArray
{
	private:
		int size;
		string *a;

	DynamicStringArray() // constructor
	{
		size = 0;
		string a[size] = { NULL };
		
	}	

	int getSize()
	{
		return size;
	}

	void addEntry(string toAdd)
	{
		int increment = size + 1;  // make new array of size++;
		string incArray[increment];

		if(a[size] == NULL) // first entry ino the array
		{	
			size++; // increase size
		}

		else
		{ 	
			for(int i = 0; i < a.length(); i++)
			{
				incArray[i] = a[i];  // old >> new
			}

			incArray[incArray.length()]	= toAdd; // add new	entry at the end of the array
		}

		string a[increment] = incArray[increment];

	}

	void deleteEntry(string toRemove)
	{

	}

	string getEntry(int index)
	{

	}


};