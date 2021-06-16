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

	/* 
		At each iteration of while loop we ensure that our perfect prefix and suffix are same
		The length of the same is being stored in len variable.
		For each iteration through the string elements, we try to extend the LPS known for last string elemnt.

		Now the substring from index [0, len-1] is the last known perfect prefix and it matches with
		suffix starting from index [curr_itr_idx - len - 1, curr_itr_idx]. Hence, if element at index len matched with
		current iteration index, we will have a LPS for current element which is 1 greater than the last known LPS.

		If the elemnts at len and curr_itr_idx do not match, we will check the LPS know before the last known LPS and will try to extend
		it using the same procedure. We will keep following these steps until we have a valid LPS or the LPS turns 0.

		One important thing to note is that the lps_arr at any given index stores the length of the LPS for substring of that length,
		and at the same time, the entry in the lps_arr also signifies ending index (0-based indexing) of the mathced perfect-prefix.
		Hence to extend that particular LPS, we just need to match the string at index in the lps_arr with current element under consideration.
	*/
	
	while(i < n){
		if(str[i] == str[len]){ // The if statement tried to extend the last known LPS
			// Current LPS will be last LPS + 1
			len++;
			lps_arr.emplace(lps_arr.begin()+i, len);
			i++;
		}
		else{ // The if statement fails so we try to extend the LPS just before the last known LPS
			if(len == 0) // If current string elements do not match and lps for previous element was 0, it will remain 0 for current
			{
				lps_arr.emplace(lps_arr.begin()+i, 0);
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