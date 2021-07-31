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

string infixToPostFix(string infixExpression)
{
	string postfixExpression = "";
	stack<char> operator_dump;

	for(int i=0; i<infixExpression.length(); i++) {
		if(infixExpression[i] == '(')
			operator_dump.push(infixExpression[i]);
		else if(infixExpression[i] == ')') {
			while(operator_dump.top() != '(') {
				postfixExpression += operator_dump.top();
				operator_dump.pop();
			}
			operator_dump.pop();
		}
		else if(isOperator(infixExpression[i])) {
			if(operator_dump.empty() == true)
				operator_dump.push(infixExpression[i]);
			else {
				while(isLowerPrecedence(infixExpression[i], operator_dump.top())) {
					postfixExpression += operator_dump.top();
					operator_dump.pop();
				}
				if(isHigherPrecedence(infixExpression[i], operator_dump.top()))
					operator_dump.push(infixExpression[i]);
				else if(isSamePrecedence(infixExpression[i], operator_dump.top())) {
					if(infixExpression[i] != '^') { // Will process left to right
						string operators = "";
						operators += infixExpression[i];

						while(operator_dump.empty() == false) {
							operators += operator_dump.top();
							operator_dump.pop();
						}

						reverse(operators.begin(), operators.end());
						postfixExpression += operators;
					}
					else
						operator_dump.push(infixExpression[i]);
				}
			}
		}
		else
			postfixExpression += infixExpression[i];
	}

	while(operator_dump.empty() == false) {
		postfixExpression += operator_dump.top();
		operator_dump.pop();
	}

	return postfixExpression;
}

int main() {
	string input_string, output_string;
	operatorPrecedenceTable['('] = -1;
	operatorPrecedenceTable['+'] = 0;
	operatorPrecedenceTable['-'] = 0;
	operatorPrecedenceTable['*'] = 1;
	operatorPrecedenceTable['/'] = 1;
	operatorPrecedenceTable['^'] = 2;

	input_string = "a+b*c";
	cout << "Infix expression: " << input_string << endl;
	output_string = infixToPostFix(input_string);
	cout << "Postfix expression: " << output_string << endl << endl;

	input_string = "(a+b)*c";
	cout << "Infix expression: " << input_string << endl;
	output_string = infixToPostFix(input_string);
	cout << "Postfix expression: " << output_string << endl << endl;
	
	input_string = "a^b^c";
	cout << "Infix expression: " << input_string << endl;
	output_string = infixToPostFix(input_string);
	cout << "Postfix expression: " << output_string << endl << endl;
	
	input_string = "(a+b)*(c+d)";
	cout << "Infix expression: " << input_string << endl;
	output_string = infixToPostFix(input_string);
	cout << "Postfix expression: " << output_string << endl << endl;
	
	input_string = "a*b/c";
	cout << "Infix expression: " << input_string << endl;
	output_string = infixToPostFix(input_string);
	cout << "Postfix expression: " << output_string << endl << endl;
	
	// input_string = "";
	// cout << "Infix expression: " << input_string << endl;
	// output_string = infixToPostFix(input_string);
	// cout << "Postfix expression: " << output_string << endl << endl;
	
	return 0;
}