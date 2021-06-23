#include <bits/stdc++.h>
using namespace std;

int getLongestSubStrLength(string &str)
{
	if(str.length() == 0)
		return 0;

	unordered_set<char> string_chars;
	int max_substr_length = 1;

	for(int i=0; i<str.length(); i++){
		if(string_chars.find(str[i]) != string_chars.end()){
			max_substr_length = max(max_substr_length, static_cast<int>(string_chars.size()));
			string_chars.clear();
		}
		else
			string_chars.insert(str[i]);
	}
	return max_substr_length;
}

int main(){
	string str;

	str = "abcdabc";
	cout << "\nInput string: " << str << endl;
	cout << "Longest substring with distince characters in given string: " << getLongestSubStrLength(str) << endl;

	str = "aaa";
	cout << "\nInput string: " << str << endl;
	cout << "Longest substring with distince characters in given string: " << getLongestSubStrLength(str) << endl;

	str = "";
	cout << "\nInput string: " << str << endl;
	cout << "Longest substring with distince characters in given string: " << getLongestSubStrLength(str) << endl;

	str = "abaacdbab";
	cout << "\nInput string: " << str << endl;
	cout << "Longest substring with distince characters in given string: " << getLongestSubStrLength(str) << endl;

	str = "abac";
	cout << "\nInput string: " << str << endl;
	cout << "Longest substring with distince characters in given string: " << getLongestSubStrLength(str) << endl;

	return 0;
}