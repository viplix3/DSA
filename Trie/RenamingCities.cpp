// https://practice.geeksforgeeks.org/problems/renaming-cities28581833/1/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node{
    bool isEndOfWord;
    int count1;
    map<char, Node *> mp;
};

Node *newNode(){
    Node *temp = new Node();
    temp->isEndOfWord = false;
    // int count1 = 0;
    return temp;
}


 // } Driver Code Ends
//User function template for C++

// arr : array of strings
// n : count of the number of strings in the array
class Solution
{
private:
	string insertAndGetID(Node* root, string cityName) {
		int strLen = cityName.length();

		string currId = "";
		int endIdx = -1, count;

		for(int currIdx = 0; currIdx < strLen; currIdx++) {
			char currChar = cityName[currIdx];

			if(root->mp.find(currChar) == root->mp.end()) { // Current character not encountered before
				root->mp[currChar] = newNode(); // Create a new node for current character
				root->count1 = 1; // Initial count set to 1

				if(endIdx == -1)
					endIdx = currIdx;
			}
			else
				root->count1 += 1; // Current character encountered before, add 1 to count

			count = root->count1;
			root = root->mp[currChar];
			currId += currChar;
		}

		root->isEndOfWord = true;
		endIdx += 1;

		if(endIdx == 0) { // Complete string appeared before
			if(strLen != 1)
			    currId += " " + to_string(count);
		}
		else
			currId = currId.substr(0, endIdx); // Take some part of the city name
		
		return currId;
	}


public:
    void check(string *arr, int n){
		Node* root = newNode();
		vector<string> cityIDs;

		for(int i = 0;  i < n; i++) { // Insert all the city names in Trie
			cityIDs.emplace_back(insertAndGetID(root, arr[i]));
		}

		for(string id : cityIDs)
			cout << id << endl;
    }
};




// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string arr[n];
        for(int i = 0;i<n;i++){
            string s;
            cin >> s;
            arr[i] = s;
        }
        Solution obj;
        obj.check(arr,n);
    }
    return 0;
}
  // } Driver Code Ends