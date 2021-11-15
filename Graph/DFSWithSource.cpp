#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjacency_list[], int vertex1, int vertex2) {
	adjacency_list[vertex1].emplace_back(vertex2);
	adjacency_list[vertex2].emplace_back(vertex1);
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

void DFS(vector<int> adjacencyList[], int sourceVertex, bool visited[]) {
	cout << sourceVertex << " ";
	visited[sourceVertex] = true;

	for(int connected_node : adjacencyList[sourceVertex])
		if(visited[connected_node] == false)
			DFS(adjacencyList, connected_node, visited);
}

void printDFS(vector<int> adjacencyList[], int source, int numVertices) {
	bool visited[numVertices] = {false};
	DFS(adjacencyList, source, visited);
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
		cout << "Enter vertices for edge: ";
		cin >> vertex1 >> vertex2;
		addEdge(adjacencyList, vertex1, vertex2);
	}

	int source;
	cout << "Enter source vertex: ";
	cin >> source;

	cout << "\nAdjacency List\n";
	printAdjacencyList(adjacencyList, numVertices);

	cout << "DFS: ";
	printDFS(adjacencyList, source, numVertices);
	cout << endl;

	return 0;
}