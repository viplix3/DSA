#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string clean_string(string s)
    {
        stringstream ss(s), out_ss;

        char ch;
        while (ss >> ch)
        {
            if (isalnum(ch))
            {
                if ('A' <= ch && ch <= 'Z')
                    ch = tolower(ch);
                out_ss << ch;
            }
        }

        return out_ss.str();
    }

    bool checkPalindrome(string s, size_t l_itr, size_t r_itr)
    {
        if (l_itr >= r_itr)
            return true;

        if (s[l_itr] == s[r_itr])
            return checkPalindrome(s, l_itr + 1, r_itr - 1);

        return false;
    }

public:
    bool isPalindrome(string s)
    {
        string cleaned_str = clean_string(s);

        if (cleaned_str.length() <= 1)
            return true;

        size_t l_itr = 0, r_itr = cleaned_str.length() - 1;
        return checkPalindrome(cleaned_str, l_itr, r_itr);
    }

    bool isPalindrome_iterative(string s)
    {
        string cleaned_str = clean_string(s);

        auto l_itr = cleaned_str.begin();
        auto r_itr = cleaned_str.end() - 1;

        while (l_itr <= r_itr)
        {
            if (!(*l_itr == *r_itr))
                return false;
            l_itr++, r_itr--;
        }

        return true;
    }
};

int main()
{
    int test_cases;
    cin >> test_cases;
    cin.ignore();

    Solution sol_obj;
    while (test_cases--)
    {
        string input_string;
        getline(cin, input_string);
        cout << sol_obj.isPalindrome(input_string) << endl;
    }

    return 0;
}