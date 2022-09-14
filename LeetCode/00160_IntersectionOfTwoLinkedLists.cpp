// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Taken from: https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!
// Look at 1st comment for understanding clearly
class Solution {

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return nullptr;
        
        ListNode *nodeRunnerA = headA, *nodeRunnerB = headB;
        
        while(nodeRunnerA != nodeRunnerB) {
            nodeRunnerA = (nodeRunnerA == nullptr) ? headB : nodeRunnerA->next;
            nodeRunnerB = (nodeRunnerB == nullptr) ? headA : nodeRunnerB->next;
        }
        
        return nodeRunnerA;
    }
};

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