#include <bits/stdc++.h>
using namespace std;

int applyOperator(int op1, int op2, char op)
{
	int result;

	switch(op) {
		case '+':	result = op1 + op2;
					break;
		case '-':	result = op1 - op2;
					break;
		case '*':	result = op1 * op2;
					break;
		case '/':	result = op1 / op2;
					break;
		case '^':	result = pow(op1, op2);
					break;
		default:	cerr << "Non supported operator" << endl;
					break;
	}

	return result;
}

bool isOperator(char input)
{
	return (input == '+' ||
			input == '-' ||
			input == '*' ||
			input == '/' ||
			input == '^');
}

int evaluatePostfix(string expression)
{
	stack<int> operands;
	string current_parsed_operand = "";

	for(int i=0; i<expression.length(); i++) {
		if(isOperator(expression[i])) {
			int operand_1 = operands.top();
			operands.pop();

			int operand_2 = operands.top();
			operands.pop();

			int result = applyOperator(operand_1, operand_2, expression[i]);
			operands.push(result);
		}
		else if(isdigit(expression[i]))
			current_parsed_operand += expression[i];
		else {
			if(current_parsed_operand != "") {
				operands.push(stoi(current_parsed_operand));
				current_parsed_operand = "";
			}
		}
	}

	return operands.top();
}


int main() {
	string postfixExpression;

	postfixExpression = "10 2 * 3 +";
	cout << postfixExpression << " = " << evaluatePostfix(postfixExpression) << "\n\n";

	postfixExpression = "10 2 + 3 *";
	cout << postfixExpression << " = " << evaluatePostfix(postfixExpression) << "\n\n";

	postfixExpression = "5 2 3 ^ ^";
	cout << postfixExpression << " = " << evaluatePostfix(postfixExpression) << "\n\n";

	return 0;
}