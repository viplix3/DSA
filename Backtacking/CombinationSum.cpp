// https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
private:
	vector<vector<int>> sumArrays;

private:
	void findSum(vector<int> currSumArray, vector<int>&arr, int currSum, int currArrIdx) {
		int numElems = arr.size();

		if(currSum < 0 || currArrIdx >= numElems)
			return;

		if(currSum == 0) {
			sumArrays.emplace_back(currSumArray);
			return;
		}

		if(currSum >= arr[currArrIdx]) {
			currSumArray.emplace_back(arr[currArrIdx]);
			findSum(currSumArray, arr, currSum - arr[currArrIdx], currArrIdx); // call with curr element and sum reduced

			currSumArray.pop_back();
			findSum(currSumArray, arr, currSum, currArrIdx + 1);
		}

	}

public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &arr, int requiredSum) {
		sort(arr.begin(), arr.end()); // Sort the array

		vector<int> uniqueArr; // Remove all the duplicates from the array
		uniqueArr.push_back(arr[0]);

		for(int currElement : arr)
			if(uniqueArr[uniqueArr.size() - 1] != currElement)
				uniqueArr.emplace_back(currElement);
		
		int arrIdx = 0;
		vector<int> currSumArray;
		findSum(currSumArray, uniqueArr, requiredSum, arrIdx);
		return sumArrays;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends