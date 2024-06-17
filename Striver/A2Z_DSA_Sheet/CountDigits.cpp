// https://www.geeksforgeeks.org/problems/count-digits5716/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int evenlyDivides(int N)
    {
        int num_divisors = 0;
        int num = N;

        while (N)
        {
            int digit = N % 10;
            if (digit != 0)
                num_divisors += (num % digit == 0);
            N /= 10;
        }

        return num_divisors;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0;
}
// } Driver Code Ends