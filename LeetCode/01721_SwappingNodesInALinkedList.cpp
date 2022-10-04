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
        ListNode *dummyHead = new ListNode(-1, head);
		ListNode *prevKth = dummyHead;
        
        for(int i = 0; i < k - 1; i++)
			prevKth = prevKth->next;
        
        ListNode *prevNminusKth = dummyHead, *fastPtr = prevKth->next->next;
        
		while(fastPtr != nullptr) {
			prevNminusKth = prevNminusKth->next;
			fastPtr = fastPtr->next;
		}
        
		ListNode *kthNode = prevKth->next, *nMinusKthNode = prevNminusKth->next;
		ListNode *nextKth = kthNode->next, *nextNminusKth = nMinusKthNode->next;
        
        // Adjacent nodes, kth node is previous of (n-k)th node
        if(nextKth == nMinusKthNode) {
            kthNode->next = nextNminusKth; // Link kth node to the right of (n-k)th node
            prevKth->next = nMinusKthNode; // Link left of kth node to (n-k)th node
            
            nMinusKthNode->next = kthNode; // Link (n-k)th node to kth node
        }
        else if(nextNminusKth == kthNode) { // Adjacent nodes, kth node is next of (n-k)th node
            nMinusKthNode->next = nextKth; // Link (n-k)th node to the right of kth node
            prevNminusKth->next = kthNode; // Link left of (n-k)th node to kth node
            
            kthNode->next = nMinusKthNode; // Link kth node to (n-k)th node
        }
        else { // Normal swapping
            kthNode->next = nextNminusKth;
            prevNminusKth->next = kthNode;
            
            nMinusKthNode->next = nextKth;
            prevKth->next = nMinusKthNode;
        }

        head = dummyHead->next;
        delete dummyHead;
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