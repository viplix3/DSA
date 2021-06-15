#include<bits/stdc++.h>
using namespace std;

void reverse(string &str, int beginIdx, int endIdx)
{
	while(beginIdx <= endIdx){
		swap(str[beginIdx], str[endIdx]);
		beginIdx++;
		endIdx--;
	}
}

void reverse_string_words(string &str)
{
	int startIdx = 0;
	for(int endIdx = 0; endIdx < str.length(); endIdx++){
		if(str[endIdx] == ' '){
			reverse(str, startIdx, endIdx-1);
			startIdx = endIdx+1;
		}
	}
	reverse(str, startIdx, str.length()-1); // Reversing last word
	reverse(str, 0, str.length()-1); // reversing the reversed string
}

int main(){
	string input_str;

	cout << "Enter the input string: ";
	getline(cin, input_str);

	reverse_string_words(input_str);
	cout << "String after words reversal" << endl;
	cout << input_str << endl;

	return 0;
}