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

void fillLPS(string str, vector<int> &lps_arr)
{
	lps_arr.clear();
	int n = str.length(), len = 0;
	lps_arr.emplace_back(0);
	int i = 1;
	
	while(i < n){
		if(str[i] == str[len]){
			// Current LPS will be last LPS + 1
			len++;
			lps_arr.emplace(lps_arr.begin()+i, len);
			// lps_arr[i] == len;
			i++;
		}
		else{
			if(len == 0) // If current string elements do not match and lps for previous element was 0, it will remain 0 for current
			{
				lps_arr.emplace(lps_arr.begin()+i, 0);
				// lps_arr[i] = 0;
				i++;
			}
			else{ // If current string do not match but lps is not zero, we will try to extend the last known lps with current string element
				len = lps_arr[len-1];
			}
		}
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