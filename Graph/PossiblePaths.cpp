// https://practice.geeksforgeeks.org/problems/possible-paths-between-2-vertices-1587115620/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
private:
    void DFS(int sourceVertex, vector<int> adjacencyList[], int destinationVertex, int& numPaths) {
                    
        if(sourceVertex == destinationVertex) {
            numPaths += 1;
            return;
        }
        
        for(int connected_node : adjacencyList[sourceVertex]) 
            DFS(connected_node, adjacencyList, destinationVertex, numPaths);
            
    }

public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        int numPaths = 0;
		DFS(source, adj, destination, numPaths);
        return numPaths;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends