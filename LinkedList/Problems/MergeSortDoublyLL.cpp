// https://practice.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


 // } Driver Code Ends
/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */
struct Node* DLLsortedMerge(struct Node *first_ptr, struct Node *second_ptr)
{
    if(first_ptr == NULL && second_ptr == NULL)
        return NULL;
    if(first_ptr == NULL)
        return second_ptr; // Only 2nd half has elements
    if(second_ptr == NULL)
        return first_ptr; // Only first half has elements
    
    struct Node *merged_head = NULL, *merged_tail = NULL;
    
    // Setting head to the lower value
    if(first_ptr->data < second_ptr->data) {
        merged_head = first_ptr;
        merged_tail = merged_head;
        first_ptr = first_ptr->next;
    }
    else {
        merged_head = second_ptr;
        merged_tail = merged_head;
        second_ptr = second_ptr->next;
    }
    
    while(first_ptr != NULL && second_ptr != NULL) {
        if(first_ptr->data < second_ptr->data) {
            merged_tail->next = first_ptr;
            merged_tail->next->prev = merged_tail;
            merged_tail = merged_tail->next;
            first_ptr = first_ptr->next;
        }
        else {
            merged_tail->next = second_ptr;
            merged_tail->next->prev = merged_tail;
            merged_tail = merged_tail->next;
            second_ptr = second_ptr->next;   
        }
    }
    
    if(first_ptr == NULL) {
        merged_tail->next = second_ptr;
        merged_tail->next->prev = merged_tail;
    }
    else {
        merged_tail->next = first_ptr;
        merged_tail->next->prev = merged_tail;
    }
    return merged_head;
}

struct Node* getMiddle(struct Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    
    struct Node *slow_ptr = head, *fast_ptr = head;
    while(fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    
    // slow_ptr will be head of second half
    struct Node *partition_node = slow_ptr;
	partition_node->prev->next = NULL; // From head to slow_ptr->prev will be first half for merge sort
	partition_node->prev = NULL;

    return partition_node; 
}

void mergeSortDLL(struct Node **headRef)
{
    struct Node *init = *headRef; // This is head of first half

	if(init == NULL || init->next == NULL)
		return;

    struct Node *middle = getMiddle(init); // This will be the middle element and head of second half
    
    mergeSortDLL(&init); // Apply merge sort in first half
    mergeSortDLL(&middle); // Apply merge sort in second half
    *headRef = DLLsortedMerge(init, middle); // merge sorted DLLS
}

//Function to sort the given doubly linked list using Merge Sort.
struct Node *sortDoubly(struct Node *head)
{
	mergeSortDLL(&head);
	return head;
}


// { Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}


// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}
  // } Driver Code Ends