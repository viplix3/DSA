// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        if(list2 == nullptr)
            return list1;
        
        ListNode* sortedListHead = list1;
        
        if(list1->val > list2->val) {
            sortedListHead = list2;
            list2 = list2->next;
        }
        else
            list1 = list1->next;
        
        ListNode *sortedListTail = sortedListHead;
        
        while(list1 && list2) {
            if(list1->val < list2->val) {
                sortedListTail->next = list1;
                sortedListTail = sortedListTail->next;
                list1 = list1->next;
            }
            else {
                sortedListTail->next = list2;
                sortedListTail = sortedListTail->next;
                list2 = list2->next;
            }
        }
        
        if(list1)
            sortedListTail->next = list1;
        else
            sortedListTail->next = list2;
        
        return sortedListHead;
    }
};