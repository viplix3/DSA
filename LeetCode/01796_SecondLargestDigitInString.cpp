class Solution
{
public:
    int secondHighest(string s)
    {
        int max = -1, second_max = -1;

        for (char c: s)
        {
            if (!isdigit(c))
                continue;
            else
            {
                int num = c - '0';
                if (max == -1)
                    max = num;
                else if (num > max)
                {
                    second_max = max;
                    max = num;
                }
                else if (num > second_max && num < max)
                    second_max = num;
            }
        }

        return second_max;
    }
};