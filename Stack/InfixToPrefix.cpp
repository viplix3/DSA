#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> operatorPrecedenceTable;

bool isSamePrecedence(char op1, char op2)
{
	return (operatorPrecedenceTable[op1] == operatorPrecedenceTable[op2]);
}

bool isHigherPrecedence(char op1, char op2)
{
	return (operatorPrecedenceTable[op1] > operatorPrecedenceTable[op2]);
}

bool isLowerPrecedence(char op1, char op2)
{
	return (operatorPrecedenceTable[op1] < operatorPrecedenceTable[op2]);
}

bool isOperator(char input)
{
	return (operatorPrecedenceTable.find(input) != operatorPrecedenceTable.end());
}

string infixToPreFix(string infixExpression)
{
	string prefixExpression = "";
	stack<char> operator_dump;

	for(int i = infixExpression.length()-1; i >= 0; i--) {
		if(infixExpression[i] == ')')
			operator_dump.push(infixExpression[i]);
		else if(infixExpression[i] == '(') {
			while(operator_dump.top() != ')') {
				prefixExpression += operator_dump.top();
				operator_dump.pop();
			}
			operator_dump.pop();
		}
		else if(isOperator(infixExpression[i])) {
			while(operator_dump.empty() == false && \
					isLowerPrecedence(infixExpression[i], operator_dump.top())) {
				prefixExpression += operator_dump.top();
				operator_dump.pop();
			}
			if(operator_dump.empty() || isHigherPrecedence(infixExpression[i], operator_dump.top()))
				operator_dump.push(infixExpression[i]);
			else if(isSamePrecedence(infixExpression[i], operator_dump.top())) {
				if(infixExpression[i] != '^') { // Will process left to right
					operator_dump.push(infixExpression[i]);
				}
				else {
					prefixExpression += operator_dump.top();
					operator_dump.pop();
					operator_dump.push(infixExpression[i]);
				}
			}
		}
		else
			prefixExpression += infixExpression[i];
	}

	while(operator_dump.empty() == false) {
		prefixExpression += operator_dump.top();
		operator_dump.pop();
	}

	reverse(prefixExpression.begin(), prefixExpression.end());
	return prefixExpression;
}

int main() {
	string input_string, output_string;
	operatorPrecedenceTable['('] = -1;
	operatorPrecedenceTable[')'] = -1;
	operatorPrecedenceTable['+'] = 0;
	operatorPrecedenceTable['-'] = 0;
	operatorPrecedenceTable['*'] = 1;
	operatorPrecedenceTable['/'] = 1;
	operatorPrecedenceTable['^'] = 2;

	input_string = "a+b*c";
	cout << "Infix expression: " << input_string << endl;
	output_string = infixToPreFix(input_string);
	cout << "Prefix expression: " << output_string << endl << endl;

	input_string = "(a+b)*c";
	cout << "Infix expression: " << input_string << endl;
	output_string = infixToPreFix(input_string);
	cout << "Prefix expression: " << output_string << endl << endl;
	
	input_string = "a^b^c";
	cout << "Infix expression: " << input_string << endl;
	output_string = infixToPreFix(input_string);
	cout << "Prefix expression: " << output_string << endl << endl;
	
	input_string = "(a+b)*(c+d)";
	cout << "Infix expression: " << input_string << endl;
	output_string = infixToPreFix(input_string);
	cout << "Prefix expression: " << output_string << endl << endl;
	
	input_string = "a*b/c";
	cout << "Infix expression: " << input_string << endl;
	output_string = infixToPreFix(input_string);
	cout << "Prefix expression: " << output_string << endl << endl;
	
	input_string = "a+b/c-d*e";
	cout << "Infix expression: " << input_string << endl;
	output_string = infixToPreFix(input_string);
	cout << "Prefix expression: " << output_string << endl << endl;
	
	return 0;
}