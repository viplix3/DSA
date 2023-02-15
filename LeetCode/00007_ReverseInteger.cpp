// https://leetcode.com/problems/reverse-integer/

class Solution
{
public:
    int reverse(int x)
    {
        int revNum = 0;

        while (x)
        {
            int digit = x % 10;

            // 2nd part of || makes sure all the int range is utilized
            if (revNum > INT_MAX / 10 || (revNum == INT_MAX / 10 && digit > 7))
                return 0;
            if (revNum < INT_MIN / 10 || (revNum == INT_MIN / 10 && digit < -8))
                return 0;

            revNum = (revNum * 10) + (x % 10);
            x /= 10;
        }

        return revNum;
    }
};