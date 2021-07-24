#include <bits/stdc++.h>
using namespace std;

bool checkBalancedParenthesis(string str)
{
	stack<char> parenthesis_stack;

	for(int i=0; i<str.length(); i++) {
		if(str[i] == '(' || str[i] == '[' || str[i] == '{')
			parenthesis_stack.push(str[i]);
		else {
			if(str[i] == ')') {
				if(parenthesis_stack.empty() || parenthesis_stack.top() != '(')
					return false;
				else
					parenthesis_stack.pop();
			}
			else if(str[i] == ']') {
				if(parenthesis_stack.empty() || parenthesis_stack.top() != '[')
					return false;
				else
					parenthesis_stack.pop();
			}
			else if(str[i] == '}') {
				if(parenthesis_stack.empty() || parenthesis_stack.top() != '{')
					return false;
				else
					parenthesis_stack.pop();
			}
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