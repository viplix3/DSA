// https://leetcode.com/problems/next-greater-node-in-linked-list/

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
private:
    ListNode* reverseLL(ListNode* head) {
        ListNode *curr = head, *prev = nullptr;
        
        while(curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        
        return prev;
    }
    
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head || !(head->next))
            return {0};
        
        vector<int> nextGreater;
        ListNode *rHead = reverseLL(head);
        ListNode *curr = rHead;
        stack<ListNode*> nextGreaterStack;
        
        nextGreaterStack.push(curr);
        nextGreater.push_back(0);
        curr = curr->next;
        
        while(curr) {
            while(!nextGreaterStack.empty() && curr->val >= (nextGreaterStack.top())->val)
                nextGreaterStack.pop();
            
            int nextMax = (nextGreaterStack.empty()) ? 0 : (nextGreaterStack.top())->val;
            nextGreater.push_back(nextMax);
            nextGreaterStack.push(curr);
            curr = curr->next;
        }
        
        reverse(nextGreater.begin(), nextGreater.end());
        return nextGreater;
    }
};