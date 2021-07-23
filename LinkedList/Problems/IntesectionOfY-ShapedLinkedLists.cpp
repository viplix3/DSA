// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1/

// { Driver Code Starts
#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
	Node *head1_ptr = head1, *head2_ptr = head2;
	int list1_length = 0, list2_length = 0;

	while(head1_ptr != NULL) {
		list1_length += 1;
		head1_ptr = head1_ptr->next;
	}

	while(head2_ptr != NULL) {
		list2_length += 1;
		head2_ptr = head2_ptr->next;
	}

	int len_diff = abs(list1_length - list2_length);
	Node *longer_list = list1_length >= list2_length ? head1 : head2;
	Node *smaller_list = list1_length < list2_length ? head1 : head2;

	for(int i=0; i<len_diff; i++)
		longer_list = longer_list->next;
	
	while(longer_list != NULL && smaller_list != NULL) {
		if(longer_list == smaller_list)
			return longer_list->data;

		longer_list = longer_list->next;
		smaller_list = smaller_list->next;
	}

	return -1;
}
