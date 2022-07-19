/*
write a function that takes input an array of distinct integers, return the length of highest mountain.
• A mountain is definded as adjacent integers that are strictly incresing untill they reach a peak
at which it becomes strictly decreasing
• At least 3 numbers are required to form a mountain.

Sample Input
[5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4]
Sample Output
9
*/
#include <vector>
#include <iostream>
 
using namespace std;

int highest_mountain(vector<int> arr)
{
    int n = arr.size();
    int largest = 0;
    //i cannot be 0 because first index cannot be a peak at all times & i should be <=n -2 because last element cannot be a peak  
    for(int i=1; i<=n-2;) 
    {
        // an element is a peak if its preceding value and succeding value is lesser then th i value
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
        {
            // count the length of peak
            int count = 1;
            int j = i;
            // count the elemnts that are lesser & greater than the current value of i
            while(j>=1 && arr[j]>arr[j-1])
            {
                //count backward
                j--;
                count++;
            }
            while(i<=n-2 && arr[i] > arr[i+1])
            {
                //count forward
                i++;
                count++;
            }
            largest = max(largest,count);
        }
        else{
            i++;
        }
    }
    return largest;
}

int main(){

    vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

    cout << highest_mountain(arr) << endl; // O(N);

    return 0;

}