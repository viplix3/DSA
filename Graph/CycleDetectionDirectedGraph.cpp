#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjacency_list[], int vertexFrom, int vertexTo) {
	adjacency_list[vertexFrom].emplace_back(vertexTo);
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

bool DFS(vector<int> adjacencyList[], int sourceVertex, bool visited[], bool recursionStack[], int parent) {
	visited[sourceVertex] = true;
	recursionStack[sourceVertex] = true; // Current node is in the recursion call stack

	for(int connected_node : adjacencyList[sourceVertex]) {
		if(visited[connected_node] == false && DFS(adjacencyList, connected_node, visited, recursionStack, sourceVertex) == true)
				return true;
		// If the connected node of current source vertex is in the recusion call stack, the connecting edge is a back edge, i.e.
		// it is connecting current node to an already visited node in current connected component resulting in a cycle
		else if(recursionStack[connected_node] == true)
			return true;
	}
	recursionStack[sourceVertex] = false; // sourceVertex has gone out of recursion stack
	return false;
}

bool checkForCycle(vector<int> adjacencyList[], int numVertices) {
	bool visited[numVertices] = {false};
	bool recursionNodes[numVertices] = {false};

	for(int i=0; i<numVertices; i++) {
		if(visited[i] == false)
			if(DFS(adjacencyList, i, visited, recursionNodes, -1) == true)
				return true;
	}

	return false;
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

	cout << boolalpha << "Cycle in graph: " << checkForCycle(adjacencyList, numVertices) << endl;

	return 0;
}