// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return nullptr;
        
        ListNode *fastPtr = head, *slowPtr = head;
        
        while(fastPtr && fastPtr->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            
            if(slowPtr == fastPtr)
                break;
        }
        
        if(slowPtr != fastPtr)
            return nullptr;
        
        slowPtr = head;
        while(slowPtr != fastPtr)
            slowPtr = slowPtr->next, fastPtr = fastPtr->next;
        
        return slowPtr;
    }
};