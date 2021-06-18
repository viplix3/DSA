#include<bits/stdc++.h>
using namespace std;

constexpr int CHAR = 256;

bool areSame(int arr_1[], int arr_2[])
{
	for(int i=0; i < CHAR; i++)
		if(arr_1[i] != arr_2[i])
			return false;
	return true;
}

bool searchAnagram(string input_str, string pattern)
{
	int string_count[CHAR] = {0}, pattern_count[CHAR] = {0};

	for(int i=0; i < pattern.length(); i++){
		string_count[input_str[i]] += 1;
		pattern_count[pattern[i]] += 1;
	}

	for(int i=pattern.length(); i < input_str.length(); i++){
		// Anagram check for pattern and current window position
		if(areSame(string_count, pattern_count))
			return true;
		
		// Sliding Window
		string_count[input_str[i]] += 1;
		string_count[input_str[i - pattern.length()]] -= 1;
	}
	return false;
}

int main(){
	string str, pattern;

	str = "geeksforgeeks";
	pattern = "frog";
	cout << "\nInput string: " << str << endl;
	cout << "Pattern: " << pattern << endl;
	cout << "Given pattern or any of its permutations present in the string: " << searchAnagram(str, pattern) << endl;

	str = "geeksforgeeks";
	pattern = "rseek";
	cout << "\nInput string: " << str << endl;
	cout << "Pattern: " << pattern << endl;
	cout << "Given pattern or any of its permutations present in the string: " << searchAnagram(str, pattern) << endl;

	return 0;
}