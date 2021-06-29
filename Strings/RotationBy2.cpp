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
            
        if(str1.length() < 2)
            return str1 == str2;
            
        int strlength = str2.length();
        string anticlockwise_rotated = "", clockwise_rotated = "";
        
        anticlockwise_rotated = anticlockwise_rotated +
                                str2.substr(strlength-2) +
                                str2.substr(0, strlength-2);
        
        clockwise_rotated = clockwise_rotated +
                            str2.substr(2) +
                            str2.substr(0, 2);
        
        return (anticlockwise_rotated == str1 || clockwise_rotated == str1);
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