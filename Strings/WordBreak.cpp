// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
private:
    bool solveWordBreak(int partitionIdx, string& searchString, unordered_set<string>& wordDict) {
        if(partitionIdx >= searchString.length())
            return true;
            
        for(int currIdx = 1; partitionIdx + currIdx < searchString.length() + 1; currIdx++) {
            string firstPartitionString = searchString.substr(partitionIdx, currIdx);
            
            if(wordDict.find(firstPartitionString) != wordDict.end()) {
                bool solvable = solveWordBreak(partitionIdx + currIdx, searchString, wordDict);
                
                if(solvable)
                    return true;
            }
        }
        
        return false;
    }

public:
    // int wordBreak(string A, vector<string> &B)
    int wordBreak(string searchString, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        
        return solveWordBreak(0, searchString, wordDict);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends