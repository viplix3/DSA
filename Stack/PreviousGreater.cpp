#include <bits/stdc++.h>
using namespace std;

vector<int> getPreviousGreater(vector<int> arr)
{
	vector<int> previous_greater;
	stack<int> prev_max_stack;
	prev_max_stack.push(arr[0]); // Idx of 1st element
	previous_greater.emplace_back(-1);

	for(int i=1; i<arr.size(); i++) {
		while(prev_max_stack.empty() == false && prev_max_stack.top() <= arr[i])
			prev_max_stack.pop();

		int curr_max = prev_max_stack.empty() ? -1 : prev_max_stack.top();
		previous_greater.emplace_back(curr_max);
		prev_max_stack.push(arr[i]);
	}
	return previous_greater;
}

std::ostream& operator<<(std::ostream& out, vector<int> data)
{
	for(int i=0; i<data.size(); i++)
		out << data[i] << " ";

	return out;
}

int main() {
	vector<int> test_vector;
	vector<int> previous_max;

	test_vector = {15, 10, 18, 12, 4, 6, 2, 8};
	printf("\nInput array: ");
	cout << test_vector << endl;
	previous_max = getPreviousGreater(test_vector);
	printf("Previous closest max: ");
	cout << previous_max << endl;

	test_vector = {8, 10, 12};
	printf("\nInput array: ");
	cout << test_vector << endl;
	previous_max = getPreviousGreater(test_vector);
	printf("Previous closest max: ");
	cout << previous_max << endl;

	test_vector = {12, 10, 8};
	printf("\nInput array: ");
	cout << test_vector << endl;
	previous_max = getPreviousGreater(test_vector);
	printf("Previous closest max: ");
	cout << previous_max << endl;

	test_vector = {30, 20, 25, 28, 27, 29};
	printf("\nInput array: ");
	cout << test_vector << endl;
	previous_max = getPreviousGreater(test_vector);
	printf("Previous closest max: ");
	cout << previous_max << endl;

	test_vector = {20, 30, 10, 5, 15};
	printf("\nInput array: ");
	cout << test_vector << endl;
	previous_max = getPreviousGreater(test_vector);
	printf("Previous closest max: ");
	cout << previous_max << endl;

	test_vector = {60, 10, 20, 40, 35, 30, 50, 70, 75};
	printf("\nInput array: ");
	cout << test_vector << endl;
	previous_max = getPreviousGreater(test_vector);
	printf("Previous closest max: ");
	cout << previous_max << endl;

	return 0;
}