#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_CHILDREN = 26;

struct TrieNode {
	TrieNode *child[MAX_CHILDREN];
	bool isEnd;

	TrieNode()
		: isEnd(false)
	{
		for(int i = 0; i < MAX_CHILDREN; i++)
			child[i] = nullptr;
	}
};

bool search(string& key, TrieNode* root) {
	TrieNode *curr = root;

	for(int i = 0; i < key.length(); i++) {
		int charIdx = key[i] - 'a';

		if(curr->child[charIdx] == nullptr)
			return false;
		curr = curr->child[charIdx];
	}

	return curr->isEnd;
}

void insert(string& key, TrieNode* root) {
	TrieNode *curr = root;

	for(int i = 0; i < key.length(); i++) {
		int charIdx = key[i] - 'a';

		if(curr->child[charIdx] == nullptr)
			curr->child[charIdx] = new TrieNode();

		curr = curr->child[charIdx];
	}

	curr->isEnd = true;
}

bool isEmpty(TrieNode* root) {
	for(int i = 0; i < MAX_CHILDREN; i++)
		if(root->child[i] != nullptr)
			return false;
	
	return true;
}

TrieNode* deleteWord(string& key, int strIdx, TrieNode* root) {
	if(root == nullptr)
		return nullptr;
	
	if(strIdx == key.length()) {
		root->isEnd = false;

		if(isEmpty(root)) {
			delete(root);
			root = nullptr;
		}

		return root;
	}

	int charIdx = key[strIdx] - 'a';
	root->child[charIdx] = deleteWord(key, strIdx+1, root->child[charIdx]);

	return root;
}

int main() {
	TrieNode *root = new TrieNode();
	string inputString, searchString, deleteString;

	inputString = "cat";
	insert(inputString, root);

	inputString = "can";
	insert(inputString, root);

	inputString = "bat";
	insert(inputString, root);

	inputString = "bad";
	insert(inputString, root);

	inputString = "geek";
	insert(inputString, root);

	searchString = "cat";
	cout << boolalpha << searchString << " in Trie: " << search(searchString, root) << endl;

	searchString = "can";
	cout << boolalpha << searchString << " in Trie: " << search(searchString, root) << endl;

	searchString = "caa";
	cout << boolalpha << searchString << " in Trie: " << search(searchString, root) << endl;

	searchString = "geeks";
	cout << boolalpha << searchString << " in Trie: " << search(searchString, root) << endl;

	searchString = "FAANG";
	cout << boolalpha << searchString << " in Trie: " << search(searchString, root) << endl;

	deleteString = "FAANG";
	root = deleteWord(deleteString, 0, root);

	deleteString = "cat";
	root = deleteWord(deleteString, 0, root);

	return 0;
}