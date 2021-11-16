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

vector<int> getShortestPath(vector<int> adjacencyList[], int sourceVertex, int numVertices) {
	vector<int> distFromSource(numVertices);
	fill(distFromSource.begin(), distFromSource.end(), INT_MAX);
	bool visited[numVertices] = {false};
	queue<pair<int, int>> gnodes; // first -> nodeNum, second -> dist. from source

	gnodes.push(make_pair(sourceVertex, 0)); // Dist. of source vertex to itself is always 0
	visited[sourceVertex] = true;

	while(gnodes.empty() == false) {
		auto curr = gnodes.front();
		gnodes.pop();

		int currNode = curr.first, currDist = curr.second;

		for(int connected_node : adjacencyList[currNode])
			if(visited[connected_node] == false) {
				visited[connected_node] = true;
				gnodes.push(make_pair(connected_node, currDist+1));
			}

		distFromSource[currNode] = currDist;
	}

	return distFromSource;
}

std::ostream& operator<<(std::ostream& outputStream, std::vector<int> outData) {
	cout << "vertex: distance from source\n";
	for(int i=0; i<outData.size(); i++)
		outputStream << i << ": " << outData[i] << std::endl;
	return outputStream;
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

	vector<int> pathDist = getShortestPath(adjacencyList, source, numVertices);
	cout << "Dist from source vertex " << source << "\n" << pathDist;
	cout << endl;

	return 0;
}