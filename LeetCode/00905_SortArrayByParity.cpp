// https://leetcode.com/problems/sort-array-by-parity/

// Hoare's partition based solution
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int evenIdx = -1, oddIdx = nums.size();
        while(true) {
            do {
                evenIdx++;
            } while(evenIdx < oddIdx && nums[evenIdx] % 2 == 0);
                
            do {
                oddIdx--;
            } while(oddIdx > evenIdx && nums[oddIdx] % 2 != 0);
            
            if(evenIdx >= oddIdx)
                return nums;
            
            swap(nums[evenIdx], nums[oddIdx]);
        }
        
        return nums;
    }
};

// Simple check and swap (by GitHub CoPilot)
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int numElems = A.size();
		int evenIdx = 0, oddIdx = numElems - 1;
		
		while(evenIdx < oddIdx) {
			if(A[evenIdx] % 2 == 0)
				evenIdx++;
			else {
				swap(A[evenIdx], A[oddIdx]);
				oddIdx--;
			}
		}
		
		return A;
	}
};