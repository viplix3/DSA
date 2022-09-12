// https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next)
            return head;
        
        ListNode *curr = head, *prevLeft = nullptr, *nextRight = nullptr;
        int currPosition = 1;
        
        // Go to left
        while(curr && currPosition != left) {
            prevLeft = curr, curr = curr->next;
            currPosition++;
        }
            
        // Reverse until right
        ListNode *revHead = curr;
        ListNode *prev = nullptr, *next = nullptr;
        while(curr && currPosition != right + 1) {
            next = curr->next;
            curr->next = prev;
            prev = curr, curr = next, nextRight = next;
            currPosition++;
        }
        
        // Full list is reversed
        if(prevLeft == nullptr && nextRight == nullptr)
            return prev;
        
        // Connect the reversed part with rest of the list
        if(revHead != head) // Some links are there before left which needs preserving
            prevLeft->next = prev; // Connect the node before reversing to last reversed node
        else
            head = prev;
        
        revHead->next = nextRight;
        
        return head;
    }