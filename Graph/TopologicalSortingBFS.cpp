#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjacencyList[], int vertexFrom, int vertexTo) {
	adjacencyList[vertexFrom].emplace_back(vertexTo);
}

void printAdjacencyList(vector<int> adjacencyList[], int numVertices) {
	for(int i = 0; i < numVertices; i++) {
		cout << i << ": ";
		for(auto connected_node : adjacencyList[i])
			cout << connected_node << " ";
		cout << "\n";
	}
	cout << endl;
}

void BFS(vector<int> adjacencyList[], int sourceVertex, int numVertices, bool visited[], int inDegree[]) {
	queue<int> gnodes;

	gnodes.push(sourceVertex);
	visited[sourceVertex] = true;

	while(gnodes.empty() == false) {
		int curr = gnodes.front();
		gnodes.pop();

		if(inDegree[curr] == 0)
			cout << curr << " ";
		
		for(int connected_node : adjacencyList[curr]) {
			if(visited[connected_node] == false) {
				inDegree[connected_node] -= 1;

				if(inDegree[connected_node] == 0) {
					visited[connected_node] = true;
					gnodes.push(connected_node);
				}
			}
		}
	}
}

void topologicalSorting(vector<int> adjacencyList[], int numVertices) {
	int inDegree[numVertices] = {0};
	bool visited[numVertices] = {false};

	// inDegree of each node, O(V*E) operation
	for(int i=0; i<numVertices; i++)
		for(int connected_node : adjacencyList[i])
			inDegree[connected_node] += 1;

	for(int i=0; i<numVertices; i++) {
		if(visited[i] == false || inDegree[i] > 0)
			BFS(adjacencyList, i, numVertices, visited, inDegree);
	}
}

int main() {
	int numVertices, numEdges;
	cout << "Enter number of vertices: ";
	cin >> numVertices;

	cout << "Enter number of edges: ";
	cin >> numEdges;

	vector<int> adjacencyList[numVertices];
	int vertex1, vertex2;

	while(numEdges--) {
		cout << "Enter FROM and TO vertices for edge: ";
		cin >> vertex1 >> vertex2;
		addEdge(adjacencyList, vertex1, vertex2);
	}

	cout << "\nAdjacency List\n";
	printAdjacencyList(adjacencyList, numVertices);

	cout << "Topological sorting of graph: \n";
	topologicalSorting(adjacencyList, numVertices);
	cout << endl;

	return 0;
}