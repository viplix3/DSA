#include <bits/stdc++.h>
using namespace std;

int getEditDistance(string fromString, int fromStringIdx, string toString, int toStringIdx) {
	if(fromStringIdx == 0 || toStringIdx == 0)
		return max(fromStringIdx, toStringIdx);

	if(fromString[fromStringIdx - 1] == toString[toStringIdx - 1])
		return getEditDistance(fromString, fromStringIdx - 1, toString, toStringIdx - 1);
	else
		return 1 + min({ getEditDistance(fromString, fromStringIdx - 1, toString, toStringIdx), // Remove current char
							getEditDistance(fromString, fromStringIdx, toString, toStringIdx - 1), // Add new char
							getEditDistance(fromString, fromStringIdx - 1, toString, toStringIdx - 1) }); // Replace current char
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