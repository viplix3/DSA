#include<bits/stdc++.h>
using namespace std;

bool check_palindrome(string &str)
{
	int i=0, j = str.length()-1;

	while(i < j)
		if(str[i++] != str[j--])
			return false;
	return true;
}

int main(){
	string str;

	cout << "\nEnter the input string: ";
	cin >> str;
	cout<< "Palindrome: " << check_palindrome(str) << endl;

	return 0;
}