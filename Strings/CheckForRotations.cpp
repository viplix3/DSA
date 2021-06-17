#include<bits/stdc++.h>
using namespace std;

bool checkForRotations(string str_1, string str_2)
{
	if(str_1.length() != str_2.length())
		return false;

	return ((str_1+str_1).find(str_2) != string::npos);
}

int main(){
	string str_1, str_2;

	str_1 = "ABCD";
	str_2 = "CDAB";
	cout << "\nInput string 1: " << str_1 << endl;
	cout << "Input string 2: " << str_2 << endl;
	cout << "Given strings are rotations of each other: " << checkForRotations(str_1, str_2) << endl;

	str_1 = "ABAAA";
	str_2 = "BAAAA";
	cout << "\nInput string 1: " << str_1 << endl;
	cout << "Input string 2: " << str_2 << endl;
	cout << "Given strings are rotations of each other: " << checkForRotations(str_1, str_2) << endl;

	str_1 = "ABAB";
	str_2 = "ABBA";
	cout << "\nInput string 1: " << str_1 << endl;
	cout << "Input string 2: " << str_2 << endl;
	cout << "Given strings are rotations of each other: " << checkForRotations(str_1, str_2) << endl;
	
	return 0;
}