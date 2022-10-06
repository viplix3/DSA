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


// LC discuss genius solution
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        
        Node *curr = head;
        
        /*
         * Traverse horizontally until a child a found
         * If you see a child (vertically), make that the next of current (parent) node
         * Go to the end of child LL and link the right of parent node to the tail of child LL
         * Keep doing above steps, if you reach nullptr on horizontal+child traversal, you've flattened the LL
        */
        while(curr) {
            if(curr->child) {
                Node *parentRightNode = curr->next;
                
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;
                
                Node *childListRunner = curr->next;
                
                while(childListRunner->next)
                    childListRunner = childListRunner->next;
                
                childListRunner->next = parentRightNode;
                if(parentRightNode)
                    parentRightNode->prev = childListRunner;
            }
            else
                curr = curr->next;
        }
        
        return head;
    }
};


// My weak-ass solution
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