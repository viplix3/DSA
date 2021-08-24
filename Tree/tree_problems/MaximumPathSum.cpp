// https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
// User Fuction template for C++

class Solution {
private:
	int getSum(Node* root, int& max_sum) {
		if(root == NULL)
			return 0;

		int left_sum = getSum(root->left, max_sum);
		int right_sum = getSum(root->right, max_sum);
		
		int left_subtree_sum = left_sum + root->data;
		int right_subtree_sum = root->data + right_sum;
		int full_subtree_sum = left_sum + root->data + right_sum;

		// This will be max sub for our current sub-tree
		max_sum = max({root->data, left_subtree_sum, right_subtree_sum, full_subtree_sum, max_sum});

		// When returning sum to the parent, we would consider only one of the left or right sub-tree
		return max({root->data, left_subtree_sum, right_subtree_sum, 0});
	}
public:
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
		int max_sum = INT_MIN;
		getSum(root, max_sum);
		return max_sum;
    }
};

// { Driver Code Starts.


int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        cout << ob.findMaxSum(root) << "\n";

    }


    return 0;
}  // } Driver Code Ends