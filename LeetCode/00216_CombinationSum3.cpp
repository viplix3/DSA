// https://leetcode.com/problems/combination-sum-iii/

// Combination sum 1 and 2 like solution
class Solution {
private:
    void findAllCombinations(vector<vector<int>>& allCombinations,
                            vector<int>& currCombination, int prevSelectedDigit,
                            int allowedSize, int target) {
        if(currCombination.size() > allowedSize)
            return;
        
        if(target == 0 && currCombination.size() == allowedSize) {
            allCombinations.push_back(currCombination);
            return;
        }
        
        
        for(int currDigit = prevSelectedDigit + 1; currDigit < 10 && currDigit <= target; currDigit++) {
            currCombination.push_back(currDigit);
            findAllCombinations(allCombinations, currCombination, currDigit,
                                allowedSize, target - currDigit);
            currCombination.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> allCombinations;
        vector<int> currCombination;
        int currSelectionIdx = 0;
        
        findAllCombinations(allCombinations, currCombination, currSelectionIdx,
                           k, n);
        return allCombinations;
    }
};

// GitHub CoPilot solution, faster than 100% of submissions
class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> res;
		vector<int> cur;
		dfs(k, n, 1, cur, res);
		return res;
	}
	
	void dfs(int k, int n, int start, vector<int>& cur, vector<vector<int>>& res) {
		if (k == 0 && n == 0) {
			res.push_back(cur);
			return;
		}
		if (k == 0 || n == 0) return;
		for (int i = start; i <= 9; i++) {
			if (i > n) break;
			cur.push_back(i);
			dfs(k - 1, n - i, i + 1, cur, res);
			cur.pop_back();
		}
	}
};