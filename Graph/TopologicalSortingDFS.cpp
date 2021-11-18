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

void DFS(vector<int> adjacencyList[], int sourceVertex, bool visited[], stack<int>& completedNodes) {
	visited[sourceVertex] = true;

	for(int connected_node : adjacencyList[sourceVertex])
		if(visited[connected_node] == false) {
			DFS(adjacencyList, connected_node, visited, completedNodes);
		}
	
	completedNodes.push(sourceVertex);
}

void topologicalSorting(vector<int> adjacencyList[], int numVertices) {
	bool visited[numVertices] = {false};
	stack<int> completedNodes;

	for(int i=0; i<numVertices; i++) {
		if(visited[i] == false) {
			DFS(adjacencyList, i, visited, completedNodes);
		}
	}

	while(completedNodes.empty() == false) {
		cout << completedNodes.top() << " ";
		completedNodes.pop();
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
