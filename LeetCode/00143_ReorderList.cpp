// https://leetcode.com/problems/reorder-list/

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
    ListNode* getFromMid(ListNode* head) {
        ListNode *fastPtr = head, *slowPtr = head, *prevPtr = nullptr;
        
        while(fastPtr && fastPtr->next) {
            prevPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        // Disconnect the first half from second half
        prevPtr->next = nullptr;
        return slowPtr;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *curr = head, *prev = nullptr;
        while(curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        
        return prev;
    }
    
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        
        // Split
        ListNode *midNodePtr = splitFromMid(head);
        
        // Reverse
        ListNode *secondHalfNode = reverseList(midNodePtr);
        
        // Merge
        ListNode *firstHalfNode = head;
        ListNode *modifiedListHead = new ListNode(), *modifiedListTail = modifiedListHead;
        
        while(firstHalfNode && secondHalfNode) {
            modifiedListTail->next = firstHalfNode;
            firstHalfNode = firstHalfNode->next;
            modifiedListTail = modifiedListTail->next;
            
            modifiedListTail->next = secondHalfNode;
            secondHalfNode = secondHalfNode->next;
            modifiedListTail = modifiedListTail->next;
        }
        
        delete modifiedListHead;
    }
};