
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
    const int NULLPTR = -1;

    void inOrder(Node* root, vector<int>& traversal) {
        
        if(root == NULL) {
            traversal.emplace_back(NULLPTR);
            return;
        }
        
        inOrder(root->left, traversal);
        traversal.emplace_back(root->data);
        inOrder(root->right, traversal);
    }
    
    void preOrder(Node* root, vector<int>& traversal) {
        if(root == NULL) {
            traversal.emplace_back(NULLPTR);
            return;
        }
        
        traversal.emplace_back(root->data);
        preOrder(root->left, traversal);
        preOrder(root->right, traversal);
    }
    
    bool checkSubsets(vector<int>& set1, vector<int>& set2) {
        string set1Str = "";
        string set2Str = "";
        
        for(int i=0; i<set1.size(); i++)
            set1Str += to_string(set1[i]);
        
        for(int i=0; i<set2.size(); i++)
            set2Str += to_string(set2[i]);
        
        if(set1Str.find(set2Str) != string::npos)
            return true;
        else
            return false;
    }
    
public:
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* superTree, Node* subTree) 
    {
        vector<int> preOrder_superTree, inOrder_superTree;
        vector<int> preOrder_subTree, inOrder_subTree;
        
        // Get preOrder and inOrder traversal of both super and sub tree
        preOrder(superTree, preOrder_superTree);
        preOrder(subTree, preOrder_subTree);
        inOrder(superTree, inOrder_superTree);
        inOrder(subTree, inOrder_subTree);
        
        // Check if preOrder and inOrder traversals of sub-tree
        // is a subset of preOrder and inOrder traversals of super-tree
        bool preOrderCheck, inOrderCheck;
        preOrderCheck = checkSubsets(preOrder_superTree, preOrder_subTree);
        inOrderCheck = checkSubsets(inOrder_superTree, inOrder_subTree);
        
        return (preOrderCheck && inOrderCheck);
        
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