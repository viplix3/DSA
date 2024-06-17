//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long sum_of_divisors = 0;

        /*
        * We have to find the sum of divisors of all the numbers leading upto N
        * Suppose N = 4, and f(x) = sum of divisors of x
        * f(1) = 1
        * f(2) = 1 + 2 = 3
        * f(3) = 1 + 3 = 4
        * f(4) = 1 + 2 + 4 = 7
        * sumOfDivisors(4) = f(1) + f(2) + f(3) + f(4) = 15
        * sumOfDivisors(4) = 1 + 1 + 2 + 1 + 3 + 1 + 2 + 4 = 15
        * sumOfDivisors(4) = 4 + 4 + 3 + 4 // Rearranged the terms
        * sumOfDivisors(4) = (1 * (4/1)) + (2 * (4/2)) + (3 * (4/3)) + (4 * (4/4))
        * sumOfDivisors(N) = (1 * (N/1)) + (2 * (N/2)) + (3 * (N/3)) + (4 * (N/N))
        */
        for (long long i = 1; i <= N; i++)
            sum_of_divisors += i * (N / i);

        return sum_of_divisors;
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
        long long ans = ob.sumOfDivisors(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends