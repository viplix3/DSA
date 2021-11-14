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

void printBFS(vector<int> adjacencyList[], int numVertices, int sourceVertex) {
	bool visited[numVertices] = {false};
	queue<int> gnodes;

	gnodes.push(sourceVertex);
	visited[sourceVertex] = true;

	while(gnodes.empty() == false) {
		int currNode = gnodes.front();
		gnodes.pop();

		cout << currNode << " ";

		for(auto connected_node : adjacencyList[currNode]) {
			if(visited[connected_node] == false) {
				visited[connected_node] = true;
				gnodes.push(connected_node);
			}
		}
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
		cout << "Enter vertices for edge: ";
		cin >> vertex1 >> vertex2;
		addEdge(adjacencyList, vertex1, vertex2);
	}

	printAdjacencyList(adjacencyList, numVertices);

	int sourceVertex;
	cout << "Enter source vertex for BFS: ";
	cin >> sourceVertex;
	printBFS(adjacencyList, numVertices, sourceVertex);
	cout << endl;

	return 0;
}