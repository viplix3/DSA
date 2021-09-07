// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

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

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> mergedInOrder;

		stack<Node*> nodesBST1, nodesBST2;

		// Merged traversal
		while((root1 != NULL || nodesBST1.empty() == false) &&
				(root2 != NULL || nodesBST2.empty() == false)) {
			
			while(root1 != NULL) {
				nodesBST1.push(root1);
				root1 = root1->left;
			}

			while(root2 != NULL) {
				nodesBST2.push(root2);
				root2 = root2->left;
			}

			root1 = nodesBST1.top();
			root2 = nodesBST2.top();

			if(root1->data < root2->data) {
				mergedInOrder.push_back(root1->data);
				nodesBST1.pop();
				root1 = root1->right;
				root2 = NULL;
			}
			else {
				mergedInOrder.push_back(root2->data);
				nodesBST2.pop();
				root1 = NULL;
				root2 = root2->right;
			}
		}

		// Remaining nodes traversal
		while(root1 != NULL || nodesBST1.empty() == false) {
			while(root1 != NULL) {
				nodesBST1.push(root1);
				root1 = root1->left;
			}
			root1 = nodesBST1.top();
			nodesBST1.pop();
			mergedInOrder.push_back(root1->data);
			root1 = root1->right;
		}

		while(root2 != NULL || nodesBST2.empty() == false) {
			while(root2 != NULL) {
				nodesBST2.push(root2);
				root2 = root2->left;
			}
			root2 = nodesBST2.top();
			nodesBST2.pop();
			mergedInOrder.push_back(root2->data);
			root2 = root2->right;
		}

		return mergedInOrder;
    }
};

// { Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}  // } Driver Code Ends