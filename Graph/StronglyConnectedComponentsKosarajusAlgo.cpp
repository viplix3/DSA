#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
	int numVertices;
	std::list<int> *adjacencyList;
	
	void topologicalSortUtil(int sourceVertex, bool visited[], std::stack<int>& recursion_stack) {
		visited[sourceVertex] = true;

		for(int connected_node : adjacencyList[sourceVertex]) {
			if(visited[connected_node] == false)
				topologicalSortUtil(connected_node, visited, recursion_stack);
		}

		recursion_stack.push(sourceVertex);
	}


	void DFS(Graph graph, int sourceVertex, bool visited[], std::vector<int>& traversal) {
		visited[sourceVertex] = true;
		traversal.emplace_back(sourceVertex);

		for(int connected_node : graph.adjacencyList[sourceVertex]) {
			if(visited[connected_node] == false)
				DFS(graph, connected_node, visited, traversal);
		}
	}


	Graph transposeGraph() {
		Graph transposedGraph(numVertices);

		for(int i=0; i<numVertices; i++)
			for(int connected_node : adjacencyList[i])
				transposedGraph.adjacencyList[connected_node].emplace_back(i);
		
		return transposedGraph;
	}


	std::vector<int> topologicalSortingDFS() {
		bool visited[numVertices] = {false};
		std::stack<int> recursion_stack;
		std::vector<int> topologicalSort;

		for(int i=0; i<numVertices; i++)
			if(visited[i] == false)
				topologicalSortUtil(i, visited, recursion_stack);
		
		while(recursion_stack.empty() == false) {
			topologicalSort.emplace_back(recursion_stack.top());
			recursion_stack.pop();
		}

		return topologicalSort;
	}

public:
	Graph(int numVertices) {
		this->numVertices = numVertices;
		adjacencyList = new list<int>[numVertices];
	}

	std::ostream& printAdjacencyList(std::ostream& outputStream) const {
		for(int i = 0; i < numVertices; i++) {
			outputStream << i << ": ";
			for(int connected_node : adjacencyList[i])
				outputStream << connected_node << " ";
			outputStream << "\n";
		}
		outputStream << std::endl;
		return outputStream;
	}

	void addEdge(int sourceVertex, int destVertex) {
		adjacencyList[sourceVertex].push_back(destVertex);
	}

	std::vector<std::vector<int>> getStronglyConnectedComponents() {
		std::vector<int> topologicalSort = topologicalSortingDFS();
		Graph graphTransposed = transposeGraph();

		std::vector<std::vector<int>> SSCs;
		bool visited[numVertices] = {false};

		for(int vertex : topologicalSort) {
			std::vector<int> DFSTraversal;
			if(visited[vertex] == false) {
				DFS(graphTransposed, vertex, visited, DFSTraversal);
				SSCs.emplace_back(DFSTraversal);
			}
		}

		return SSCs;
	}

};


std::ostream& operator<<(std::ostream& outputStream, const Graph& weightedGraph) {
	return weightedGraph.printAdjacencyList(outputStream);
}

std::ostream& operator<<(std::ostream& outputStream, std::vector<std::vector<int>> outData) {
	for(auto data_vector : outData) {
		for(auto data : data_vector)
			outputStream << data << " ";
		outputStream  << endl;
	}
	return outputStream;
}


int main() {
	int numVertices, numEdges;
	cout << "Enter number of vertices: ";
	cin >> numVertices;
	Graph weightedGraph(numVertices);

	cout << "Enter number of edges: ";
	cin >> numEdges;

	int vertex1, vertex2;

	while(numEdges--) {
		cout << "Enter SOURCE and DESTINATION VERTEX for new edge: ";
		cin >> vertex1 >> vertex2;
		weightedGraph.addEdge(vertex1, vertex2);
	}

	cout << "\nAdjacency List\n";
	cout << weightedGraph;

	cout << "Strongly connected components in graph: \n";
	cout << weightedGraph.getStronglyConnectedComponents() << endl;

	return 0;
}

