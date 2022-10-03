// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *kthNode = nullptr, *nMinusKthNode = nullptr;
        
        for(auto curr = head; curr != nullptr; curr = curr->next) {
            nMinusKthNode = (nMinusKthNode == nullptr) ? nullptr : nMinusKthNode->next;
            
            if(--k == 0) {
                kthNode = curr;
                nMinusKthNode = head;
            }
        }
        
        swap(kthNode->val, nMinusKthNode->val);
        return head;
    }
};