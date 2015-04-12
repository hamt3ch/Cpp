
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


////http://www.spoj.com/problems/ELIS/

using namespace std;

int main (void)
{
    int inputLength;
    
    cin >> inputLength;
    
    int inputArray[inputLength];
    
    for (int i = 0; i < inputLength; ++i)
    {
        cin >> inputArray[i];  // fill up input Array
    }
    
    int greatest = 0;
    
    for(int a = 0; a < inputLength; a++)
    {
        int ascendingCount = 0; // reset count
        int j = a + 1; // next element
        
        while(inputArray[a] < inputArray[j])
        {
            ascendingCount++; //inc count
            a++; // move to nextElement
            j = a + 1; // j = nextElement
        }
        
        greatest = ascendingCount;	//break ascending
        a = j; // move index to
    }
    
    cout << greatest;	
}



