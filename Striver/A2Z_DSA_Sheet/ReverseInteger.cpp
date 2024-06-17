// https://leetcode.com/problems/reverse-integer/description/

class Solution
{

private:
    int INT_MAX = 2147483647;
    int INT_MIN = -2147483648;

public:
    int reverse(int x)
    {
        int rev_num = 0;

        while (x)
        {
            if (rev_num > INT_MAX / 10 || (rev_num == INT_MAX / 10 && rev_num % 10 > 7))
                return 0;

            if (rev_num < INT_MIN / 10 || (rev_num == INT_MIN / 10 && rev_num % 10 < -8))
                return 0;

            int digit = x % 10;
            rev_num = (rev_num * 10) + digit;
            x /= 10;
        }

        return rev_num;
    }
};