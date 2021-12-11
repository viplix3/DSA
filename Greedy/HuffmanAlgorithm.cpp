#include <bits/stdc++.h>
using namespace std;

struct Node {
	int frequency;
	char ch;
	Node *left, *right;

	Node(char symbol, int freq)
		: frequency(freq), ch(symbol), left(nullptr), right(nullptr)
	{}
};

struct NodeComparator {
	bool operator()(Node* N1, Node* N2) {
		return (N1->frequency > N2->frequency);
	}
};

Node* buildHuffmanBTree(vector<char>& characters, vector<int>& frequencies) {
	priority_queue<Node*, vector<Node*>, NodeComparator> minHeap;

	for(int i=0; i<frequencies.size(); i++) {
		minHeap.push(new Node(characters[i], frequencies[i]));
	}

	while(minHeap.size() > 1) {
		Node* lowestFreqNode_1 = minHeap.top();
		minHeap.pop();

		Node* lowestFreqNode_2 = minHeap.top();
		minHeap.pop();

		Node* newNode = new Node('$', lowestFreqNode_1->frequency + lowestFreqNode_2->frequency);
		newNode->left = lowestFreqNode_1;
		newNode->right = lowestFreqNode_2;
		minHeap.push(newNode);
	}

	return minHeap.top();
}

void printHuffmanBTree(Node* root) {
	if(root == nullptr) {
		cout << "Empty tree" << endl;
		return;
	}

	queue<Node*> treeLevelNodes;
	treeLevelNodes.push(root);

	while(treeLevelNodes.empty() == false) {
		int numCurrLevelNodes = treeLevelNodes.size();

		for(int i=0; i<numCurrLevelNodes; i++) {
			Node* currNode = treeLevelNodes.front();
			treeLevelNodes.pop();

			if(currNode)
				cout << currNode->ch << ": " << currNode->frequency << "\t";
			
			if(currNode->left)
				treeLevelNodes.push(currNode->left);
			if(currNode->right)
				treeLevelNodes.push(currNode->right);
		}
		cout << endl;
	}
}


void parseAndPrintHuffmanCode(Node* huffmanBTreeRoot, string encoding) {
	if(huffmanBTreeRoot == nullptr)
		return;

	if(huffmanBTreeRoot->ch != '$') // Not an internal node, i.e. is a leaf node
		cout << huffmanBTreeRoot->ch << ": " << encoding << endl;
	
	parseAndPrintHuffmanCode(huffmanBTreeRoot->left, encoding + "0");
	parseAndPrintHuffmanCode(huffmanBTreeRoot->right, encoding + "1");

}


int main() {

	vector<char> characters;
	vector<int> frequencies;

	characters = {'a', 'd', 'b', 'e', 'f'};
	frequencies = {10,  50,  20,  40,  80};
	Node* huffmanBTreeRoot = buildHuffmanBTree(characters, frequencies);

	cout << "Level order traversal of huffman tree ('$' depicts the internal nodes)" << endl;
	printHuffmanBTree(huffmanBTreeRoot);

	cout << "\nHuffman encoded data" << endl;
	parseAndPrintHuffmanCode(huffmanBTreeRoot, "");

	return 0;
}