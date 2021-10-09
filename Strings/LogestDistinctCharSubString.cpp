#include <bits/stdc++.h>
using namespace std;

constexpr int CHARS = 256;

int getLongestSubStrLength(string &str)
{
	if(str.length() == 0)
		return 0;

	int previous_starting_idx = 0, previous_occurrence[CHARS];
	int max_substr_length = INT_MIN;

	fill(previous_occurrence, previous_occurrence + CHARS, -1);

	for(int curr_idx=0; curr_idx < str.length(); curr_idx++){
		previous_starting_idx = max(previous_starting_idx, previous_occurrence[str[curr_idx]] + 1);
		int curr_substr_length = curr_idx - previous_starting_idx + 1;
		max_substr_length = max(curr_substr_length, max_substr_length);
		previous_occurrence[str[curr_idx]] = curr_idx;
	}
	return max_substr_length;
}

int main(){
	string str;

	str = "abcdabc";
	cout << "\nInput string: " << str << endl;
	cout << "Longest substring with distinct characters in given string: " << getLongestSubStrLength(str) << endl;

	str = "aaa";
	cout << "\nInput string: " << str << endl;
	cout << "Longest substring with distinct characters in given string: " << getLongestSubStrLength(str) << endl;

	str = "abaaacd";
	cout << "\nInput string: " << str << endl;
	cout << "Longest substring with distinct characters in given string: " << getLongestSubStrLength(str) << endl;

	str = "abaacdbab";
	cout << "\nInput string: " << str << endl;
	cout << "Longest substring with distinct characters in given string: " << getLongestSubStrLength(str) << endl;

	str = "abac";
	cout << "\nInput string: " << str << endl;
	cout << "Longest substring with distinct characters in given string: " << getLongestSubStrLength(str) << endl;

	return 0;
}