// https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1/

// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends

#include <bits/stdc++.h>
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.length() != str2.length())
            return false;
        
        bool isomorphic = true;
        int mapping[MAX_CHARS];
        int str2_visited[MAX_CHARS];
        
        memset(mapping, 0, sizeof(mapping));
        memset(str2_visited, 0, sizeof(str2_visited));
        
        for(int i=0; i<str1.length(); i++) {
            if(mapping[str1[i]] == 0) {
                if(!str2_visited[str2[i]]) {
                    mapping[str1[i]] = str2[i];
                    str2_visited[str2[i]] = 1;
                }
                else {
                    isomorphic = false;
                    break;
                }
            }
            else if(mapping[str1[i]] != str2[i]) {
                isomorphic = false;
                break;
            }
        }
        
        return isomorphic;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends