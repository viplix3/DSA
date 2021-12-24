#include <bits/stdc++.h>
using namespace std;

int getMaxCuts(int rodLength, int cut1, int cut2, int cut3) {
	vector<int> possibleCuts(rodLength + 1, -1);
	possibleCuts[0] = 0; // Cannot make any cut on a rod of length 0

	for(int currRodLength = 1; currRodLength <= rodLength; currRodLength++) {
		if(currRodLength - cut1 >= 0) // rod length > cut size
			possibleCuts[currRodLength] = max(possibleCuts[currRodLength],
												possibleCuts[currRodLength - cut1]);
		if(currRodLength - cut2 >= 0) // rod length > cut size
			possibleCuts[currRodLength] = max(possibleCuts[currRodLength],
												possibleCuts[currRodLength - cut2]);
		if(currRodLength - cut3 >= 0) // rod length > cut size
			possibleCuts[currRodLength] = max(possibleCuts[currRodLength],
												possibleCuts[currRodLength - cut3]);
		if(possibleCuts[currRodLength] != -1)
			possibleCuts[currRodLength] += 1;
	}
	return possibleCuts[rodLength];
}

int main() {
	int rodLength, cut1, cut2, cut3;

	rodLength = 5;
	cut1 = 1, cut2 = 2, cut3 = 3;
	cout << "Rod length: " << rodLength << endl;
	cout << "Allowed cut lengths: " << cut1 << ", " << cut2 << " and " << cut3 << endl;
	cout << "Maximum cuts that can be made: " << getMaxCuts(rodLength, cut1, cut2, cut3) << endl;
	cout << endl;

	rodLength = 23;
	cut1 = 12, cut2 = 11, cut3 = 13;
	cout << "Rod lengths: " << rodLength << endl;
	cout << "Allowed cut length: " << cut1 << ", " << cut2 << " and " << cut3 << endl;
	cout << "Maximum cuts that can be made: " << getMaxCuts(rodLength, cut1, cut2, cut3) << endl;
	cout << endl;

	rodLength = 3;
	cut1 = 2, cut2 = 4, cut3 = 2;
	cout << "Rod lengths: " << rodLength << endl;
	cout << "Allowed cut length: " << cut1 << ", " << cut2 << " and " << cut3 << endl;
	cout << "Maximum cuts that can be made: " << getMaxCuts(rodLength, cut1, cut2, cut3) << endl;
	cout << endl;

	// rodLength = 5;
	// a = 1, b = 2, c = 3;
	// cout << "Rod length: " << rodLength << endl;
	// cout << "Allowed cut length: " << cut1 << ", " << cut2 << " and " << cut3 << endl;
	// cout << "Maximum cuts that can be made: " << getMaxCuts(rodLength, cut1, cut2, cut3) << endl;

	return 0;
}