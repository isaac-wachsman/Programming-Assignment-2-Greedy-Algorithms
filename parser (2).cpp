#include <fstream>
#include <iostream>
#include <sstream>
#include "parser.h"

using namespace std;


int getCacheSize(string fileName)
{
    string s;
    ifstream Input(fileName);

    getline(Input, s);

    return stoi(s.substr(0, s.find(' ')));
}


vector<int> getCacheRequests(string fileName)
{
    vector<int> requests;

    string s;
    ifstream Input(fileName);

    getline(Input, s);

    int n = stoi(s.substr(s.find(' '), s.length()));

    getline(Input, s);

    istringstream iss(s);
    for(int i = 0; i < n; i++)
    {
        int x;
        iss >> x;
        requests.push_back(x);
    }

    return requests;
}