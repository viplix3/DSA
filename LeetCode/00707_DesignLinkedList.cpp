// https://leetcode.com/problems/design-linked-list/

class MyLinkedList {
private:
    ListNode *head;
    int listLen;
   
    
public:
    MyLinkedList() {
        head = nullptr;
        listLen = 0;
    }

    ~MyLinkedList() {
        ListNode *deleteNode;
        while(head) {
            deleteNode = head;
            head = head->next;
            delete deleteNode;
        }
    }
    
    int get(int index) {
        if(!head)
            return -1;
        
        if(index < 0 || index >= listLen)
            return -1;
        
        ListNode *curr = head;
        for(int i = 0; i < index; i++)
            curr = curr->next;
        
        return curr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(listLen, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > listLen)
            return;
        
        ListNode *newNode = new ListNode(val);
        
        // add at head
        if(index == 0) {
            newNode->next = head;
            head = newNode;
        }
        else { // add elsewhere in the linked list
            ListNode *curr = head;
            
            for(int i = 0; i < index - 1; i++)
                curr = curr->next;
            
            newNode->next = curr->next;
            curr->next = newNode;
        }
        
        listLen++;
    }
    
    void deleteAtIndex(int index) {
        if(!head)
            return;
        
        if(index < 0 || index >= listLen)
            return;
        
        ListNode *deleteNode = nullptr;
        // Delete head
        if(index == 0) {
            deleteNode = head;
            head = head->next;
            delete deleteNode;
        }
        else { // delete from elsewhere in the linked list
            ListNode *curr = head;
            
            for(int i = 0; i < index - 1; i++)
                curr = curr->next;
            
            deleteNode = curr->next;
            curr->next = curr->next->next;
            delete deleteNode;
        }
        
        listLen--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */