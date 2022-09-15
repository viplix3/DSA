// https://leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *sortedListDummyHead = new ListNode(INT_MIN);
        ListNode *curr = head, *sortedListPtr = sortedListDummyHead;
        
        while(curr) {
            sortedListPtr = sortedListDummyHead;
            
            // Find a position for insertion
            while(sortedListPtr->next && sortedListPtr->next->val < curr->val)
                sortedListPtr = sortedListPtr->next;
            
            // Insert
            ListNode *next = curr->next;
            curr->next = sortedListPtr->next;
            sortedListPtr->next = curr;
            curr = next;
        }
        
        ListNode *sortedHead = sortedListDummyHead->next;
        delete sortedListDummyHead;
        return sortedHead;
    }
    
};