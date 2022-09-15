// https://leetcode.com/problems/sort-list/

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
    ListNode* splitList(ListNode *head) {
        ListNode *slowPtr = head, *fastPtr = head;
        while(fastPtr->next && fastPtr->next->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        ListNode *rightHalfHead = slowPtr->next;
        slowPtr->next = nullptr;
        return rightHalfHead;
        
    }
    
    ListNode* mergeList(ListNode *headLeft, ListNode *headRight) {
        if(!headLeft)
            return headRight;
        if(!headRight)
            return headLeft;
        
        ListNode mergedListDummyHead(INT_MIN);
        ListNode *mergedListTail = &(mergedListDummyHead);
        
        while(headLeft && headRight) {
            if(headLeft->val <= headRight->val) {
                mergedListTail->next = headLeft;
                headLeft = headLeft->next;
            }
            else {
                mergedListTail->next = headRight;
                headRight = headRight->next;
            }
            
            mergedListTail = mergedListTail->next;
        }
        
        if(headLeft)
            mergedListTail->next = headLeft;
        if(headRight)
            mergedListTail->next = headRight;
        
        return mergedListDummyHead.next;
    }
    
    void mergeSortLL(ListNode **headPtrRef) {
        ListNode *headPtr = *headPtrRef;
        
        if(!headPtr || !headPtr->next)
            return;
        
        ListNode *headLeft = headPtr;
        ListNode *headRight = splitList(headPtr);
        
        mergeSortLL(&headLeft);
        mergeSortLL(&headRight);
        *headPtrRef = mergeList(headLeft, headRight);
        
    }
    
public:
    ListNode* sortList(ListNode* head) {
        mergeSortLL(&head);
        return head;
    }
};