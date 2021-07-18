// https://practice.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
		string lowerCase = "", upperCase = "";

		for(int i=0; i<str.length(); i++) {
			if(islower(str[i]))
				lowerCase += str[i];
			else
				upperCase += str[i];
		}

		sort(lowerCase.begin(), lowerCase.end());
		sort(upperCase.begin(), upperCase.end());

		int lowerItr = 0, upperItr = 0;
		for(int i=0; i<str.length(); i++) {
			if(islower(str[i])) {
				str[i] = lowerCase[lowerItr];
				lowerItr += 1;
			}
			else {
				str[i] = upperCase[upperItr];
				upperItr += 1;
			}
		}
		return str;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}  // } Driver Code Ends