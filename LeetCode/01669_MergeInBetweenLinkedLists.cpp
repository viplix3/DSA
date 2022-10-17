// https://leetcode.com/problems/merge-in-between-linked-lists/

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if(!list1 && !list2)
            return nullptr;
        
        if(!list1)
            return nullptr;
        
        if(!list2)
            return list1;
        
        ListNode *dummyHead = new ListNode(INT_MIN, list1);
        ListNode *curr = list1;
        ListNode *preInsertNode = dummyHead, *postInsertNode = nullptr;
        int currIdx = 0;
        
        // Find a - 1
        while(curr) {
            if(currIdx == a)
                break;
            
            preInsertNode = curr;
            curr = curr->next, currIdx += 1;
        }
        
        // Find b + 1
        while(curr) {
            if(currIdx == b) {
                postInsertNode = curr->next;
                break;
            }
            
            curr = curr->next, currIdx += 1;
        }
        
        // Find tail of list 2
        ListNode *list2Tail = list2;
        while(list2Tail->next)
            list2Tail = list2Tail->next;
        
        // Connect the list 2 in b/w a-1 and b+1
        preInsertNode->next = list2;
        list2Tail->next = postInsertNode;
        
        ListNode *mergedHead = dummyHead->next;
        delete dummyHead;
        return mergedHead;
    }
};