// https://leetcode.com/problems/odd-even-linked-list/

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
// Cleaner code taken for LC discuss
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *oddTail = head;
        ListNode *evenHead = head->next, *evenTail = evenHead;
       
        while(evenTail && evenTail->next) {
            oddTail->next = oddTail->next->next;
            evenTail->next = evenTail->next->next;
            
            oddTail = oddTail->next;
            evenTail = evenTail->next;
        }
        
        oddTail->next = evenHead;
        return head;
    }
};


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
// My janky code
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode oddDummyHead = ListNode(-1);
        ListNode evenDummyHead = ListNode(-2);
        
        ListNode *oddTail = &(oddDummyHead);
        ListNode *evenTail = &(evenDummyHead);
        
        int currIdx = 1;
        while(head) {
            if(currIdx % 2) {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
            else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
            
            head = head->next;
            currIdx++;
        }
        
        oddTail->next = evenDummyHead.next;
        evenTail->next = nullptr;
        
        return oddDummyHead.next;
    }
};