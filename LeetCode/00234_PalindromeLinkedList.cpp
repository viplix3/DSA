// https://leetcode.com/problems/palindrome-linked-list/

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
        ListNode *fastPtr = head, *slowPtr = head;
        
        while(fastPtr && fastPtr->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        return slowPtr;
    }
    
    ListNode* reverseList(ListNode *head) {
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
    bool isPalindrome(ListNode* head) {
        ListNode *midPtr = splitList(head);
        ListNode *reversed2ndHalf = reverseList(midPtr);
        ListNode *firstHalf = head;
        
        while(reversed2ndHalf) {
            if(firstHalf->val != reversed2ndHalf->val)
                return false;
            
            firstHalf = firstHalf->next, reversed2ndHalf = reversed2ndHalf->next;
        }
        
        return true;
    }
};