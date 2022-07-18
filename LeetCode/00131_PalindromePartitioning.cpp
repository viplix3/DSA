// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
private:
    bool isPalindrome(string str, int beginIdx, int endIdx) {
        while(beginIdx < endIdx) {
            if(str[beginIdx] != str[endIdx])
                return false;
            
            beginIdx += 1;
            endIdx -= 1;
        }
        return true;
    }
    
    void findPalindromePartitions(string str, int partitionInitIdx,
                                  vector<string>& currPalindromePartitions,
                                  vector<vector<string>>& allPalindromePartitions) {
        if(partitionInitIdx == str.length()) {
            allPalindromePartitions.push_back(currPalindromePartitions);
            return;
        }
        
        
        for(int currIdx = partitionInitIdx; currIdx < str.length(); currIdx++) {
            if(isPalindrome(str, partitionInitIdx, currIdx)) {
                // Pick
                currPalindromePartitions.push_back(str.substr(partitionInitIdx, currIdx - partitionInitIdx + 1));
                findPalindromePartitions(str, currIdx + 1, currPalindromePartitions, allPalindromePartitions);
                currPalindromePartitions.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> allPalindromePartitions;
        vector<string> currPalindromePartitions;
        int startIdx = 0;
        
        findPalindromePartitions(s, startIdx, 
                                 currPalindromePartitions, allPalindromePartitions);
        return allPalindromePartitions;
    }
};