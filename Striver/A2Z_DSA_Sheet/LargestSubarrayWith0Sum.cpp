// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this function*/

class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        unordered_map<int, int> prefix_sum_map;// prefix_sum, occurrence_idx

        int curr_sum = 0, max_len = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            curr_sum += arr[i];

            if (curr_sum == 0)
                max_len = max(i + 1, max_len);

            if (prefix_sum_map.find(curr_sum) != prefix_sum_map.end())
                max_len = max(i - prefix_sum_map[curr_sum], max_len);
            else
                prefix_sum_map[curr_sum] = i;
        }

        return max_len;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();// to ignore the newline after the integer input
    while (t--)
    {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends