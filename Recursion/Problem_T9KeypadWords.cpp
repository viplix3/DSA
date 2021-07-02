// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
private:
	void generateWords(vector<string>& allWords, int keypadInput[], int numInputs) {
		string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		static string currWord = "";
		static int keyIdx = 0;
		
		if(currWord.length() == numInputs){
			allWords.emplace_back(currWord);
			return;
		}

		for(int keyEntryIdx = 0; keyEntryIdx < mapping[keypadInput[keyIdx]].length(); keyEntryIdx++) {
			currWord += mapping[keypadInput[keyIdx]][keyEntryIdx]; // Added a letter of keyIdx

			keyIdx += 1; // Now we need to add the letter of next key, so keyIdx is incremented by 1
			generateWords(allWords, keypadInput, numInputs);
			currWord.pop_back();
			
			keyIdx -= 1; // Now in next iteration, we want to add letter of curr key, so keyIdx reset is done
		}

	}

    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
		vector<string> allWords;
		generateWords(allWords, a, N);
		return allWords;
    }
};


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
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends