/*
Given an array containing N integers, and an number S denoting a target sum
Find all distinct pairs that can add up to form target sum if no pairs are possible return -1 
the output should be sorted 
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute force Approach 
vector<vector<int>> tripletsBrute(vector<int> arr, int Sum )
{
    vector<vector<int>> result;

    for(int i = 0; i < arr.size();)
    {
        for(int j = i+1; i < arr.size();)
        {
            for(int k = j+1; i < arr.size();)
            {
                if(arr[i]+arr[j]+arr[k] == Sum)
                {
                    result.push_back({arr[i],arr[j],arr[k]});
                }
                else{
                    cout << "no such pair";
                }
                
            }
        }
    }
    return result;
}

vector<vector<int> > triplets2Pointer(vector<int> arr,int targetSum){
	//Logic 
	int n = arr.size();
	sort(arr.begin(),arr.end());
	vector<vector<int> > result;

	// Pick every a[i], pair sum for remaining part
	for(int i=0; i<=n-3;i++){

		int j = i + 1;
		int k = n - 1;

		//two pointer approach
		while(j < k){
			int current_sum = arr[i];
			current_sum += arr[j];
			current_sum += arr[k];

			if(current_sum==targetSum){
				result.push_back({arr[i],arr[j],arr[k]});
				j++;
				k--;
			}
			else if(current_sum > targetSum){
				k--;
			}
			else{
				j++;
			}
		}

	}
	return result;

}

int main()
{
    vector<int> arr{-1,0,1,2,-1,-4};
    int Sum = 0; 

    //auto result = tripletsBrute(arr, Sum); // 0(N³)
    auto result = triplets2Pointer(arr, Sum); // 0(N)

	for(auto v : result){
		for(auto no : v){
			cout<<no<<",";
		}
		cout<< endl;
	}


	return 0;



}