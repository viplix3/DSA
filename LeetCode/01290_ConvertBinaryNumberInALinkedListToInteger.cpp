// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
    int getDecimalValue(ListNode* head) {
        int num = 0;
        
        while(head) {
            // 2 * num is like left shiting the result to add new bit
            num = (2 * num) + head->val;
            head = head->next;
        }
        
        return num;
    }
};


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string binaryNum;
        
        while(head) {
            binaryNum += to_string(head->val);
            head = head->next;
        }
        
        int num = 0, pwr = 1;
        for(int i = binaryNum.length() - 1; i >= 0; i--) {
            num += pwr * (stoi(binaryNum.substr(i, 1)));
            pwr *= 2;
        }
        
        return num;
    }
};