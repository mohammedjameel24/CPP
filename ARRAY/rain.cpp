/*
Given n non-negative integers represnting an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
3   |                ___
2   |       ___      | |__  ___
1   |  ___  | |__  __| | |__| |___
0   |__|_|__|_|_|__|_|_|_|_|__|__|__
      0  1 0 2 1  0 1 3 2 1  2  1

left  0  1 1 2 2  2 2 3 3 3  3  3
right 3  3 3 3 3  3 3 3 2 2  2  1

formula min(left,right) - height

water = 0+0+1+0+1+2+1+0+0+1+0+0 = 6
*/
#include <bits/stdc++.h>
using namespace std;

int trappedWater(vector<int> height)
{
    int n = height.size();
    // if water cannot be trapped 
    if(n<=2)
    {
        return 0;
    }

    vector<int> left(n,0) ; //left array
    vector<int> right(n,0) ; //right array

    left[0] = height[0]; // value of left 0 initiliazed to value of height 0 (filled left to right)
    right[n-1] = height[n-1]; // value of right n-1 initialized to hegitht n-1 (filled right to left)

    for(int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1],height[i]);// left array is being filled with the largest value so far found (filled left to right)
        right[n-i-1] = max(right[n-i],height[n-i-1]);// right array is being filled with largest value so far found (filled right to left)
    }

    int water = 0;
    for(int i = 0; i < n; i++){
        water += min(left[i],right[i]) - height[i]; 
    }
    return water;

}
int main()
{
    vector<int> heights{0,1,0,2,1,0,1,3,2,1,2,1};

    cout << trappedWater(heights) <<endl; //O(N²)

}