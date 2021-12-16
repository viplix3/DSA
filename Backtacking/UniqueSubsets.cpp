// https://practice.geeksforgeeks.org/tracks/DSASP-Backtracking/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
private:
	vector<vector<int>> subSets;
	set<vector<int>> uniqueSubsets;

private:
	void generateSubsets(vector<int>& arr, vector<int> currSubset, int currIdx) {
		if(currIdx == arr.size()) {
			if(uniqueSubsets.find(currSubset) == uniqueSubsets.end()) {
				uniqueSubsets.insert(currSubset);
			}
			return;
		}

		currSubset.emplace_back(arr[currIdx]);
		generateSubsets(arr, currSubset, currIdx+1); // Add a new element and move to next

		currSubset.pop_back();
		generateSubsets(arr, currSubset, currIdx+1); // Don't add a new element and move to next
	}

public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
		vector<int> currSubset;
		sort(arr.begin(), arr.end());
		generateSubsets(arr, currSubset, 0);

		for(vector<int> subset : uniqueSubsets)
			subSets.emplace_back(subset);

		return subSets;
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
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
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
}   


  // } Driver Code Ends