/*
Given an array containing N integers , and an number S denoting target sum.
Find two distinct elements that can make a pair up to form target sum. lets asssume there can only be one such pair.

INPUT
array = [10,5,2,3,-6,9,11]
S = 4

OUTPUT
[10,-6]
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

//Brute force Approach

vector<int> pairSumBrute(vector<int> arr , int S)
{
    //First traverse through the vector array
    for(int i = 0; i < arr.size(); i++){
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[i] + arr[j] == S){
                cout << arr[i] << "," << arr[j] << endl;
            }
        }            
	}
    return {};
}

//Sorted Array Approach
vector<int> pairSumSort(vector<int> arr , int S)
{
    //sort the array
    sort(arr.begin(),arr.end());
    // traverse through the vector array
    for(int i = 0; i < arr.size(); i++){
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[i] + arr[j] == S){
                cout << arr[i] << "," << arr[j] << endl;
            }
        }            
	}
    return {};
}

// Data structure Approach

vector<int> pairSumDS(vector<int> arr, int S)
{
    unordered_set<int> set;
    vector<int> result;

    for(int i = 0; i < arr.size(); i++)
    {
        int x = S - arr[i];
        if(set.find(x) != set.end())
        {
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
        }
        set.insert(arr[i]);
        
    }
    return {};
}


int main(){

	vector<int> arr{10, 5, 2 , 3, -6, 9 , 11};
	int S = 4;
    
    pairSumBrute(arr,S); // O(N²)
    pairSumSort(arr,S); // O(Nlog N)
    auto p = pairSumDS(arr,S); // O(N)
    if(p.size() == 0)
    {
        cout << "no such pair" << endl;
    }
    else{
        cout<<p[0] << "," <<p[1] << endl;
    }

	return 0;
}