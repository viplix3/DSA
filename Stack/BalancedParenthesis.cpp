#include <bits/stdc++.h>
using namespace std;

bool is_matching(char ch1, char ch2)
{
	return (
			(ch1 == '(' && ch2 == ')') ||
			(ch1 == '{' && ch2 == '}') ||
			(ch1 == '[' && ch2 == ']')
			);
}

bool checkBalancedParenthesis(string str)
{
	stack<char> parenthesis_stack;

	for(int i=0; i<str.length(); i++) {
		if(str[i] == '(' || str[i] == '[' || str[i] == '{')
			parenthesis_stack.push(str[i]);
		else {
			if(parenthesis_stack.empty())
				return false;
			else if(is_matching(parenthesis_stack.top(), str[i]) == false)
				return false;
			else
				parenthesis_stack.pop();
		}
	}
	if(!parenthesis_stack.empty())
		return false;
	return true;
}

int main() {
	string input;
	cout << "\nEnter the input parenthesis string: ";
	cin >> input;

	bool balanced = checkBalancedParenthesis(input);
	if(balanced)
		cout << "Input string is having balanced parenthesis" << endl;
	else
		cout << "Input string is having imbalanced parenthesis" << endl;
	
	return 0;
}