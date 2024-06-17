// https://leetcode.com/problems/fibonacci-number/

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;

        if (n <= 2)
            return 1;

        int prev = 1, prev_prev = 1;
        int curr = prev + prev_prev;

        for (int i = 3; i <= n; i++)
        {
            curr = prev + prev_prev;
            prev_prev = prev;
            prev = curr;
        }

        return curr;
    }
};