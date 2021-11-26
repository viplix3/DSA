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

	std::vector<int> bellmanFordShortestPath(int sourceVertex) {
		std::vector<int> distFromSource(numVertices);
		
		fill(distFromSource.begin(), distFromSource.end(), INT_MAX);
		distFromSource[sourceVertex] = 0;

		for(int i=0; i<numVertices; i++) {
			for(AdjacencyListNode connected_node : adjacencyList[i])
				if(distFromSource[i] != INT_MAX &&
					distFromSource[i] + connected_node.getEdgeWeight() < distFromSource[connected_node.getVertex()])
						distFromSource[connected_node.getVertex()] = distFromSource[i] + connected_node.getEdgeWeight();
		}

		for(int i=0; i<numVertices; i++) {
			for(AdjacencyListNode connected_node : adjacencyList[i])
				if(distFromSource[i] != INT_MAX &&
					distFromSource[i] + connected_node.getEdgeWeight() < distFromSource[connected_node.getVertex()]) {
						std::cout << "Negative edge weight cycle present in the graph" << std::endl;
						return std::vector<int>(numVertices);
					}
		}

		return distFromSource;
	}

};


std::ostream& operator<<(std::ostream& outputStream, const Graph& weightedGraph) {
	return weightedGraph.printAdjacencyList(outputStream);
}

std::ostream& operator<<(std::ostream& outputStream, std::vector<int> outData) {
	for(auto data : outData)
		outputStream << data << " ";
	outputStream  << endl;
	return outputStream;
}


int main() {
	int numVertices, numEdges;
	cout << "Enter number of vertices: ";
	cin >> numVertices;
	Graph weightedGraph(numVertices);

	cout << "Enter number of edges: ";
	cin >> numEdges;

	int vertex1, vertex2, edgeWeight;

	while(numEdges--) {
		cout << "Enter SOURCE, DESTINATION VERTEX and WEIGHT for new edge: ";
		cin >> vertex1 >> vertex2 >> edgeWeight;
		weightedGraph.addEdge(vertex1, vertex2, edgeWeight);
	}

	cout << "\nAdjacency List\n";
	cout << weightedGraph;

	int sourceVertex;
	cout << "Enter source vertex for finding shortest paths from: ";
	cin >> sourceVertex;

	cout << "Shortest path from source vertex " << sourceVertex << endl;;
	cout << weightedGraph.bellmanFordShortestPath(sourceVertex) << endl;

	return 0;
}


