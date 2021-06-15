#include<bits/stdc++.h>
using namespace std;

vector<int> naive_patter_matching(string input_str, string pattern)
{
	vector<int> matched_indice;

	for(int i=0; i <= input_str.length() + pattern.length(); i++){
		int num_matched_chars;

		for(num_matched_chars=0; num_matched_chars<pattern.length(); num_matched_chars++)
			if(pattern[num_matched_chars] != input_str[i+num_matched_chars])
				break;

		if(num_matched_chars == pattern.length())
			matched_indice.emplace_back(i);
	}

	return matched_indice;
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

	input_str = "ABABABCD";
	pattern = "ABAB";
	pattern_occ_idx = naive_patter_matching(input_str, pattern);
	cout << "\nInput string: " << input_str << endl;
	cout << "Search pattern: " << pattern << endl;
	if(pattern_occ_idx.size() > 0){
		cout << "Pattern occurrent index: ";
		printArray(pattern_occ_idx);
	}
	else
		cout << "Given pattern doesn't appear in the provided input string" << endl;

	input_str = "ABCABCD";
	pattern = "ABDC";
	pattern_occ_idx = naive_patter_matching(input_str, pattern);
	cout << "\nInput string: " << input_str << endl;
	cout << "Search pattern: " << pattern << endl;
	if(pattern_occ_idx.size() > 0){
		cout << "Pattern occurrent index: ";
		printArray(pattern_occ_idx);
	}
	else
		cout << "Given pattern doesn't appear in the provided input string" << endl;

	input_str = "AAAAA";
	pattern = "AAA";
	pattern_occ_idx = naive_patter_matching(input_str, pattern);
	cout << "\nInput string: " << input_str << endl;
	cout << "Search pattern: " << pattern << endl;
	if(pattern_occ_idx.size() > 0){
		cout << "Pattern occurrent index: ";
		printArray(pattern_occ_idx);
	}
	else
		cout << "Given pattern doesn't appear in the provided input string" << endl;

	input_str = "ABCDABCDABC";
	pattern = "ABCD";
	pattern_occ_idx = naive_patter_matching(input_str, pattern);
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