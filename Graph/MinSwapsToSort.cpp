// https://practice.geeksforgeeks.org/problems/minimum-swaps/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
	public:
	//Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
		vector<pair<int, int>> sortedArrWithPos;
		
		for(int i=0; i<nums.size(); i++)
			sortedArrWithPos.emplace_back(make_pair(nums[i], i));

		sort(sortedArrWithPos.begin(), sortedArrWithPos.end());

		int numSwaps = 0;

		for(int i=0; i<sortedArrWithPos.size(); i++) {
			if(sortedArrWithPos[i].second != i) {
				swap(sortedArrWithPos[i], sortedArrWithPos[sortedArrWithPos[i].second]);
				numSwaps += 1;
			}

			if (sortedArrWithPos[i].second != i)
				i--;
		}

		return numSwaps;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends