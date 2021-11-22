#include <bits/stdc++.h>
using namespace std;

class AdjacencyListNode {
private:
	int vertex, edgeWeight;

public:
	AdjacencyListNode(int v, int w)
		: vertex(v), edgeWeight(w)
	{}

	int getVertex() {
		return vertex;
	}

	int getEdgeWeight() {
		return edgeWeight;
	}
};

class Graph {
private:
	int numVertices;
	std::list<AdjacencyListNode> *adjacencyList;

	std::vector<int> topologicalSorting() {
		int inDegree[numVertices] = {0};

		for (int i = 0; i < numVertices; i++)
			for(AdjacencyListNode connected_node : adjacencyList[i])
				inDegree[connected_node.getVertex()] += 1;
		
		std::queue<int> graphNodes;

		for(int i=0; i<numVertices; i++)
			if(inDegree[i] == 0)
				graphNodes.push(i);
			
		std::vector<int> topologicalSort;

		while(graphNodes.empty() == false) {
			int currNode = graphNodes.front();
			graphNodes.pop();
			topologicalSort.emplace_back(currNode);

			for(AdjacencyListNode connected_node : adjacencyList[currNode]) {
				inDegree[connected_node.getVertex()] -= 1;
				if(inDegree[connected_node.getVertex()] == 0)
					graphNodes.push(connected_node.getVertex());
			}
		}

		return topologicalSort;
	}

public:
	Graph(int numVertices) {
		this->numVertices = numVertices;
		adjacencyList = new list<AdjacencyListNode>[numVertices];
	}

	std::ostream& printAdjacencyList(std::ostream& outputStream) const {
		for(int i = 0; i < numVertices; i++) {
			outputStream << i << ": ";
			for(AdjacencyListNode connected_node : adjacencyList[i])
				outputStream << "(" << connected_node.getVertex() << ", " << connected_node.getEdgeWeight() << ") ";
			outputStream << "\n";
		}
		outputStream << std::endl;
		return outputStream;
	}

	void addEdge(int sourceVertex, int destVertex, int weight) {
		AdjacencyListNode newNodeEdge(destVertex, weight);
		adjacencyList[sourceVertex].push_back(newNodeEdge);
	}

	vector<int> shortestPath(int sourceVertex) {
		std::vector<int> distFromSource(numVertices);

		std::fill(distFromSource.begin(), distFromSource.end(), INT_MAX);
		distFromSource[sourceVertex] = 0;

		std::vector<int> topologicalSort = topologicalSorting();

		for(int i=0; i<numVertices; i++) {
			for(AdjacencyListNode connected_node : adjacencyList[topologicalSort[i]]) {
				if(distFromSource[connected_node.getVertex()] > distFromSource[topologicalSort[i]])
					distFromSource[connected_node.getVertex()] = distFromSource[topologicalSort[i]] + connected_node.getEdgeWeight();
			}
		}

		return distFromSource;
	}
};


std::ostream& operator<<(std::ostream& outputStream, const Graph& weightedGraph) {
	return weightedGraph.printAdjacencyList(outputStream);
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
	Graph weightedDAG(numVertices);

	cout << "Enter number of edges: ";
	cin >> numEdges;

	int vertex1, vertex2, weight;

	while(numEdges--) {
		cout << "Enter FROM vertex, TO vertex and EDGE WEIGHT for new edge: ";
		cin >> vertex1 >> vertex2 >> weight;
		weightedDAG.addEdge(vertex1, vertex2, weight);
	}

	int source;
	cout << "Enter source vertex: ";
	cin >> source;

	cout << "\nAdjacency List [sourceVertex: (connectedVertex, edgeWeight), ...]\n";
	cout << weightedDAG;

	vector<int> pathDist = weightedDAG.shortestPath(source);
	cout << "Dist from source vertex " << source << "\n" << pathDist;
	cout << endl;

	return 0;
}