// https://practice.geeksforgeeks.org/problems/check-if-subtree/1/

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


 // } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
private:
    bool isIdentical(Node* root1, Node* root2) {
        if(root1 == NULL && root2 == NULL)
            return true;
        
        if(root1 == NULL || root2 == NULL)
            return false;
            
        bool data_check = (root1->data == root2->data);
        bool left_subtree_check, right_subtree_check;
        left_subtree_check = right_subtree_check = false;
        
        if(data_check) {
            left_subtree_check = isIdentical(root1->left, root2->left);
            right_subtree_check = isIdentical(root1->right, root2->right);
        }
        
        return (data_check && left_subtree_check && right_subtree_check);
    }
public:
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* superTree, Node* subTree) 
    {
        if(superTree != NULL) {
            return (
                    isIdentical(superTree, subTree) || 
                    isSubTree(superTree->left, subTree) ||
                    isSubTree(superTree->right, subTree)
                    );
        }
		return false;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Solution obj;
        Node *rootS = buildTree(strS);
        cout << obj.isSubTree(rootT, rootS) << "\n";

    }
    return 0;
}  // } Driver Code Ends