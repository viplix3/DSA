// https://leetcode.com/problems/palindrome-number/

#include <bits/stdc++.h>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // If x is nevative it can never be a palindrome
        // If last digit if x is 0, it can never be palindrome except x is 0
        if (x < 0 || (x % 10 == 0 & x != 0))
            return false;

        // reverse half of x
        int rev = 0;
        while (x > rev)
        {
            rev = (rev * 10) + x % 10;
            x /= 10;
        }

        // if x has even digits and is a palindrome, after above loop, x == rev
        // if x has odd digits, (eg. 121), after above loop, x will be 1 and rev will be 12
        //  we can remove 2 and check if x == rev, if it is palindrome, the condition will be true
        return (x == rev) || (rev / 10 == x);
    }
};

int main()
{
    int test_cases;
    std::cin >> test_cases;

    Solution sol;

    while (test_cases--)
    {
        int n;

        std::cin >> n;
        std::cout << sol.isPalindrome(n) << std::endl;
    }

    return 0;
}