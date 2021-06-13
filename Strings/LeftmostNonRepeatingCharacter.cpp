#include<bits/stdc++.h>
using namespace std;

constexpr int CHAR = 256;

int getLeftmostNonRepeatingCharIdx(const string& str)
{
	int occ_idx[CHAR];
	fill(occ_idx, occ_idx+CHAR, -1);

	for(int i=0; i<str.length(); i++){
		if(occ_idx[str[i]] == -1) // -1 signifies that the element has not occurres previously
			occ_idx[str[i]] = i; // We update the element index with it's first occurrent
		else
			occ_idx[str[i]] = -2; // -2 signifies a repeating element
	}

	// Now all the positive entries of occ_idx are non-repeating elements, we need to find minimum positive entry idx
	int leftmost_idx = INT_MAX;
	for(int i=0; i<CHAR; i++)
		if(occ_idx[i] >= 0)
			leftmost_idx = min(leftmost_idx, occ_idx[i]);

	return (leftmost_idx == INT_MAX) ? -1: leftmost_idx;
}

int main(){
	string str;

	cout << "Enter input string: ";
	cin >> str;
	cout << "Leftmost non repeating element idx: " << getLeftmostNonRepeatingCharIdx(str) << endl;

	return 0;
}