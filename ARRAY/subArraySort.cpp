/*
Given an array of size at least two, find the smallest subarray that needs to be sorted 
if the input is already sorted return [-1,-1] , otherwise return start & end index of smallest sub array.
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

pair<int,int> subarraysort(vector<int> a)
{
    vector<int> b(a);
    sort(b.begin(), b.end());

    int i = 0;
    int n = a.size();

    while(i<n && a[i]==b[i])
    {
        i++;
    }
    int j = a.size() - 1;
    while(j>=0 && a[j]==b[j])
    {
        j--;
    }
    if(i==a.size())
    {
        return {-1,-1};
    }
    else{
        return {i,j};
    }
}

//------------------------------------Optimal Approach----------------------------------//
bool outOfOrder(vector<int> arr, int i)
{
    int x = arr[i];
    if(i==0)
    {
        return x > arr[1];
    }
    if(i==arr.size()-1)
    {
        return x < arr[i-1];
    }
    return x > arr[i+1] || x < arr[i-1];
}
pair<int,int> subarraysortOptimal(vector<int> arr)
{

    int smallest = INT_MAX;
    int largest = INT_MIN;
    int n = arr.size();

    for(int i=0; i<n;i++)
    {
        int x = arr[i];
        if(outOfOrder(arr,i)){
            smallest = min(smallest,x);
            largest = max(largest,x);
        }
    }
    if(smallest == INT_MAX)
    {
        return {-1,-1};
    }
    int left = 0;
    while(smallest >= arr[left])
    {
        left++;
    }
    int right = n - 1;
    while(largest <= arr[right])
    {
        right--;
    }

    return {left,right};
}


int main()
{
    vector<int> arr{1, 2, 3, 4, 8, 6, 5, 7, 9, 10, 11};

    auto p = findUnsortedSubarray(arr); // O(N log N)
    cout<< p.first <<" and "<<p.second <<endl;

    auto pair = subarraysort(arr); // O(N log N)
    cout << pair.first << " and " << pair.second <<endl;

    auto pairs = subarraysortOptimal(arr); // O(N)
    cout << pairs.first << " and " << pairs.second <<endl;
}