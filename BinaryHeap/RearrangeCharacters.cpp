// https://practice.geeksforgeeks.org/problems/rearrange-characters5322/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to rearrange the characters in a string such that 
    //no two adjacent characters are same.
    string rearrangeString(string str)
    {
        unordered_map<char, int> freqMap;
        priority_queue<pair<int, char>> maxHeap;

		for(int i=0; i<str.length(); i++)
			freqMap[str[i]] += 1;
        
        for(auto ele : freqMap)
            maxHeap.push(make_pair(ele.second, ele.first));
        
        string rearrangedStr = "";
        pair<int, char> prev = make_pair(0, '-');
        
        while(maxHeap.empty() == false) {
            auto curr = maxHeap.top();
            maxHeap.pop();
            
            rearrangedStr += curr.second;
            curr.first -= 1;
            
            if(prev.first)
                maxHeap.push(prev);
            
            prev = curr;
        }
        
        if(prev.first)
            rearrangedStr += prev.second;
        
        return rearrangedStr;
    }
};

// { Driver Code Starts.

int checker(string str, string pat)
{
    int freq[26];
    for(int i=0;i<26;i++)
        freq[i]=0;
    if(str.length()!=pat.length())
        return 0;
    for(int i=0;i<str.length();i++)
    {
        freq[str[i]-97]--;
        if(pat[i]<97 || pat[i]>122)
            return 0;
        freq[pat[i]-97]++;
    }
    for(int i=0;i<26;i++)
        if(freq[i]!=0)
            return 0;
    for(int i=0;i<pat.length()-1;i++)
        if(pat[i]==pat[i+1])
            return 0;
    return 1;
}

int main()
{
	int t;
	cin>>t;
	cin.ignore(INT_MAX, '\n');
	while(t--)
	{
	    string str,ret;
	    cin>>str;
	    Solution ob;
	    ret = ob.rearrangeString(str);
	    cout << checker(str, ret) << endl;
	}
    return 0;
}  // } Driver Code Ends