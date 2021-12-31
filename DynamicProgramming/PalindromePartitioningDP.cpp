#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int beginIdx, int endIdx) {

	while(beginIdx < endIdx) {
		if(str[beginIdx] != str[endIdx])
			return false;
		
		beginIdx += 1;
		endIdx -= 1;
	}

	return true;
}

int getPalindromicPartitions(string str) {
	int numChars = str.length();

	if(isPalindrome(str, 0, numChars - 1))
		return 0;
	
	vector<vector<int>> numPartitions(numChars, vector<int>(numChars, 0));

	for(int currGap = 1; currGap < numChars; currGap++) {
		for(int currBeginIdx = 0; (currBeginIdx + currGap) < numChars; currBeginIdx++) {
			int currEndIdx = currBeginIdx + currGap;

			if(isPalindrome(str, currBeginIdx, currEndIdx))
				numPartitions[currBeginIdx][currEndIdx] = 0;
			else {
				numPartitions[currBeginIdx][currEndIdx] = INT_MAX;

				for(int i = currBeginIdx; i < currEndIdx; i++) { // Same loop as recursion
					numPartitions[currBeginIdx][currEndIdx] = min( numPartitions[currBeginIdx][currEndIdx],
															1 + numPartitions[currBeginIdx][i] + numPartitions[i+1][currEndIdx]);
				}
			}

		}
	}

	return numPartitions[0][numChars - 1];
}

int main() {
	string testString;

	testString = "geek";
	cout << "Input string: " << testString << endl;
	cout << "Num partitions required to make string palindrome: " << getPalindromicPartitions(testString) << endl;
	cout << endl;

	testString = "abbac";
	cout << "Input string: " << testString << endl;
	cout << "Num partitions required to make string palindrome: " << getPalindromicPartitions(testString) << endl;
	cout << endl;

	testString = "abcde";
	cout << "Input string: " << testString << endl;
	cout << "Num partitions required to make string palindrome: " << getPalindromicPartitions(testString) << endl;
	cout << endl;

	testString = "aaaa";
	cout << "Input string: " << testString << endl;
	cout << "Num partitions required to make string palindrome: " << getPalindromicPartitions(testString) << endl;
	cout << endl;

	testString = "abbabbc";
	cout << "Input string: " << testString << endl;
	cout << "Num partitions required to make string palindrome: " << getPalindromicPartitions(testString) << endl;
	cout << endl;

	return 0;
}