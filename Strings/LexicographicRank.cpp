#include<bits/stdc++.h>
using namespace std;

constexpr int CHAR = 256;

int factorial(int n)
{
	int fact = 1;
	while(n != 0){
		fact *= n;
		n -= 1;
	}
	return fact;
}

int getLexRank(string &str)
{
	int rank = 1, strlen = str.length();
	int multiplier = factorial(strlen);
	int occ_count[CHAR] = {0};

	for(int i=0; i < strlen; i++)
		occ_count[str[i]] += 1;

	for(int i=1; i < CHAR; i++)
		occ_count[i] += occ_count[i-1];

	for(int i=0; i < strlen; i++){
		multiplier /= (strlen-i);
		rank = rank + multiplier * occ_count[str[i] - 1];

		for(int j=str[i]; j < CHAR; j++)
			occ_count[j] -= 1;
	}
	return rank;
}

int main(){
	string str;

	str = "STRING";
	cout << "\nInput string: " << str << endl;
	cout << "Lexicographical rank of string: " << getLexRank(str) << endl;

	str = "ABC";
	cout << "\nInput string: " << str << endl;
	cout << "Lexicographical rank of string: " << getLexRank(str) << endl;

	str = "DCBA";
	cout << "\nInput string: " << str << endl;
	cout << "Lexicographical rank of string: " << getLexRank(str) << endl;

	return 0;
}