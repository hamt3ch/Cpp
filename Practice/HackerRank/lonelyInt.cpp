/*
 
 Lonely Integer
 
 There are N integers in an array A. All but one integer occur in pairs. Your task is to find out the number that occurs only once.
 
 Input Format
 
 The first line of the input contains an integer N indicating the number of integers.
 The next line contains N space separated integers that form the array A.
 
 Constraints
 
 1 <= N < 100
 N % 2 = 1 ( N is an odd number )
 0 <= A[i] <= 100, ∀ i ∈ [1, N]
 
 Output Format
 
 Output S, the number that occurs only once.
 
*/

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

////stateMethods///////////////
int lonelyinteger(vector<int> a);
////////////////////////////////

int main() {
    
    int res;        // intialize variable
    int _a_size;
    int _a_item;
    
    cin >> _a_size; // read user input for size of vector
    
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _a; // Vector a = new Vector();
    
    for(int _a_i=0; _a_i<_a_size; _a_i++) { // fill vector with user inputs
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger(_a);     //find dis
    cout << res;
    
    return 0;
}

int lonelyinteger(vector<int> a) {
    // create hashMap
    map<int, int> myMap;
    map<int, int>::iterator mapIndex;
    
    // fill hashMap w/ keys
    for(int i = 0; i < a.size(); i++) {
        
        int keyValue = a.at(i);
        
        if (myMap.find(keyValue) != myMap.end()) {
            int oldCount = myMap.find(keyValue)->second;    // save old countValue
            myMap.erase(keyValue);  //erase old key
            myMap.insert(myMap.begin(),pair<int,int>(keyValue,++oldCount)); // save new key w/ count++
        }
        
        else
        {
            myMap.insert(myMap.begin(),pair<int,int>(keyValue,1)); // fill map with key w/ value = 1
        }
        
    }
    
    for(mapIndex = myMap.begin(); mapIndex != myMap.end(); mapIndex++) {
        
    //    int test = mapIndex->second;
    //    cout << "elements in the map" << endl;
    //    cout << mapIndex->first << "," << mapIndex->second << endl;
        
        if (mapIndex->second == 1)
        {
            return mapIndex->first; // return lonely int
        }
        
    }
    
    return 0;
}