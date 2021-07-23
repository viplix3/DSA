// https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int num_rotations)
    {
		if(head == NULL || num_rotations == 0)
			return head;

        Node *curr_head = head;
        Node *rotated_list_tail = head, *rotated_list_head = NULL;
		int linked_list_length = 1;
        
        // Making list circular, i.e. connecting last node with head
        while(curr_head->next != NULL) {
            curr_head = curr_head->next;
			linked_list_length += 1;
        }
        curr_head->next = head;

		num_rotations = num_rotations % linked_list_length;

        if(num_rotations == 0) {
            curr_head->next = NULL;
            return head;
        }

		// Getting the rotated linked list tail, the node next to it will be head
		for(int i=1; i < num_rotations; i++)
			rotated_list_tail = rotated_list_tail->next;
        
        // Now we just need to make next node as head and next of curr node as NULL
        rotated_list_head = rotated_list_tail->next;
        rotated_list_tail->next = NULL;
        
        return rotated_list_head;
    }
};

// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
  // } Driver Code Ends