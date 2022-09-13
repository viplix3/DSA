// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void createCopyNodes(Node *head) {
        while(head) {
            Node *copyNode = new Node(head->val);
            copyNode->next = head->next;
            head->next = copyNode;
            head = head->next->next; // Skip the copy node
        }
    }
    
    void connectRandomPointers(Node *head) {
        while(head) {
            if(head->random)
                head->next->random = head->random->next;
            head = head->next->next; // skip the copy node
        }
    }
    
    Node *detachCopyNodes(Node *head) {
        Node *copyHeadDummy = new Node(0);
        Node *copyTail = copyHeadDummy;
        
        while(head) {
            copyTail->next = head->next; // connect copied node to copyTail
            head->next = head->next->next; // Restore original links
            
            head = head->next;
            copyTail = copyTail->next;
        }
        
        Node *copyHead = copyHeadDummy->next;
        delete copyHeadDummy;
        return copyHead;
    }
    
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        
        createCopyNodes(head); // Creates duplicate nodes in the LL
        connectRandomPointers(head);
        Node *copyHead = detachCopyNodes(head);
        
        return copyHead;
    }
};