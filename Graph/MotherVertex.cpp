// https://practice.geeksforgeeks.org/problems/mother-vertex/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
private:
    void DFS(int sourceVertex, vector<int> adjacencyList[], bool visited[]) {
        visited[sourceVertex] = true;
        
        for(int connected_node : adjacencyList[sourceVertex])
            if(visited[connected_node] == false)
                DFS(connected_node, adjacencyList, visited);
    }
    
public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    bool visited[V] = {false};
	    // Will store the last source vertex of DFS which helped in visiting all of the graph
	    // As all the previous source vertex couldn't visit all the nodes of the graph, last DFS source
	    // is the most apt candidate for mother vertex
	    int lastSourceVertex = -1;
	    
	    for(int i=0; i<V; i++)
	        if(visited[i] == false) {
	            DFS(i, adj, visited);
	            lastSourceVertex = i;
	        }
	        
	    // If we do a DFS with the mother vertex candidate and we visit all the grpah nodes, it is the mother vertex
	    fill(visited, visited + V, false); // Reset visited to false
	    DFS(lastSourceVertex, adj, visited); // DFS using candidate node
	    
	    // Checking if all the nodes are visited;
	    for(int i=0; i<V; i++)
	        if(!visited[i])
	            return -1;
	            
	    return lastSourceVertex;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends