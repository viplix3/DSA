// Working on LeetCode, not on G4G
// On LeetCode, RunTime: 0ms, Memory Usage: 7.3MB
// { Driver Code Starts
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector <string> possibleWords(int a[],int n);


int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	  vector <string> res = possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}// } Driver Code Ends


//Complete this function

void findStringPermutations(vector<string> &possibleWordCombinations, vector<string> &dictValues, vector<int> &currIndices, int numKeyPadEntries)
{
	int totalPossibleCombinations = 1;
	for(int i=0; i<numKeyPadEntries; i++)
		totalPossibleCombinations *= dictValues[i].size();
	if(possibleWordCombinations.size() == totalPossibleCombinations)
		return;
	
	string possibleWord = "";
	for(int i=0; i<numKeyPadEntries; i++){
		possibleWord += dictValues[i][currIndices[i]];
	}
	possibleWordCombinations.push_back(possibleWord);

	bool updateFlag = true;
	for(int i=numKeyPadEntries-1; i>=0; i--){
		if(updateFlag){
			currIndices[i] += 1;
			updateFlag = false;
		}

		if(currIndices[i] == dictValues[i].length()){
			currIndices[i] = 0;
			updateFlag = true;
		}
		else
			updateFlag = false;
	}

	findStringPermutations(possibleWordCombinations, dictValues, currIndices, numKeyPadEntries);
}

vector <string> possibleWords(int a[],int N)
{
    vector<string> keyPadDict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> possibleWordCombinations;
	vector<int> currIndices;
    vector<string> currDictSelection;

	for(int i=0; i<N; i++){
		currIndices.push_back(0);
		currDictSelection.push_back(keyPadDict[a[i]]);
	}
	
    findStringPermutations(possibleWordCombinations, currDictSelection, currIndices, N);
	return possibleWordCombinations;
}