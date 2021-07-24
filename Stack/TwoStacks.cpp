#include <bits/stdc++.h>
using namespace std;

template<size_t stack_size>
class TwoStacks
{
private:
	int stack_1_top = -1;
	int stack_2_top = stack_size;
	int stack_arr[stack_size];

public:
	void stack_one_push(int data)
	{
		if(stack_1_top+1 >= stack_2_top) {
			cerr << "No space left to push elements" << endl;
			return;
		}
		else {
			stack_1_top += 1;
			stack_arr[stack_1_top] = data;
		}
	}

	void stack_two_push(int data)
	{
		if(stack_2_top-1 <= stack_1_top) {
			cerr << "No space left to push elements" << endl;
			return;
		}
		else {
			stack_2_top -= 1;
			stack_arr[stack_2_top] = data;
		}
	}

	int stack_one_pop()
	{
		if(stack_1_top < 0)
			return INT_MIN;
		else {
			int data_item = stack_arr[stack_1_top];
			stack_1_top -= 1;
			return data_item;
		}
	}

	int stack_two_pop()
	{
		if(stack_2_top >= stack_size)
			return INT_MIN;
		else {
			int data_item = stack_arr[stack_2_top];
			stack_2_top += 1;
			return data_item;
		}
	}

};


int main() {
	int data;
	TwoStacks<5> TwoStackObj;

	cout << "\nTrying pop on empty stacks" << endl;
	data = TwoStackObj.stack_one_pop();
	data = TwoStackObj.stack_two_pop();

	cout << "\nEnter item to be pushed into stack 1: ";
	cin >> data;
	TwoStackObj.stack_one_push(data);

	cout << "Enter item to be pushed into stack 1: ";
	cin >> data;
	TwoStackObj.stack_one_push(data);

	cout << "Enter item to be pushed into stack 1: ";
	cin >> data;
	TwoStackObj.stack_one_push(data);

	cout << "\nEnter item to be pushed into stack 2: ";
	cin >> data;
	TwoStackObj.stack_two_push(data);

	cout << "Enter item to be pushed into stack 2: ";
	cin >> data;
	TwoStackObj.stack_two_push(data);

	cout << "Enter item to be pushed into stack 2: ";
	cin >> data;
	TwoStackObj.stack_two_push(data);

	cout << "\nEnter item to be pushed into stack 1: ";
	cin >> data;
	TwoStackObj.stack_one_push(data);

	cout << "\nStack 1 data" << endl;
	int pop_data = TwoStackObj.stack_one_pop();
	while(pop_data != INT_MIN) {
		cout << pop_data << " ";
		pop_data = TwoStackObj.stack_one_pop();
	}
	cout << endl;

	cout << "\nStack 2 data" << endl;
	pop_data = TwoStackObj.stack_two_pop();
	while(pop_data != INT_MIN) {
		cout << pop_data << " ";
		pop_data = TwoStackObj.stack_two_pop();
	}
	cout << endl;


	return 0;
}