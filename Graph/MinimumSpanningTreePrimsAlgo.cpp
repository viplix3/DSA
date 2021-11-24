#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
	int numVertices;
	std::vector<std::vector<int>> adjacencyMatrix;

public:
	Graph(int numVertices) {
		this->numVertices = numVertices;

		adjacencyMatrix.reserve(numVertices);
		for(int i=0; i<numVertices; i++)
			adjacencyMatrix[i] = vector<int>(numVertices);
	}

	std::ostream& printAdjacencyMatrix(std::ostream& outputStream) const {
		for(int i = 0; i < numVertices; i++) {
			for(int j=0; j < numVertices; j++)
				outputStream << adjacencyMatrix[i][j] << "\t";
			outputStream << "\n";
		}
		outputStream << std::endl;
		return outputStream;
	}

	void addEdge(int sourceVertex, int destVertex, int weight) {
		adjacencyMatrix[sourceVertex][destVertex] = weight;
		adjacencyMatrix[destVertex][sourceVertex] = weight;
	}

	int getMinSpanningTreeCost() {
		int distToMST[numVertices], cost = 0;
		bool includedInMST[numVertices] = {false};

		std::fill(distToMST, distToMST+numVertices, INT_MAX);
		distToMST[0] = 0;

		for(int count = 0; count < numVertices; count++) {
			int sourceVertex = -1;

			// Pick the vertex having smallest distance to the nodes currently included in MST
			for(int i=0; i<numVertices; i++)
				if(!includedInMST[i] && (sourceVertex == -1 || distToMST[i] < distToMST[sourceVertex]))
					sourceVertex = i;
			
			// Mark the selected vertex as true and add the cost of selecting the vertex
			includedInMST[sourceVertex] = true;
			cost += distToMST[sourceVertex];

			// Update the smallest distance (of all connected vertices) to the picked source vertex
			for(int i=0; i<numVertices; i++) {
				if(adjacencyMatrix[sourceVertex][i] !=0 && !includedInMST[i])
					distToMST[i] = min(distToMST[i], adjacencyMatrix[sourceVertex][i]);
			}
		}

		return cost;
	}

};

std::ostream& operator<<(std::ostream& outputStream, const Graph& weightedGraph) {
	return weightedGraph.printAdjacencyMatrix(outputStream);
}

std::ostream& operator<<(std::ostream& outputStream, std::vector<int> outData) {
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
		cout << "Enter FROM vertex, TO vertex and EDGE WEIGHT for new edge: ";
		cin >> vertex1 >> vertex2 >> weight;
		weightedGraph.addEdge(vertex1, vertex2, weight);
	}

	cout << "\nAdjacency Matrix\n";
	cout << weightedGraph;

	cout << "Minimum Spanning tree cost: " << weightedGraph.getMinSpanningTreeCost() << endl;

	return 0;
}