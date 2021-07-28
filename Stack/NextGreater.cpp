#include <bits/stdc++.h>
using namespace std;

vector<int> getNextGreater(vector<int> arr)
{
	int size = arr.size();
	vector<int> next_greater;
	stack<int> next_max_stack;

	next_max_stack.push(arr[size-1]);
	next_greater.emplace_back(-1);

	for(int i = size-2; i >= 0; i--) {
		while(next_max_stack.empty() == false && next_max_stack.top() <= arr[i])
			next_max_stack.pop();

		int next_max = next_max_stack.empty() ? -1 : next_max_stack.top();
		next_greater.emplace_back(next_max);
		next_max_stack.push(arr[i]);
	}

	reverse(next_greater.begin(), next_greater.end());
	return next_greater;
}


std::ostream& operator<<(std::ostream& out, vector<int> data)
{
	for(int i=0; i<data.size(); i++)
		out << data[i] << " ";

	return out;
}

int main() {
	vector<int> test_vector;
	vector<int> next_max;

	test_vector = {15, 10, 18, 12, 4, 6, 2, 8};
	printf("\nInput array: ");
	cout << test_vector << endl;
	next_max = getNextGreater(test_vector);
	printf("Next closest max: ");
	cout << next_max << endl;

	test_vector = {8, 10, 12};
	printf("\nInput array: ");
	cout << test_vector << endl;
	next_max = getNextGreater(test_vector);
	printf("Next closest max: ");
	cout << next_max << endl;

	test_vector = {12, 10, 8};
	printf("\nInput array: ");
	cout << test_vector << endl;
	next_max = getNextGreater(test_vector);
	printf("Next closest max: ");
	cout << next_max << endl;

	test_vector = {30, 20, 25, 28, 27, 29};
	printf("\nInput array: ");
	cout << test_vector << endl;
	next_max = getNextGreater(test_vector);
	printf("Next closest max: ");
	cout << next_max << endl;

	test_vector = {20, 30, 10, 5, 15};
	printf("\nInput array: ");
	cout << test_vector << endl;
	next_max = getNextGreater(test_vector);
	printf("Next closest max: ");
	cout << next_max << endl;

	test_vector = {5, 15, 10, 8, 6, 12, 9, 18};
	printf("\nInput array: ");
	cout << test_vector << endl;
	next_max = getNextGreater(test_vector);
	printf("Next closest max: ");
	cout << next_max << endl;

	return 0;
}