/*
Given an array containing N integers , and an number S denoting target sum.
Find two distinct elements that can make a pair up to form target sum. lets asssume there can only be one such pair.

INPUT
array = [10,5,2,3,-6,9,11]
S = 4

OUTPUT
[10,-6]
*/

//Brute force Approach

#include <iostream>
#include <vector>

using namespace std;

vector<int> pairSum(vector<int> arr , int S)
{
    //First traverse through the vector array
    for(int i = 0; i < arr.size(); i++){
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[i] + arr[j] == S){
                cout << arr[i] << "," << arr[j];
            }
        }            
	}
    return {};
}

int main(){

	vector<int> arr{10, 5, 2 , 3, -6, 9 , 11};
	int S = 4;
    
    pairSum(arr,S);

	return 0;
}