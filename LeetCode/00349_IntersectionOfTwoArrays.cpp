// https://leetcode.com/problems/intersection-of-two-arrays/

// O(N) time and O(N) space solution
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> numsIntersection;
        unordered_set<int> hashset(nums1.begin(), nums1.end());
        
        for(int ele : nums2)
            if(hashset.find(ele) != hashset.end()) {
                numsIntersection.push_back(ele);
                hashset.erase(ele);
            }
        
        return numsIntersection;
    }
};

// Merge Sort: O(N log(N))
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> numsIntersection;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int nums1Itr = 0, nums2Itr = 0;
        int numElems1 = nums1.size(), numElems2 = nums2.size();
        
        while(nums1Itr < numElems1 && nums2Itr < numElems2) {
            if(nums1[nums1Itr] == nums2[nums2Itr]) {
                numsIntersection.push_back(nums1[nums1Itr]);
                nums1Itr++;
                nums2Itr++;
            }
            else if(nums1[nums1Itr] < nums2[nums2Itr])
                nums1Itr++;
            else
                nums2Itr++;
            
            // Skip repeating elements
            while(nums1Itr > 0 && nums1Itr < numElems1 && nums1[nums1Itr] == nums1[nums1Itr - 1])
                nums1Itr++;
            
            while(nums2Itr > 0 && nums2Itr < numElems2 && nums2[nums2Itr] == nums2[nums2Itr - 1])
                nums2Itr++;
        }
        
        return numsIntersection;
    }
};