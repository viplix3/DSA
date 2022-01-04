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

int main() {
	TrieNode *root = new TrieNode();
	string inputString, searchString;

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

	return 0;
}