// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1/

// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

Node* constructTree(int inOrder[], int postOrder[], int startIdx, int endIdx, int& currNodeIdxPostOrder)
{
    if(startIdx > endIdx)
        return NULL;
    
    int currNodeVal = postOrder[currNodeIdxPostOrder];
    currNodeIdxPostOrder -= 1;
    
    int currNodeIdxInOrder;
    
    for(int i=startIdx; i <= endIdx; i++)
        if(currNodeVal == inOrder[i]) {
            currNodeIdxInOrder = i;
			break;
		}
    
    Node *currNode = new Node(currNodeVal);
    currNode->right = constructTree(inOrder, postOrder, currNodeIdxInOrder+1, endIdx, currNodeIdxPostOrder);
    currNode->left = constructTree(inOrder, postOrder, startIdx, currNodeIdxInOrder-1, currNodeIdxPostOrder);
    
    return currNode;
}

Node* buildTree(int in[], int post[], int n) {
    int currNodeIdx = 0;
    int currNodeIdxPostOrder = n-1;
    
    Node *root = constructTree(in, post, currNodeIdx, n-1, currNodeIdxPostOrder);
    return root;
}