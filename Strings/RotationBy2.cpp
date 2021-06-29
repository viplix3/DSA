// https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if(str1.length() != str2.length())
            return false;
            
        if(str1.length() == 1)
            return str1 == str2;
            
        string search_space = str1 + str1;
        auto search_idx = search_space.find(str2);
        
        if(search_idx == string::npos)
            return false;
        
        if(search_idx == 2 || search_idx == str1.length()-2)
            return true;
        return false;
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends