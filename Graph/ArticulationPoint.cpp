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

void articulationPointUtil(int sourceVertex, vector<int> adjacencyList[], bool visited[], int discoveryTime[],
							int lowestTime[], int parent[], bool articulationPointFlag[]) {

	static int currTime = 0;

	visited[sourceVertex] = true;
	int children = 0;
	discoveryTime[sourceVertex] = lowestTime[sourceVertex] = ++currTime;

	for(int connected_node : adjacencyList[sourceVertex]) {
		if(visited[connected_node] == false) {
			children += 1;
			parent[connected_node] = sourceVertex;
			articulationPointUtil(connected_node, adjacencyList, visited, discoveryTime, lowestTime,
									parent, articulationPointFlag);
			
			// Update lowest time of source vertex if there is a backedge from its children to its ancestors
			lowestTime[sourceVertex] = min(lowestTime[sourceVertex], lowestTime[connected_node]);

			if(parent[sourceVertex] == -1 && children > 1)
				articulationPointFlag[sourceVertex] = true; // source vertex is DFS root and articulation point
			if(parent[sourceVertex] != -1 && lowestTime[connected_node] >= discoveryTime[sourceVertex])
				articulationPointFlag[sourceVertex] = true; // source vertex is not DFS root, but is articulation point
		}
		else if(connected_node != parent[sourceVertex]) // this is a backedge
			lowestTime[sourceVertex] = min(lowestTime[sourceVertex], discoveryTime[connected_node]);
	}
}

vector<int> getArticulationPoints(vector<int> adjacencyList[], int numVertices) {
	bool visited[numVertices] = {false}, articulationPointFlag[numVertices] = {false};
	int discoveryTime[numVertices], lowestTime[numVertices], parent[numVertices];
	vector<int> articulationPoints;

	fill(parent, parent + numVertices, -1);

	for(int i=0; i<numVertices; i++)
		if(visited[i] == false)
			articulationPointUtil(i, adjacencyList, visited, discoveryTime, lowestTime,
									parent, articulationPointFlag);

	for(int i=0; i<numVertices; i++)
		if(articulationPointFlag[i])
			articulationPoints.emplace_back(i);
		
	return articulationPoints;
}

std::ostream& operator<<(std::ostream& outputStream, std::vector<int> outData) {
	for(int i=0; i<outData.size(); i++)
		outputStream << outData[i] << " ";
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

	vector<int> articulationPoints = getArticulationPoints(adjacencyList, numVertices);
	if(articulationPoints.size() == 0)
		cout << "No articulation points found in the graph";
	else
		cout << "Articulation points in graph: " << articulationPoints;

	cout << endl;

	return 0;
}