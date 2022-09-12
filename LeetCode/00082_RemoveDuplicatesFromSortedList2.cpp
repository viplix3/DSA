// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *sortedListDummyHead = new ListNode();
        sortedListDummyHead->next = head;
        ListNode *prevNode = sortedListDummyHead, *currNode = head;
        
        while(currNode && currNode->next) {
            int prevNodeVal;
            
            while(currNode->next && currNode->val == currNode->next->val) {
                ListNode *deleteNode = currNode;
                prevNodeVal = currNode->val;
                prevNode->next = currNode->next;
                currNode = currNode->next;
                delete deleteNode;
            }
            
            if(currNode->val == prevNodeVal) {
                ListNode *deleteNode = currNode;
                prevNode->next = currNode->next;
                currNode = currNode->next;
                delete deleteNode;
            }
            else
                prevNode = prevNode->next, currNode = currNode->next;
        }
        
        return sortedListDummyHead->next;
    }
};