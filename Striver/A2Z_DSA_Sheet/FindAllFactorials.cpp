// https://www.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0?problemType=functional&difficulty%255B%255D=-1&page=1&query=problemTypefunctionaldifficulty%255B%255D-1page1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
private:
    void find_factorials(long long N, vector<long long> &factorial_nums, long long curr_num = 2)
    {
        // Last factorial was greater than N
        if (factorial_nums.back() >= N)
            return;

        long long new_factorial = factorial_nums.back() * curr_num;

        if (new_factorial > N)
            return;

        factorial_nums.push_back(new_factorial);
        find_factorials(N, factorial_nums, curr_num + 1);
    }

public:
    vector<long long> factorialNumbers(long long N)
    {
        vector<long long> factorial_nums = {1};
        find_factorials(N, factorial_nums);
        return factorial_nums;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num: ans)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}