// https://practice.geeksforgeeks.org/problems/convert-level-order-traversal-to-bst/1/

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}// } Driver Code Ends


//User function Template for C++


//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int arrSize)
{
	/*
		For each node we are saving following mentioned things in the queue
			1. Minimum value that can be a part of left sub-tree for current node
			2. Current node
			3. Maximum value that can be a part of right sub-tree for the current node
	*/
    queue<tuple<int, Node*, int>> treeLevelNodes;
    Node* root = new Node(arr[0]);
    int arrItr = 1;
    
    treeLevelNodes.push(make_tuple(INT_MIN, root, INT_MAX));
    
    while(arrItr < arrSize) {
        auto currNodeDetails = treeLevelNodes.front();
		int currMinVal = get<0>(currNodeDetails);
		Node *currNode = get<1>(currNodeDetails);
		int currMaxVal = get<2>(currNodeDetails);
        treeLevelNodes.pop();

		// For current array value to be a part of left sub-tree of current node,
		// its value should be betweeen [minimum possible value for left sub-tree, current node value)
		if(currMinVal < arr[arrItr] && arr[arrItr] < currNode->data) {
			Node *leftChild = new Node(arr[arrItr]);
			currNode->left = leftChild;
			arrItr += 1;
			treeLevelNodes.push(make_tuple(currMinVal, leftChild, currNode->data));
		}

		// For current array value to be a part of right sub-tree of currnt node,
		// its values should be between (current node value, maximum possible value for right sub-tree]
		if((arrItr < arrSize) && (currNode->data < arr[arrItr] && arr[arrItr] < currMaxVal)) {
			Node *rightChild = new Node(arr[arrItr]);
			currNode->right = rightChild;
			arrItr += 1;
			treeLevelNodes.push(make_tuple(currNode->data, rightChild, currMaxVal));
		}
    }
    
    return root;
    
}
