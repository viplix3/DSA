// https://leetcode.com/problems/palindrome-number/

class Solution {
private:
    int reverse(int x) {
        long long reverseNum = 0;
        
        while(x) {
            reverseNum = 10 * reverseNum + (x % 10);
            x /= 10;
        }
        
        return static_cast<int>(reverseNum);
    }
    
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        return (x == reverse(x));
    }
};