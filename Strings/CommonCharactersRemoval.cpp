// https://practice.geeksforgeeks.org/problems/remove-common-characters-and-concatenate-1587115621/1/

// C++ program Find concatenated string with 
// uncommon characters of given strings 
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


constexpr int CHARS = 256;

class Solution
{
    public:
    //Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2) 
    {
        string uncommon = "";
        int char_freq[CHARS] = {0};
        
        // for(int i=0; i<s1.length(); i++)
        //     char_freq[s1[i]] += 1;
        
        for(int i=0; i<s2.length(); i++)
            char_freq[s2[i]] += 1;
        
        for(int i=0; i<s1.length(); i++) {
            if(char_freq[s1[i]] != 0)
                char_freq[s1[i]] = -1;
            else
                uncommon += s1[i];
        }
    
        for(int i=0; i<s2.length(); i++) {
            if(char_freq[s2[i]] < 0)
                continue;
            else
                uncommon += s2[i];
        }
        
        if(uncommon.length() == 0)
            return "-1";
        
        return uncommon;
    }

};

// { Driver Code Starts.

/* Driver program to test above function */
int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	Solution obj;
    	string res = obj.concatenatedString(s1, s2);
    	cout<<res<<endl;
	}
	return 0; 
}
  // } Driver Code Ends