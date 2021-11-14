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

void BFS(vector<int> adjacencyList[], int numVertices, int sourceVertex, bool visited[]) {
	queue<int> gnodes;
	gnodes.push(sourceVertex);
	visited[sourceVertex] = true;

	while(gnodes.empty() == false) {
		int curr = gnodes.front();
		gnodes.pop();

		for(int connected_node : adjacencyList[curr])
			if(visited[connected_node] == false) {
				visited[connected_node] = true;
				gnodes.push(connected_node);
			}
	}
}

int countConnectedComponents(vector<int> adjacencyList[], int numVertices) {
	bool visited[numVertices] = {false};
	int numConnectedComponents = 0;

	for(int i=0; i<numVertices; i++)
		if(visited[i] == false) { // Call BFS if the current node is not visited. 
			// BFS will only be called once per one connected component
			// Hence, number of BFS calls will be number of connected components
			numConnectedComponents += 1;
			BFS(adjacencyList, numVertices, i, visited);
		}

	return numConnectedComponents;
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

	cout << "\nAdjacency List\n";
	printAdjacencyList(adjacencyList, numVertices);
	cout << "\nNumber of connected components: " << countConnectedComponents(adjacencyList, numVertices) << endl;

	return 0;
}