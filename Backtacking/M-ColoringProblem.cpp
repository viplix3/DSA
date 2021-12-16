// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[101][101], vector<int> vertexColors, int currVertex, int colorId) {

	for(int i = 0; i < 101; i++)
		if(graph[currVertex][i] && vertexColors[i] == colorId)
			return false;
	
	return true;
}

bool assignColors(bool graph[101][101], vector<int> vertexColors, int currVertex, int numColors) {
	int numVertices = vertexColors.size();
	constexpr int NOCOLOR = -1;

	if(currVertex >= numVertices)
		return true;
	
	for(int colorId = 0; colorId < numColors; colorId++) {
		if(isSafe(graph, vertexColors, currVertex, colorId)) {
			vertexColors[currVertex] = colorId;

			if(assignColors(graph, vertexColors, currVertex+1, numColors))
				return true;

			vertexColors[currVertex] = NOCOLOR;
		}
	}

	return false;
}

bool graphColoring(bool graph[101][101], int m, int V) {
	vector<int> vertexColors(V, -1);
	bool isSolvable = assignColors(graph, vertexColors, 0, m);
	return isSolvable;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends