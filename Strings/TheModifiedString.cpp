//https://practice.geeksforgeeks.org/problems/the-modified-string-1587115621/1/

// { Driver Code Starts
#include<bits/stdc++.h>
#define br char xx; cin>>xx; cout<<xx<<endl;
#define lli long long int
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find minimum number of characters which Ishaan must insert  
    //such that string doesn't have three consecutive same characters.
    int modified (string str)
    {
        int numInsertions = 0;
		int currConsecutives = 0;

		for(int i=1; i<str.length(); i++) {
			if(str[i] == str[i-1])
				currConsecutives += 1;
			else
				currConsecutives = 0;

			if(currConsecutives == 2) {
				numInsertions += 1;
				currConsecutives = 0;
			}
		}
		return numInsertions;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    string a;
    while(t--){
        cin>>a;
        Solution obj;
        cout<<obj.modified(a)<<endl;
    }
    return 0;
}
  // } Driver Code Ends