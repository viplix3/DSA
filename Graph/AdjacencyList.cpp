#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjacency_list[], int vertex1, int vertex2) {
	adjacency_list[vertex1].emplace_back(vertex2);
	adjacency_list[vertex2].emplace_back(vertex1);
}

int main() {
	int numVertices, numEdges;
	int vertex1, vertex2;

	cout << "Enter num vertices: ";
	cin >> numVertices;
	vector<int> adjacencyList[numVertices];

	cout << "Enter num edges: ";
	cin >> numEdges;

	while(numEdges--) {
		cout << "Enter vertices for edge: ";
		cin >> vertex1 >> vertex2;
		addEdge(adjacencyList, vertex1, vertex2);
	}

	cout << "\nAdjacency List\n";
	int edge = 0;
	for(auto ele : adjacencyList) {
		cout << edge << ": ";
		for(auto x : ele)
			cout << x << " ";
		cout << endl;
		edge += 1;
	}
	cout << endl;

	return 0;
}