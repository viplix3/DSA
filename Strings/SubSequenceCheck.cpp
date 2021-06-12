#include <bits/stdc++.h>
using namespace std;

bool isSubseqence(string &str_1, string &str_2)
{
	int j = 0;
	for(int i=0; i<str_1.length(); i++)
		if(str_1[i] == str_2[j] && j < str_2.length())
			j++;
	return (j == str_2.length());
}

int main(){
	string str_1, str_2;
	
	cout << "\nEnter the input string 1: ";
	cin >> str_1;
	cout << "\nEnter the input string 2: ";
	cin >> str_2;
	if(isSubseqence(str_1, str_2))
		cout << "\nString 2 is a subsequence of string 1" << endl;
	else
		cout << "\nString 2 is not a subsequence of string 1" << endl;
	
	return 0;
}