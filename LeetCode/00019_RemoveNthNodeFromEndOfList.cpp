// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *firstPtr = head, *secondPtr = head;
        
		// Move this node by n, so when this node is at the end
		// the other node is at the n-th node from the end
        while(n--)
            firstPtr = firstPtr->next;
        
		// If the first node is at the end, then n-th node from end is the head
        if(!firstPtr)
            return head->next;
            
        while(firstPtr->next)
            firstPtr = firstPtr->next, secondPtr = secondPtr->next;
        secondPtr->next = secondPtr->next->next;
        
        return head;
    }
};