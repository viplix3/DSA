// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1/

// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
	private:
	struct Node* reverse(struct Node* head)
	{
		if(head == NULL || head->next == NULL)
			return head;
		
		struct Node *curr = head, *prev = NULL;

		while(curr != NULL) {
			struct Node *next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}

    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
		struct Node *sum_list_tail = NULL, *sum_list_head = NULL;
        struct Node *first_rev = NULL, *second_rev = NULL;
        int carry = 0;

        first_rev = reverse(first);
		second_rev = reverse(second);

        while(first_rev != NULL && second_rev != NULL) {
            int curr_sum = first_rev->data + second_rev->data + carry;
            carry = curr_sum / 10;
            curr_sum = curr_sum % 10;

            if(sum_list_head == NULL) {
                sum_list_head = new Node(curr_sum);
                sum_list_tail = sum_list_head;
            }
            else {
                struct Node *sum_node = new Node(curr_sum);
                sum_list_head->next = sum_node;
                sum_list_head = sum_list_head->next;
            }

            first_rev = first_rev->next;
            second_rev = second_rev->next;
        }

        while(first_rev != NULL)
        {
            int curr_sum = first_rev->data + carry;
            carry = curr_sum / 10;
            curr_sum = curr_sum % 10;

            struct Node *sum_node = new Node(curr_sum);
            sum_list_head->next = sum_node;
            sum_list_head = sum_list_head->next;
            first_rev = first_rev->next;
        }
        
        while(second_rev != NULL)
        {
            int curr_sum = second_rev->data + carry;
            carry = curr_sum / 10;
            curr_sum = curr_sum % 10;

            struct Node *sum_node = new Node(curr_sum);
            sum_list_head->next = sum_node;
            sum_list_head = sum_list_head->next;
            second_rev = second_rev->next;
        }
    
        if(carry)
            sum_list_head->next = new Node(carry);

        sum_list_head = reverse(sum_list_tail);
        return sum_list_head;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends