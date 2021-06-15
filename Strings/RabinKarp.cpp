#include<bits/stdc++.h>
using namespace std;

constexpr int MODULO_CONST = 10000007;

vector<int> RabinKarp(string input_str, string pattern)
{
	vector<int> matched_indice;
	int hash_constant = 1, rolling_hash = 0, pattern_hash = 0;
	int hash_factor = pattern.length();

	for(int i=1; i<pattern.length(); i++)
		hash_constant = (hash_constant * hash_factor) % MODULO_CONST;

	for(int i=0; i<pattern.length(); i++){
		rolling_hash = (rolling_hash * hash_factor + input_str[i]) % MODULO_CONST;
		pattern_hash = (pattern_hash * hash_factor + pattern[i]) % MODULO_CONST;
	}

	for(int i=0; i <= input_str.length() - pattern.length(); i++){
		if(pattern_hash == rolling_hash){
			bool matched_flag = true;

			for(int num_matched_chars=0; num_matched_chars < pattern.length(); num_matched_chars++)
				if(pattern[num_matched_chars] != input_str[i+num_matched_chars]){
					matched_flag = false;
					break;
				}

			if(matched_flag)
				matched_indice.emplace_back(i);
		}

		if(i < input_str.length() - pattern.length()){
			rolling_hash = ((hash_factor * (rolling_hash - input_str[i] * hash_constant)) + input_str[i + pattern.length()]) % MODULO_CONST;

			if(rolling_hash < 0)
				rolling_hash = rolling_hash + MODULO_CONST;
		}
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
	pattern_occ_idx = RabinKarp(input_str, pattern);
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
	pattern_occ_idx = RabinKarp(input_str, pattern);
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
	pattern_occ_idx = RabinKarp(input_str, pattern);
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
	pattern_occ_idx = RabinKarp(input_str, pattern);
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