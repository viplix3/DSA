// https://www.geeksforgeeks.org/problems/data-type-1666706751/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=data-type

//{ Driver Code Starts
// Initial Template for C++

// {Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends


// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    Solution()
    {
        dtype_sizemap["Character"] = static_cast<size_t>(1);
        dtype_sizemap["Integer"] = static_cast<size_t>(4);
        dtype_sizemap["Long"] = static_cast<size_t>(8);
        dtype_sizemap["Float"] = static_cast<size_t>(4);
        dtype_sizemap["Double"] = static_cast<size_t>(8);
    }

public:
    int dataTypeSize(string str)
    {
        if (dtype_sizemap.find(str) != dtype_sizemap.end())
            return dtype_sizemap[str];
        else
            return -1;
    }

private:
    std::unordered_map<std::string, size_t> dtype_sizemap;
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.dataTypeSize(str);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends