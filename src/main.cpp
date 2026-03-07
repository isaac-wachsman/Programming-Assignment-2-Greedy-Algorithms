#include <iostream>
#include <string>
#include <vector>
#include "parser.h"
#include "driver.h"

using namespace std;


int main()
{
    cout << "Please enter the file you would like to read from: " << endl;

    string fileName;
    cin >> fileName;

    int capacity = getCacheSize(fileName);

    vector<int> requests = getCacheRequests(fileName);
    

    cout << "FIFO: " << fifo(capacity, requests) << endl;
    cout << "LRU: " << lru(capacity, requests) << endl;
    cout << "OPTFF: " << optff(capacity, requests) << endl;

}