#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    string s;
    int n = 5;

    vector<string> stringArr;
    string temp;
    while(n--)
    {
        getline(cin,temp,'.');
        stringArr.push_back(temp);
    }

    for(string x : stringArr)
    {
        cout << x << "," << endl;
    }

}