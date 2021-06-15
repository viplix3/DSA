#include<bits/stdc++.h>
using namespace std;

vector<int> naive_distinct_pattern_matching(string input_str, string pattern)
{
	vector<int> matched_indice;
	int i=0;

	while(i <= input_str.length() - pattern.length()){
		int num_matched_chars;

		for(num_matched_chars=0; num_matched_chars < pattern.length(); num_matched_chars++)
			if(pattern[num_matched_chars] != input_str[i+num_matched_chars])
				break;

		if(num_matched_chars == pattern.length())
			matched_indice.emplace_back(i);

		i += num_matched_chars;

		if(num_matched_chars == 0)
			i += 1;
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

	input_str = "ABCABCDABCD";
	pattern = "ABCD";
	pattern_occ_idx = naive_distinct_pattern_matching(input_str, pattern);
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
	pattern_occ_idx = naive_distinct_pattern_matching(input_str, pattern);
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
	pattern_occ_idx = naive_distinct_pattern_matching(input_str, pattern);
	cout << "\nInput string: " << input_str << endl;
	cout << "Search pattern: " << pattern << endl;
	if(pattern_occ_idx.size() > 0){
		cout << "Pattern occurrent index: ";
		printArray(pattern_occ_idx);
	}
	else
		cout << "Given pattern doesn't appear in the provided input string" << endl;

	// input_str = "ABCDABCDABC";
	// pattern = "ABCD";
	// pattern_occ_idx = naive_distinct_pattern_matching(input_str, pattern);
	// cout << "\nInput string: " << input_str << endl;
	// cout << "Search pattern: " << pattern << endl;
	// if(pattern_occ_idx.size() > 0){
	// 	cout << "Pattern occurrent index: ";
	// 	printArray(pattern_occ_idx);
	// }
	// else
	// 	cout << "Given pattern doesn't appear in the provided input string" << endl;

	return 0;
}