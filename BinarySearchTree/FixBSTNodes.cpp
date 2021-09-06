// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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
    Node* root = new Node(stoi(ip[0]));

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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isBST(Node* n, int lower, int upper)
{
    if (!n) return true;
    if ( n->data <= lower || n->data >= upper ) return false;
    return (  isBST( n->left, lower, n->data )  &&  isBST( n->right, n->data, upper )  );
}

bool compare( Node* a, Node* b, vector<pair<int, int>> &mismatch )
{
    if ( !a && !b ) return true;
    if ( !a || !b ) return false;

    if ( a->data != b->data )
        mismatch.push_back( pair<int, int> (a->data, b->data) );

    return ( compare( a->left, b->left, mismatch ) && compare( a->right, b->right, mismatch ) );
}


 // } Driver Code Ends
/*
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
private:
    void getSwapNodes(Node* root, Node* &prev, Node* &node1, Node* &node2) {
        if(root == NULL)
            return;
        
        getSwapNodes(root->left, prev, node1, node2);
        
        if(prev != NULL && root->data < prev->data) {
            if(node1 == NULL)
                node1 = prev;
            node2 = root;
        }
        prev = root;
        
        getSwapNodes(root->right, prev, node1, node2);
    }
    
    Node* findParent(Node* root, Node* child) {
        if(root == NULL || child == NULL)
            return NULL;

		Node* parent = NULL;

		while(root != NULL) {
			if(root->data < child->data) {
				root = root->right;
				parent = root;
			}
			else if(root->data > child->data) {
				root = root->left;
				parent = root;
			}
			else
				break;
		}

		if(parent == NULL)
			return root;
        return parent;
    }

	void swap_nodes(Node* &root, Node* node1, Node* node2) {
        Node* node1_parent = findParent(root, node1);
        Node* node2_parent = findParent(root, node2);

		Node* node1_left = node1->left;
		Node* node1_right = node1->right;

		// Swap children
		node1->left = node2->left;
		node1->right = node2->right;
		
		node2->left = node1_left;
		node2->right = node1_right;

		// If one of the nodes are root
		if(node1_parent == root)
			root = node2_parent;
		else if(node2_parent == root)
			root = node2_parent;
		else { // If both nodes are intermediate
			if(node1_parent->left == node1)
				node1_parent->left = node2;
			else
				node1_parent->right = node2;
			
			if(node2_parent->left == node2)
				node2_parent->left = node2;
			else
				node2_parent->right = node2;
		}
	}
    
public:
    void correctBST( struct Node* root )
    {
        Node *prev = NULL;
        Node *swap_node1 = NULL, *swap_node2 = NULL;
        
        getSwapNodes(root, prev, swap_node1, swap_node2);
        
        swap_nodes(root, swap_node1, swap_node2);
    }
    
    
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        string s;
        getline(cin, s);

        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);

        Solution ob;
        ob.correctBST(root);

        // check 1: is tree now a BST
        if ( ! isBST(root, INT_MIN, INT_MAX) )
        {
            cout << "0\n";
            continue;
        }

        // check 2: comparing with duplicate tree

        vector<pair<int, int>> mismatch;
        // a vector to store data of mismatching nodes

        if ( ! compare( root, duplicate, mismatch) )
        {
            // false output from this function indicates change in structure of tree
            cout << "0\n";
            continue;
        }

        // finally, analysing the mismatching nodes
        if ( mismatch.size() != 2 || mismatch[0].first != mismatch[1].second || mismatch[0].second != mismatch[1].first )
            cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}
  // } Driver Code Ends