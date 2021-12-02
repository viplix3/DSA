// https://practice.geeksforgeeks.org/problems/level-of-nodes-1587115620/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
public:
	//Function to find the level of node X.
	int nodeLevel(int numVertices, vector<int> adjacencyList[], int key) 
	{
		bool visited[numVertices] = {false};
		int keyNodeLevel = -1;
		queue<pair<int, int>> levelNodes;

		levelNodes.push(make_pair(0, 0)); // level, graph_node
		visited[0] = true;

		while(levelNodes.empty() == false) {
			pair<int, int> curr = levelNodes.front();
			levelNodes.pop();
			
			if(curr.second == key) {
				keyNodeLevel = curr.first;
				break;
			}

			for(int connected_node : adjacencyList[curr.second])
				if(visited[connected_node] == false) {
					visited[connected_node] = true;
					levelNodes.push(make_pair(curr.first+1, connected_node));
				}

		}

		return keyNodeLevel;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends