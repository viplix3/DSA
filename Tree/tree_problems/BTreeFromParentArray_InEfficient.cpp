// https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1/

#include <bits/stdc++.h>
using namespace std;

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

void sort_and_print(vector <int> &v)
{
    sort( v.begin() , v.end() );
    for( int i=0 ; i<v.size() ; i++ )
        cout<< v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root)
{
    vector <int> v;
    queue <Node*> q;
    
    q.push(root);
    
    Node* next_row = NULL;
    
    while(!q.empty())
    {
        Node* n = q.front();
        q.pop();
        
        if(n==next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }
        
        v.push_back(n->data);
        
        if(n->left)
        {
            q.push(n->left);
            if(next_row == NULL) next_row = n->left;
        }
        
        if(n->right)
        {
            q.push(n->right);
            if(next_row == NULL) next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/


 // } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int N)
    {
		unordered_map<int, pair<Node*, Node*>> hash_map;
		Node *nullNode = NULL;

		for(int i=0; i<N; i++) {
			if(hash_map.find(parent[i]) != hash_map.end())
				hash_map[parent[i]].second = new Node(i);
			else
				hash_map[parent[i]] = make_pair(new Node(i), nullNode);
		}

		Node *root = hash_map[-1].first;
		hash_map.erase(-1);
		queue<Node*> treeLevelNodes;
		treeLevelNodes.push(root);

		while(treeLevelNodes.empty() == false && hash_map.size() != 0) {
			Node *curr = treeLevelNodes.front();
			treeLevelNodes.pop();

			if(curr != NULL && hash_map.find(curr->data) != hash_map.end()) {
				curr->left = hash_map[curr->data].first;
				curr->right = hash_map[curr->data].second;

				hash_map.erase(curr->data);
				treeLevelNodes.push(curr->left);
				treeLevelNodes.push(curr->right);
			}
		}
		return root;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        int a[n];
        for( int i=0 ; i<n ; i++ )
            cin>> a[i];
            
        Solution ob;
        
        Node *res = ob.createTree(a,n);
        
        printLevelOrder(res);
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends