#include <bits/stdc++.h>
using namespace std;

int getEditDistance(string fromString, int fromStringLength, string toString, int toStringLength) {
	vector<vector<int>> editDistance(toStringLength + 1, vector<int>(fromStringLength + 1, 0));

	for(int i = 0; i <= fromStringLength; i++)
		editDistance[0][i] = i;

	for(int i = 1; i <= toStringLength; i++)
		editDistance[i][0] = i;

	for(int toStringIdx = 1; toStringIdx <= toStringLength; toStringIdx++)
		for(int fromStringIdx = 1; fromStringIdx <= fromStringLength; fromStringIdx++) {
			if(fromString[fromStringIdx - 1] == toString[toStringIdx - 1])
				editDistance[toStringIdx][fromStringIdx] = editDistance[toStringIdx - 1][fromStringIdx - 1];
			else
				editDistance[toStringIdx][fromStringIdx] = 1 + min({ editDistance[toStringIdx][fromStringIdx - 1],
																	editDistance[toStringIdx - 1][fromStringIdx],
																	editDistance[toStringIdx - 1][fromStringIdx - 1] });
		}
	
	return editDistance[toStringLength][fromStringLength];
}

int main() {
	string fromString, toString;

	fromString = "CAT";
	toString = "CUT";
	cout << "# Operations required to convert " << fromString << " to " << toString << " using ADD/REMOVE/REPLACE operations: ";
	cout << getEditDistance(fromString, fromString.length(), toString, toString.length()) << endl;
	cout << endl;

	fromString = "GEEK";
	toString = "GEEKS";
	cout << "# Operations required to convert " << fromString << " to " << toString << " using ADD/REMOVE/REPLACE operations: ";
	cout << getEditDistance(fromString, fromString.length(), toString, toString.length()) << endl;
	cout << endl;

	fromString = "SATURDAY";
	toString = "SUNDAY";
	cout << "# Operations required to convert " << fromString << " to " << toString << " using ADD/REMOVE/REPLACE operations: ";
	cout << getEditDistance(fromString, fromString.length(), toString, toString.length()) << endl;
	cout << endl;

	return 0;
}