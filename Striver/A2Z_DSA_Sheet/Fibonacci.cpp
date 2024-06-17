// https://www.naukri.com/code360/problems/nth-fibonacci-number_74156?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=DISCUSS

#include <bits/stdc++.h>

class Fibonacci
{
public:
    int find_fibonacci(int N)
    {
        if (N <= 2)
            return 1;

        int prev = 1, prev_prev = 1;
        int curr = prev + prev_prev;

        for (int i = 3; i <= N; i++)
        {
            curr = prev + prev_prev;
            prev_prev = prev;
            prev = curr;
        }

        return curr;
    }
};

int main()
{
    Fibonacci fib_finder;
    int N;
    std::cin >> N;
    std::cout << fib_finder.find_fibonacci(N) << std::endl;

    return 0;
}