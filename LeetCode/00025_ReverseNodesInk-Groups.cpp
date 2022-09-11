// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        
        ListNode *prev = nullptr, *curr = head;
        ListNode *prevGroupTail = nullptr, *currGroupTail = nullptr;
        
        while(curr) {
            int numReversed = k;
            ListNode *next, *currGroupLenChecker = curr; 
            currGroupTail = curr, prev = nullptr;
            
            for(int i = 0; i < k; i++) {
                if(!currGroupLenChecker) {
                    prevGroupTail->next = curr;
                    return head;
                }
                    
                currGroupLenChecker = currGroupLenChecker->next;
            }
            
            // Reverse in groups of k
            while(curr && numReversed--) {
                next = curr->next;
                curr->next = prev;
                prev = curr, curr = next;
            }
            
            // If this is the first group being reversed
            if(!prevGroupTail)
                head = prev;
            else
                prevGroupTail->next = prev;
            
            prevGroupTail = currGroupTail;
        }
        
        return head;
    }
};