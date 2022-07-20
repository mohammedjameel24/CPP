/*
Given an array of size at least two, find the smallest subarray that needs to be sorted 
*/
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

pair<int,int> findUnsortedSubarray(vector<int> nums) {
    vector<int> A(nums.begin(), nums.end());
    sort(A.begin(), A.end());
    int n = A.size();
    int left , right;
    for(int i = 0; i < n; i++)
        if(A[i] != nums[i]){
            left = i;
            break;
        }
    for(int i = n - 1; i >= 0; i--)
        if(A[i] != nums[i]){
            right = i;
            break;
        }
    return {left,right};
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 8, 6, 5, 7, 9, 10, 11};

    auto p = findUnsortedSubarray(arr); // O(n log n)
    cout<< p.first <<" and "<<p.second <<endl;
}