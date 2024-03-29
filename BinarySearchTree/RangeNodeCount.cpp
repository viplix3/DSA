// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


int getCount(Node *root, int low, int high);
int main()
{
	
	int t;
	scanf("%d ", &t);
	while (t--)
	{
		string s;
		getline(cin >> ws, s);
		int l, r;
		cin >> l >> r;
		
		Node* root = buildTree(s);
		cout << getCount(root, l, r) << endl;
		
	}
	return 1;
}
// } Driver Code Ends


//Function to count number of nodes in BST that lie in the given range.
int getCountComplex(Node *root, int lowerBound, int upperBound)
{
    if(root == NULL)
        return 0;
    
    bool root_in_range = ((lowerBound <= root->data) && (root->data <= upperBound));
    int rangeNodeCount = 0;
    /*
        Left sub-tree recursion will be done only when following conditions are met
            1. Root is in the search range and root is not the smallest element of the range
                In such a case, we can find more elements lying in range in the left sub-tree
            2. Root is greater then the upper bound of range
                We need to go to left to get smaller elements that might fit in the range
    */
    if((root_in_range && root->data > lowerBound) || (root->data > upperBound))
        rangeNodeCount = getCount(root->left, lowerBound, upperBound);
    if(root_in_range || root->data < lowerBound)
        rangeNodeCount += getCount(root->right, lowerBound, upperBound);
    
    return (root_in_range + rangeNodeCount);
}

//Function to count number of nodes in BST that lie in the given range.
int getCount(Node* root, int low, int high)
{
	if (!root) 
	    return 0;

	//if data at current node is equal to lower and upper range, we return 1.
	if (root->data == high && root->data == low)
		return 1;

	//if data at current node is within range then we include it in count 
	//and call function recursively for its left and right children.
	if (root->data <= high && root->data >= low)
		return 1+getCount(root->left,low,high)+getCount(root->right,low,high);

	//else if data at current node is smaller than lower range then
	//we call function recursively only for right child.
	else if (root->data < low)
		return getCount(root->right, low, high);

	//else we call function recursively only for left child.
	else return getCount(root->left, low, high);
}