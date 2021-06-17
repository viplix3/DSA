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