// https://practice.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1/

// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/


//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int K)
{
    if(head == NULL)
        return NULL;
 
    if(K > num)
        return head;

	if((2*K - 1) == num)
		return head;
        
    int begin_idx = K;
    int end_idx = num - K+1;
    
	// These will point to the nodes to be swapped
	Node *node_from_right = head, *node_from_left = head; 
	// Nodes before the nodes that are to be swapped
	Node *prev_right = NULL, *prev_left = NULL;

	for(int i=1; i<begin_idx; i++) {
		prev_right = node_from_right;
		node_from_right = node_from_right->next;
	}

	for(int i=1; i<end_idx; i++) {
		prev_left = node_from_left;
		node_from_left = node_from_left->next;
	}

	if(prev_left != NULL)
		prev_left->next = node_from_right;
	if(prev_right != NULL)
		prev_right->next = node_from_left;

	// Swapping nodes
	Node *swap_node = node_from_left->next;
	node_from_left->next = node_from_right->next;
	node_from_right->next = swap_node;


	if(K == 1)
		head = node_from_left;

	if(K == num)
		head = node_from_right;

	return head;
}