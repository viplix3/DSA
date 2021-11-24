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

struct NodeComparator {
	bool operator() (AdjacencyListNode& Node1, AdjacencyListNode& Node2) {
		return Node1.getEdgeWeight() > Node2.getEdgeWeight();
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

		AdjacencyListNode newNodeEdge1(sourceVertex, weight);
		adjacencyList[destVertex].push_back(newNodeEdge1);
	}

	vector<int> dijkstraAlgo(int sourceVertex) {
		priority_queue<AdjacencyListNode, vector<AdjacencyListNode>, NodeComparator> minHeap;
		bool visited[numVertices] = {false};

		vector<int> distFromSource(numVertices);
		fill(distFromSource.begin(), distFromSource.end(), INT_MAX);

		AdjacencyListNode currNode = AdjacencyListNode(sourceVertex, 0);
		minHeap.push(currNode);
		distFromSource[sourceVertex] = 0;

		while(minHeap.empty() == false) {
			currNode = minHeap.top();
			minHeap.pop();

			if(visited[currNode.getVertex()] == true)
				continue;
			
			visited[currNode.getVertex()] = true;

			for(AdjacencyListNode connected_node : adjacencyList[currNode.getVertex()]) {
				if(visited[connected_node.getVertex()] == false) {
					distFromSource[connected_node.getVertex()] = min(distFromSource[currNode.getVertex()] + connected_node.getEdgeWeight(), 
																		distFromSource[connected_node.getVertex()]);
					minHeap.push(connected_node);
				}
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
	Graph weightedGraph(numVertices);

	cout << "Enter number of edges: ";
	cin >> numEdges;

	int vertex1, vertex2, weight;

	while(numEdges--) {
		cout << "Enter VERTEX-1, VERTEX-2 and EDGE WEIGHT for new edge: ";
		cin >> vertex1 >> vertex2 >> weight;
		weightedGraph.addEdge(vertex1, vertex2, weight);
	}

	cout << "\nAdjacency List\n";
	cout << weightedGraph;

	int sourceVertex;
	cout << "Enter source vertex: ";
	cin >> sourceVertex;

	cout << "Minimum distance to all the edges from source vertex " << sourceVertex << "\n" << weightedGraph.dijkstraAlgo(sourceVertex) << endl;

	return 0;
}
