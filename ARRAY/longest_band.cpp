/*
Given an array containing N integers , find the length of longest band.

A band is defined as the seqence of numbers of absolute difference +-1.
longest band is band with maximum of these elemnets 

Input 
[1,9,3,0,18,5,2,4,10,7,12,6]
Output
[1,2,3,4,5,6,7]
*/

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int longest_band_sort(vector<int> arr)
{
    int count = 0;
    int n = arr.size();
    sort(arr.begin(),arr.end());
    // sorted arr{0,1,2,3,4,5,6,7,9,10,12,18}

    for(int i = 0 ; i <=n; i++)
    {
        if(arr[i+1] - arr[i] == 1)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<int> arr{1,9,3,0,18,5,2,4,10,7,12,6};

    cout << longest_band_sort(arr) << endl; //O(N log)
    
}