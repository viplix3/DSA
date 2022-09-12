// https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        // Dummy nodes
        ListNode *lessThanXHead = new ListNode();
        ListNode *greaterThanXHead = new ListNode();
        
        ListNode *curr = head;
        ListNode *lessThanXTail = lessThanXHead, *greaterThanXTail = greaterThanXHead;
        
        while(curr) {
            
            if(curr->val < x) {
                lessThanXTail->next = curr;
                lessThanXTail = lessThanXTail->next;
            }
            else {
                greaterThanXTail->next = curr;
                greaterThanXTail = greaterThanXTail->next;
            }
            
            curr = curr->next;
        }
        
        lessThanXTail->next = greaterThanXHead->next;
        greaterThanXTail->next = nullptr;
        
        ListNode *sortedListHead = lessThanXHead->next;
        
        delete lessThanXHead;
        delete greaterThanXHead;
        
        return sortedListHead;
    }
};