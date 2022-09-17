// https://leetcode.com/problems/remove-linked-list-elements/



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
// Single Pointer
class Solution {
public:
    ListNode* removeElements(ListNode* head, int targetVal) {
        if(!head)
            return nullptr;
        
        ListNode *deleteNode = nullptr;
        
        while(head != nullptr && head->val == targetVal) {
            deleteNode = head;
            head = head->next;
            delete deleteNode;
        }
        
        ListNode *curr = head;
        
        while(curr && curr->next) {
            if(curr->next->val == targetVal) {
                deleteNode = curr->next;
                curr->next = curr->next->next;
                delete deleteNode;
            }
            else
                curr = curr->next;
        }
        
        return head;
    }
};


// 2-pointer
class Solution {
public:
    ListNode* removeElements(ListNode* head, int targetVal) {
        if(!head)
            return nullptr;
        
        ListNode *deleteNode = nullptr;
        
        while(head != nullptr && head->val == targetVal) {
            deleteNode = head;
            head = head->next;
            delete deleteNode;
        }
        
        ListNode *curr = head, *prev = nullptr;
        
        while(curr) {
            if(curr->val == targetVal) {
                deleteNode = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete deleteNode;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};