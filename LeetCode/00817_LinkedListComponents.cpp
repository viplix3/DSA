// https://leetcode.com/problems/linked-list-components/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        bool prevConnected = false, currConnected = false;
        int numConnectedComponents = 0;
        
        for(ListNode *curr = head; curr != nullptr; curr = curr->next) {
            currConnected = bool(numSet.count(curr->val)); // check if current element is a part of the nums array
            
            if(currConnected && prevConnected != currConnected) // we are starting a new component from the current element
                numConnectedComponents++;
            
            /*
                If current connected is not in nums (currConnected would be false)
                    - if previous was false, it will stay false
                    - if previous was true it was trying to extend some component, we set the previous as false marking the end of a component
                If current is present in nums (currConnected would be true)
                    - if prevConnected was already true, we will set it to true again and a new component would not be counted
                    - if prevConnected was false, we will set it as true so we could count a new component in the next loop iteration
            */
            prevConnected = currConnected; 
        }
        
        return numConnectedComponents;
    }
};