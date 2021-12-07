// https://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
private:
	int NIL = -1;
private:
	void tarjansDFSUtil(int sourceVertex, vector<int> adjacencyList[], int discoveryTime[], int lowestTime[],
							stack<int>& recursionStack, bool stackMemberFlag[], vector<vector<int>>& SCC) {
		static int currTime = 0;

		discoveryTime[sourceVertex] = lowestTime[sourceVertex] = ++currTime;
		recursionStack.push(sourceVertex);
		stackMemberFlag[sourceVertex] = true;

		for(int connectedNode : adjacencyList[sourceVertex]) {
			if(discoveryTime[connectedNode] == NIL) {
				tarjansDFSUtil(connectedNode, adjacencyList, discoveryTime, lowestTime, recursionStack, stackMemberFlag, SCC);
				lowestTime[sourceVertex] = min(lowestTime[sourceVertex], lowestTime[connectedNode]);
			}
			else if(stackMemberFlag[connectedNode] == true) // Back-edge, for cross edge, this would have been false
				lowestTime[sourceVertex] = min(lowestTime[sourceVertex], discoveryTime[connectedNode]);
		}

		if(discoveryTime[sourceVertex] == lowestTime[sourceVertex]) { // SSC source
			vector<int> currSCC;
			while(recursionStack.top() != sourceVertex) {
				currSCC.emplace_back(recursionStack.top());
				stackMemberFlag[recursionStack.top()] = false;
				recursionStack.pop();
			}

			currSCC.emplace_back(recursionStack.top());
			stackMemberFlag[recursionStack.top()] = false;
			recursionStack.pop();

            sort(currSCC.begin(), currSCC.end());
			SCC.emplace_back(currSCC);
		}

	}

public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int numVertices, vector<int> adjacencyList[])
    {
		vector<vector<int>> SCC;
		bool stackMemberFlag[numVertices] = {false};
		int discoveryTime[numVertices], lowestTime[numVertices];
		stack<int> recursionStack;

		fill(discoveryTime, discoveryTime + numVertices, NIL);
		fill(lowestTime, lowestTime + numVertices, NIL);

		for(int i=0; i<numVertices; i++)
			if(discoveryTime[i] == NIL)
				tarjansDFSUtil(i, adjacencyList, discoveryTime, lowestTime, recursionStack, stackMemberFlag, SCC);
		
		sort(SCC.begin(), SCC.end());
		return SCC;
    }
};
// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends