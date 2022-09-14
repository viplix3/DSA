// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getListLength(ListNode* head) {
        int len = 0;
        
        while(head) {
            head = head->next;
            len++;
        }
        
        return len;
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return nullptr;
        
        if(headA == headB)
            return headA;
        
        int lenA = getListLength(headA), lenB = getListLength(headB);
        int lenDiff = abs(lenA - lenB);
        
        ListNode *longerListHead = (lenA > lenB) ? headA : headB;
        ListNode *shortedListHead = (longerListHead == headA) ? headB : headA;
        
        while(lenDiff--)
            longerListHead = longerListHead->next;
        
        while(longerListHead && shortedListHead) {
            if(longerListHead == shortedListHead) // Common node
                return longerListHead;
            
            longerListHead = longerListHead->next;
            shortedListHead = shortedListHead->next;
        }
        
        return nullptr;
    }
};