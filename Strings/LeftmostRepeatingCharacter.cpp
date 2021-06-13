#include<bits/stdc++.h>
using namespace std;

int getLeftmostRepeatingCharIdx(const string& str)
{
	int occ_idx[26];
	fill(occ_idx, occ_idx+26, -1);
	int min_occ_idx = INT_MAX;

	for(int i=0; i<str.length(); i++){
		int first_occ = occ_idx[str[i] - 'a'];
		if(first_occ == -1)
			occ_idx[str[i] - 'a'] = i; // index will only get updated if it has not occurred before, hence first_occ will always have least occ
		else
			min_occ_idx = min(min_occ_idx, first_occ);
	}
	if(min_occ_idx == INT_MAX)
		return -1;
	return min_occ_idx;
}

int main(){
	string str;

	cout << "Enter input string: ";
	cin >> str;
	cout << "Leftmost repeating element idx: " << getLeftmostRepeatingCharIdx(str) << endl;

	return 0;
}