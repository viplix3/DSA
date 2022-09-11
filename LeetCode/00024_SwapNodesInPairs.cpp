// https://leetcode.com/problems/swap-nodes-in-pairs/

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

// Confusing as always
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *prev = head;
        
        // Set the head to new position
        head = head->next;
        prev->next = head->next;
        head->next = prev;
        ListNode *curr = prev->next;
        
        while(curr && curr->next) {
            prev->next = curr->next;
            prev = prev->next;
            
            curr->next = prev->next;
            prev->next = curr;
            
            prev = curr;
            curr = prev->next;
        }
        
        return head;
    }
};