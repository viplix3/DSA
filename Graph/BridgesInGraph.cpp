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

void findBridges(int sourceVertex, vector<int> adjacencyList[], int parent[], bool visited[], int discoveryTime[],
					int lowestTime[], vector<pair<int, int>>& bridges) {
	static int currTime = 0;

	visited[sourceVertex] = true;
	discoveryTime[sourceVertex] = lowestTime[sourceVertex] = ++currTime;

	for(int connected_node : adjacencyList[sourceVertex]) {
		if(visited[connected_node] == false) {
			parent[connected_node] = sourceVertex;

			findBridges(connected_node, adjacencyList, parent, visited, discoveryTime, lowestTime, bridges);
			lowestTime[sourceVertex] = min(lowestTime[sourceVertex], lowestTime[connected_node]);

			// None of the ancestors of source vertex can be reached by the current connected_node
			if(lowestTime[connected_node] > discoveryTime[sourceVertex])
				bridges.emplace_back(make_pair(sourceVertex, connected_node));
		}
		else if(connected_node != parent[sourceVertex])
			lowestTime[sourceVertex] = min(lowestTime[sourceVertex], discoveryTime[connected_node]);

	}
}

vector<pair<int, int>> getBridges(vector<int> adjacencyList[], int numVertices) {
	bool visited[numVertices] = {false};
	int parent[numVertices], discoveryTime[numVertices], lowestTime[numVertices];
	vector<pair<int, int>> bridges;

	fill(parent, parent + numVertices, -1);

	for(int i=0; i<numVertices; i++)
		if(visited[i] == false)
			findBridges(i, adjacencyList, parent, visited, discoveryTime, lowestTime, bridges);
	
	return bridges;
}

std::ostream& operator<<(std::ostream& outputStream, std::vector<std::pair<int, int>> outData) {
	for(int i=0; i<outData.size(); i++)
		outputStream << outData[i].first << "----" << outData[i].second << std::endl;
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

	cout << "\nAdjacency List\n";
	printAdjacencyList(adjacencyList, numVertices);

	vector<pair<int, int>> bridges = getBridges(adjacencyList, numVertices);
	if(bridges.size() == 0)
		cout << "No bridges found in the graph";
	else
		cout << "Bridges in graph\n" << bridges;

	cout << endl;

	return 0;
}
