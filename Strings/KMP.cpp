#include<bits/stdc++.h>
using namespace std;

void fillLPS(string str, vector<int>& lps_arr)
{
	lps_arr.clear();
	lps_arr.emplace_back(0);
	
	int n = str.length(), len = 0;
	int i = 1;

	while(i < n){
		if(str[i] == str[len]) {
			len += 1;
			lps_arr.emplace(lps_arr.begin()+i, len);
			i += 1;
		}
		else{
			if(len == 0) {
				lps_arr.emplace(lps_arr.begin()+i, 0);
				i += 1;
			}
			else{
				len = lps_arr[len-1];
			}
		}
	}
}


vector<int> KMP(string input_str, string pattern)
{
	vector<int> matched_indices;
	vector<int> lps_pattern;
	fillLPS(pattern, lps_pattern);

	/*
		How KMP works and what is the role of LPS array during pattern matching?
		We are creating a LPS array for pattern here. How LPS array data is used during pattern matching in KMP is very intersting.
		Eg. Pattern : ababa -> LPS: [0, 0, 1, 2, 3]
		The LPS array tells us the length of the proper prefix which is also a suffix at any particular index of the string.
		Hence in our example pattern, for 'b' at index 3, we have 2 in LPS. This tells us that if we have matched our pattern with input string
		till 'b' at index 3 of pattern, then the data at index 0 & 1 is same as data in index 2 & 3 and if we slide our pattern over by 2, the starting
		2 entries of the pattern will match with string. Why? As the 4 entries were matching with pattern and the starting and ending 2 are the same.

		Now if suppose there is a mismatch between pattern and input string at index 4, how does KMP help in this case?
		We know that data at indices [0, 3] of pattern matches with string and from the LPS array we know that data at indices [0, 1] of the pattern
		is same as the data at indices [2, 3] of the pattern. Hence if there is a mismatch at index 4 of the string and pattern, we can slide the pattern
		over by the len (entry in the LPS array of last match) and the starting len entries of the pattern would automatically match with string. 
		[This isn't exactly what is done, simplified for understanding. Actual shift is (current failed/matched index of pattern - LPS entry)]
		Now we have to compare and check data at entry len of pattern with string data which didn't match earlier and recurse.
	*/

	int i=0, j=0;

	while(i < input_str.length()){
		if(input_str[i] == pattern[j]){
			i += 1;
			j += 1;
		}
		if(j == pattern.length()){
			matched_indices.emplace_back(i - pattern.length());
			j = lps_pattern[j-1];
		}
		else if(i < input_str.length() && input_str[i] != pattern[j]){
			if(j == 0)
				i += 1;
			else
				j = lps_pattern[j-1];
		}
	}
	return matched_indices;
}

void printArray(vector<int> arr)
{
	for(auto ele: arr)
		cout << ele << " ";
	cout << endl;
}


int main(){
	string input_str, pattern;
	vector<int> pattern_occ_idx;

	input_str = "ABCABCDABCD";
	pattern = "ABCD";
	pattern_occ_idx = KMP(input_str, pattern);
	cout << "\nInput string: " << input_str << endl;
	cout << "Search pattern: " << pattern << endl;
	if(pattern_occ_idx.size() > 0){
		cout << "Pattern occurrent index: ";
		printArray(pattern_occ_idx);
	}
	else
		cout << "Given pattern doesn't appear in the provided input string" << endl;

	input_str = "GEEKSFORGEEKS";
	pattern = "EKS";
	pattern_occ_idx = KMP(input_str, pattern);
	cout << "\nInput string: " << input_str << endl;
	cout << "Search pattern: " << pattern << endl;
	if(pattern_occ_idx.size() > 0){
		cout << "Pattern occurrent index: ";
		printArray(pattern_occ_idx);
	}
	else
		cout << "Given pattern doesn't appear in the provided input string" << endl;

	input_str = "ABCAAAD";
	pattern = "ABD";
	pattern_occ_idx = KMP(input_str, pattern);
	cout << "\nInput string: " << input_str << endl;
	cout << "Search pattern: " << pattern << endl;
	if(pattern_occ_idx.size() > 0){
		cout << "Pattern occurrent index: ";
		printArray(pattern_occ_idx);
	}
	else
		cout << "Given pattern doesn't appear in the provided input string" << endl;

	input_str = "AAAAAAAAAAA";
	pattern = "AAAA";
	pattern_occ_idx = KMP(input_str, pattern);
	cout << "\nInput string: " << input_str << endl;
	cout << "Search pattern: " << pattern << endl;
	if(pattern_occ_idx.size() > 0){
		cout << "Pattern occurrent index: ";
		printArray(pattern_occ_idx);
	}
	else
		cout << "Given pattern doesn't appear in the provided input string" << endl;

	input_str = "abcdef";
	pattern = "bcd";
	pattern_occ_idx = KMP(input_str, pattern);
	cout << "\nInput string: " << input_str << endl;
	cout << "Search pattern: " << pattern << endl;
	if(pattern_occ_idx.size() > 0){
		cout << "Pattern occurrent index: ";
		printArray(pattern_occ_idx);
	}
	else
		cout << "Given pattern doesn't appear in the provided input string" << endl;

	input_str = "aaaaab";
	pattern = "aaaa";
	pattern_occ_idx = KMP(input_str, pattern);
	cout << "\nInput string: " << input_str << endl;
	cout << "Search pattern: " << pattern << endl;
	if(pattern_occ_idx.size() > 0){
		cout << "Pattern occurrent index: ";
		printArray(pattern_occ_idx);
	}
	else
		cout << "Given pattern doesn't appear in the provided input string" << endl;
	input_str = "abcd";
	pattern = "bd";
	pattern_occ_idx = KMP(input_str, pattern);
	cout << "\nInput string: " << input_str << endl;
	cout << "Search pattern: " << pattern << endl;
	if(pattern_occ_idx.size() > 0){
		cout << "Pattern occurrent index: ";
		printArray(pattern_occ_idx);
	}
	else
		cout << "Given pattern doesn't appear in the provided input string" << endl;

	input_str = "abababad";
	pattern = "abab";
	pattern_occ_idx = KMP(input_str, pattern);
	cout << "\nInput string: " << input_str << endl;
	cout << "Search pattern: " << pattern << endl;
	if(pattern_occ_idx.size() > 0){
		cout << "Pattern occurrent index: ";
		printArray(pattern_occ_idx);
	}
	else
		cout << "Given pattern doesn't appear in the provided input string" << endl;

	return 0;
}