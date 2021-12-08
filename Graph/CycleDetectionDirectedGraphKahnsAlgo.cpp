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

bool checkForCycle(vector<int> adjacencyList[], int numVertices) {
	int inDegree[numVertices] = {0};
	queue<int> gnodes;
	int zeroInDegreeNodes = 0;

	for(int i=0; i<numVertices; i++)
		for(int connected_node : adjacencyList[i])
			inDegree[connected_node] += 1;
		
	for(int i=0; i<numVertices; i++)
		if(inDegree[i] == 0)
			gnodes.push(i);
		
	while(gnodes.empty() == false) {
		int curr = gnodes.front();
		gnodes.pop();
		zeroInDegreeNodes += 1;

		for(int connected_node : adjacencyList[curr]) {
			inDegree[connected_node] -= 1;
			if(inDegree[connected_node] == 0)
				gnodes.push(connected_node);
		}

	}

	return (zeroInDegreeNodes != numVertices);
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
