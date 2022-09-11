// https://leetcode.com/problems/rotate-list/

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
// Make LL circular by connecting tail with head, go to head + k position
// next node would be new head, disconnect current node and mark it as last
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        
        ListNode *tail = head, *newHead;
        int listLen = 1;
        
        // Find the last node and list length
        while(tail->next) {
            tail = tail->next;
            listLen++;
        }
        
        // Connect tail with head to make linked list circular
        tail->next = head;
        
        k = k % listLen;
        for(int i = 0; i < listLen - k; i++)
            tail = tail->next;
        
        newHead = tail->next;
        tail->next = nullptr;
        
        return newHead;
    }
};