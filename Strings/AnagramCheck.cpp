#include <bits/stdc++.h>
using namespace std;

bool checkAnagram(string& str_1, string& str_2)
{
	if(str_1.length() != str_2.length())
		return false;

	int char_count[26];
	memset(char_count, 0, sizeof(char_count));

	for(int i=0; i<str_1.length(); i++){
		char_count[str_1[i] - 'a'] += 1;
		char_count[str_2[i] - 'a'] -= 1;
	}

	for(int i=0; i<26; i++)
		if(char_count[i] != 0)
			return false;
	return true;
}

int main(){
	string str_1, str_2;

	cout << "Enter the 1st input string: ";
	cin >> str_1;
	cout << "Enter the 2nd input string: ";
	cin >> str_2;
	cout << "String 1 and 2 are anagrams: " << checkAnagram(str_1, str_2) << endl;

	return 0;
}