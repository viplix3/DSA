// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        
        stack<Node*> parentRightNodes;
        
        Node *dummyHead = new Node(-1);
        Node *curr = head, *flattenTail = dummyHead;
        
        while(curr || !parentRightNodes.empty()) {
            if(curr) {
                curr->prev = flattenTail;
                flattenTail->next = curr;
                
                if(curr->child) {
                    parentRightNodes.push(curr->next);
                    Node *childNode = curr->child;
                    curr->child = nullptr;
                    curr = childNode;
                }
                else
                    curr = curr->next;
                
                flattenTail = flattenTail->next;
            }
            else {
                curr = parentRightNodes.top();
                parentRightNodes.pop();
            }
        }
        
        Node *flattenHead = dummyHead->next;
        delete dummyHead;
        
        flattenHead->prev = nullptr;
        flattenTail->next = nullptr;
        
        return flattenHead;
    }
};