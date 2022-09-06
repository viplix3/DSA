// https://leetcode.com/problems/minimum-size-subarray-sum/

// Sliding window
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int numSize = nums.size();
        int windowInitIdx = 0, windowEndIdx = 0, currWindowSum = 0;
        int minWindowSize = numSize + 1;
        
        while(windowEndIdx < numSize) {
            currWindowSum += nums[windowEndIdx];
            
            while(windowInitIdx <= windowEndIdx && currWindowSum >= target) {
                minWindowSize = min(windowEndIdx - windowInitIdx + 1, minWindowSize);
                currWindowSum -= nums[windowInitIdx];
                windowInitIdx++;
            }
            
            windowEndIdx++;
        }
        
        return (minWindowSize == numSize + 1) ? 0 : minWindowSize;
    }
};

// Binary seach O(N log(N)), because asked as followup
class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int numElems = nums.size();
		vector<int> prefixSum(numElems + 1, 0);

		for(int i = 0; i < numElems; i++)
			prefixSum[i + 1] = prefixSum[i] + nums[i];
	
	 	int windowEndIdx = numElems, minWindowSize = numElems + 1;
		if(prefixSum[windowEndIdx] < target)
			return 0;

		for(; windowEndIdx > 0 && prefixSum[windowEndIdx] >= target; windowEndIdx--) {
			int searchIdx = upper_bound(prefixSum.begin(), prefixSum.end(), prefixSum[windowEndIdx] - target) - prefixSum.begin();
			minWindowSize = min(windowEndIdx - searchIdx + 1, minWindowSize);
		}

		return minWindowSize;
	}
};