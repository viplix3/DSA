// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
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
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
		if(head == NULL)
			return head;

        Node *curr = head;

		// Thow away list heads to avoid a lot of NULL checks
        Node *zero_list_dummy_head_ptr = new Node(0);
        Node *ones_list_dummy_head_ptr = new Node(1);
        Node *twos_list_dummy_head_ptr = new Node(2);

		Node *zero_list_tail_ptr = zero_list_dummy_head_ptr;
		Node *ones_list_tail_ptr = ones_list_dummy_head_ptr;
		Node *twos_list_tail_ptr = twos_list_dummy_head_ptr;

        while(curr != NULL) {
            if(curr->data == 0) {
				zero_list_tail_ptr->next = curr;
				zero_list_tail_ptr = zero_list_tail_ptr->next;
            }
            
            else if(curr->data == 1) {
				ones_list_tail_ptr->next = curr;
				ones_list_tail_ptr = ones_list_tail_ptr->next;
            }
            
            else {
				twos_list_tail_ptr->next = curr;
				twos_list_tail_ptr = twos_list_tail_ptr->next;
            }
            
            curr = curr->next;
        }

		if(ones_list_dummy_head_ptr->next != NULL) {
			zero_list_tail_ptr->next = ones_list_dummy_head_ptr->next;
			ones_list_tail_ptr->next = twos_list_dummy_head_ptr->next;
		}
		else
			zero_list_tail_ptr->next = twos_list_dummy_head_ptr->next;
        twos_list_tail_ptr->next = NULL;

		return zero_list_dummy_head_ptr->next;
    }
};

// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends