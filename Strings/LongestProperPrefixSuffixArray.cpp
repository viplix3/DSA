#include<bits/stdc++.h>
using namespace std;

/*
IP: "ababc"
idx 0: PP []					S [a]
idx 1: PP [a]					S [b, ab]
idx 2: PP [a, ab]				S [a, ba, aba]
idx 3: PP [a, ab, aba]			S [b, ab, bab, abab]
idx 4: PP [a, ab, aba, abab]	S [c, bc, abc, babc, ababc]

LPS: [0, 0, 1, 2, 0]

IP: "abacabad"
idx 0: PP []											S [a]
idx 1: PP [a]											S [b, ab]
idx 2: PP [a, ab]										S [a, ba, aba]
idx 3: PP [a, ab, aba]									S [c, ac, bac, abac]
idx 4: PP [a, ab, aba, abac]							S [a, ca, aca, baca, abaca]
idx 5: PP [a, ab, aba, abac, abaca]						S [b, ab, cab, acab, bacab, abacab]
idx 6: PP [a, ab, aba, abac, abaca, abacab]				S [a, ba, aba, caba, acaba, bacaba, abacaba]
idx 7: PP [a, ab, aba, abac, abaca, abacab, abacaba]	S [d, ad, bad, abad, cabad, acabad, bacabad, abacabad]

LPS: [0, 0, 1, 0, 1, 2, 3, 0]
*/

int longestProperPrefixSuffix(string str, int strlen)
{
	for(int len=strlen-1; len > 0; len--){
		bool flag = true;

		for(int i=0; i<len; i++)
			if(str[i] != str[strlen - len + i])
				flag = false;
		
		if(flag)
			return len;
	}
	return 0;
}

void fillLPS(string str, vector<int> &lps_arr)
{
	lps_arr.clear();
	for(int i=0; i<str.length(); i++){
		lps_arr.emplace_back(longestProperPrefixSuffix(str, i+1));
	}
}

void printArray(vector<int> arr)
{
	for(auto ele: arr)
		cout << ele << " ";
	cout << endl;
}

int main(){
	string str;
	vector<int> lps_arr;

	str = "ababc";
	cout << "\nInput string: " << str << endl;
	fillLPS(str, lps_arr);
	cout << "LPS array: ";
	printArray(lps_arr); // [0, 0, 1, 2, 0]

	str = "aaaa";
	cout << "\nInput string: " << str << endl;
	fillLPS(str, lps_arr);
	cout << "LPS array: ";
	printArray(lps_arr); // [0, 1, 2, 3]

	str = "abcd";
	cout << "\nInput string: " << str << endl;
	fillLPS(str, lps_arr);
	cout << "LPS array: ";
	printArray(lps_arr); // [0, 0, 0, 0]

	str = "ababab";
	cout << "\nInput string: " << str << endl;
	fillLPS(str, lps_arr);
	cout << "LPS array: ";
	printArray(lps_arr); // [0, 0, 1, 2, 3, 4]

	str = "abacabad";
	cout << "\nInput string: " << str << endl;
	fillLPS(str, lps_arr);
	cout << "LPS array: ";
	printArray(lps_arr); // [0, 0, 1, 0, 1, 2, 3, 0]

	str = "abbabb";
	cout << "\nInput string: " << str << endl;
	fillLPS(str, lps_arr);
	cout << "LPS array: ";
	printArray(lps_arr); // [0, 0, 0, 1, 2, 3]

	return 0;
}