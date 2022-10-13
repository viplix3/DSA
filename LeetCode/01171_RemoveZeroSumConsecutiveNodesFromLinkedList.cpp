// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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
// Leetcode keeps giving illegal memory access errors if I delete nodes
class Solution {
private:
    void deleteNodes(ListNode *deleteBegin, ListNode *deleteEnd,
                    unordered_map<int, ListNode*> &prefixSumHashMap, int prefixSum) {
        ListNode *deleteNode = deleteBegin;
        ListNode *nextDeleteNode = nullptr;
        
        while(nextDeleteNode != deleteEnd) {
            prefixSum += deleteNode->val;
            
            prefixSumHashMap.erase(prefixSum);
            nextDeleteNode = deleteNode->next;
            
            // delete deleteNode;
            deleteNode = nextDeleteNode;
        } 
    }
    
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head)
            return nullptr;
        
        if(!head->next && head->val == 0)
            return nullptr;
        
        while(head != nullptr && head->val == 0) {
            ListNode *deleteNode = head;
            head = head->next;
            // delete deleteNode;
        }

        unordered_map<int, ListNode*> prefixSumHashMap;
        ListNode *dummyNode = new ListNode(INT_MIN, head), *curr = head;
        int prefixSum = 0;
        prefixSumHashMap[prefixSum] = dummyNode;
        
        while(curr) {
            prefixSum += curr->val;
            
            if(prefixSumHashMap.find(prefixSum) != prefixSumHashMap.end()) {
                ListNode *preDelete = prefixSumHashMap[prefixSum];
                ListNode *postDelete = curr->next;
                
                deleteNodes(preDelete->next, postDelete, prefixSumHashMap, prefixSum);
                preDelete->next = postDelete;
                curr = preDelete;
            }
            
            prefixSumHashMap[prefixSum] = curr;
            curr = curr->next;
        }
        return dummyNode->next;
    } 
};