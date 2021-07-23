// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1/

// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
private:
    Node* splitList(Node* head_ptr)
    {
        Node *slow_ptr = head_ptr, *fast_ptr = head_ptr;
        
        while(fast_ptr->next != NULL && fast_ptr->next->next != NULL) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        
        Node *partition_node = slow_ptr->next;
        slow_ptr->next = NULL;
        return partition_node;
    }
    
    Node* mergeSortedLL(Node *head1_ptr, Node *head2_ptr)
    {
        if(head1_ptr == NULL)
            return head2_ptr;
        if(head2_ptr == NULL)
            return head1_ptr;
        
        Node *mergedHeadPtr = NULL, *mergedTailPtr = NULL;
        
        if(head1_ptr->data < head2_ptr->data) {
            mergedHeadPtr = head1_ptr;
            mergedTailPtr = mergedHeadPtr;
            head1_ptr = head1_ptr->next;
        }
        else {
            mergedHeadPtr = head2_ptr;
            mergedTailPtr = mergedHeadPtr;
            head2_ptr = head2_ptr->next;
        }
        
        while(head1_ptr != NULL && head2_ptr != NULL) {
            if(head1_ptr->data <= head2_ptr->data) {
                mergedTailPtr->next = head1_ptr;
                mergedTailPtr = mergedTailPtr->next;
                head1_ptr = head1_ptr->next;
            }
            else {
                mergedTailPtr->next = head2_ptr;
                mergedTailPtr = mergedTailPtr->next;
                head2_ptr = head2_ptr->next;
            }
        }
        
        if(head1_ptr == NULL)
            mergedTailPtr->next = head2_ptr;
        else
            mergedTailPtr->next = head1_ptr;
        
        return mergedHeadPtr;
    }
    
    
    void mergeSortLL(Node **headRef)
    {
        Node *head = *headRef;
        
        if(head == NULL or head->next == NULL)
            return;
        
        Node *first_partition_head = head;
        Node *second_partition_head = splitList(head);
        
        mergeSortLL(&first_partition_head);
        mergeSortLL(&second_partition_head);
        *headRef = mergeSortedLL(first_partition_head, second_partition_head);
    }
    
public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        mergeSortLL(&head);
        return head;
    }
};

/ { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends