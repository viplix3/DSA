// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
private:
    void findLetterCombinations(string& currCombination, const string& digits, int currKeyIdx,
                               vector<string>& possibleCombinations) {
                                 //  0   1     2      3      4      5      6      7       8      9
        static string keypadMap[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if(currCombination.length() == digits.length()) {
            possibleCombinations.push_back(currCombination);
            return;
        }
        
        for(int currKeySubIdx = 0; currKeySubIdx < keypadMap[digits[currKeyIdx] - '0'].length(); currKeySubIdx++) {
            // Add a letter from current keypad entry
            currCombination += keypadMap[digits[currKeyIdx] - '0'][currKeySubIdx];
            
            // Call the function to add a letter from next keypad entry
            findLetterCombinations(currCombination, digits, currKeyIdx+1, possibleCombinations);
            
            // Remove the added letter so that new latter can be added in next loop iteration
            currCombination.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> possibleCombinations;
        string currCombination = "";
        
        if(digits.length() == 0)
            return possibleCombinations;
        
        findLetterCombinations(currCombination, digits, 0, possibleCombinations);
        return possibleCombinations;
    }
};