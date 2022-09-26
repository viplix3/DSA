// https://leetcode.com/problems/add-two-numbers-ii/

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

// Doesn't modify input lists and doesn't reverse lists
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> nums1, nums2;
        
        while(l1 != nullptr) {
            nums1.push_back(l1->val);
            l1 = l1->next;
        }
        
        while(l2 != nullptr) {
            nums2.push_back(l2->val);
            l2 = l2->next;
        }
        
        ListNode *sumListTail = nullptr, *sumListHead = nullptr;
        
        int nums1Size = nums1.size(), nums2Size = nums2.size();
        int sum = 0, carry = 0;
        
        for(int i = nums1Size - 1, j = nums2Size - 1; i >= 0 || j >= 0 || carry > 0; i--, j--) {
            sum = carry;
            
            if(i >= 0)
                sum += nums1[i];
            
            if(j >= 0)
                sum += nums2[j];
            
            carry = sum / 10;
            sumListHead = new ListNode(sum % 10);
            sumListHead->next = sumListTail;
            sumListTail = sumListHead;
        }
        
        return sumListHead;
    }
};



// Modifies the input lists
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        
        if(!l2)
            return l1;
        
        ListNode *l1Rev = reverseList(l1);
        ListNode *l2Rev = reverseList(l2);
        
        ListNode *sumListTail = new ListNode(INT_MIN);
        
        ListNode *sumListHead = sumListTail;
        int carry = 0;
        
        while(l1Rev != nullptr || l2Rev != nullptr) {
            int sum = 0;
            
            if(l1Rev) {
                sum += l1Rev->val;
                l1Rev = l1Rev->next;
            }
            
            if(l2Rev) {
                sum += l2Rev->val;
                l2Rev = l2Rev->next;
            }
            
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            
            sumListHead->next = new ListNode(sum);
            sumListHead = sumListHead->next;
        }
        
        if(carry != 0) {
            sumListHead->next = new ListNode(carry);
            sumListHead = sumListHead->next;
        }
        
        
        ListNode *deleteNode = sumListTail;
        sumListTail = sumListTail->next;
        delete deleteNode;
        
        sumListHead = reverseList(sumListTail);
        return sumListHead;
    }
};