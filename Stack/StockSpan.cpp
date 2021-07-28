#include <bits/stdc++.h>
using namespace std;

vector<int> getStockSpan(vector<int> stockPrice)
{
	vector<int> stock_span;
	stack<int> prev_max_stack;
	prev_max_stack.push(0); // Idx of 1st element
	stock_span.emplace_back(1);

	for(int i=1; i<stockPrice.size(); i++) {
		while(prev_max_stack.empty() == false && stockPrice[prev_max_stack.top()] <= stockPrice[i])
			prev_max_stack.pop();

		int curr_span = prev_max_stack.empty() ? i+1 : i - prev_max_stack.top();
		stock_span.emplace_back(curr_span);
		prev_max_stack.push(i);
	}
	return stock_span;
}

std::ostream& operator<<(std::ostream& out, vector<int> data)
{
	for(int i=0; i<data.size(); i++)
		out << data[i] << " ";

	return out;
}

int main() {
	vector<int> test_vector;
	vector<int> stock_span;

	test_vector = {13, 15, 12, 14, 16, 8, 6, 4, 10, 30};
	// {1, 2, 1, 2, 5, 1, 1, 1, 4, 10}
	printf("\nInput array: ");
	cout << test_vector << endl;
	stock_span = getStockSpan(test_vector);
	printf("Stock span: ");
	cout << stock_span << endl;

	test_vector = {10, 20, 30, 40};
	// {1, 2, 3, 4}
	printf("\nInput array: ");
	cout << test_vector << endl;
	stock_span = getStockSpan(test_vector);
	printf("Stock span: ");
	cout << stock_span << endl;

	test_vector = {40, 30, 20, 10};
	// {1, 1, 1, 1}
	printf("\nInput array: ");
	cout << test_vector << endl;
	stock_span = getStockSpan(test_vector);
	printf("Stock span: ");
	cout << stock_span << endl;

	test_vector = {30, 20, 25, 28, 27, 29};
	// {1, 1, 2, 3, 1, 5}
	printf("\nInput array: ");
	cout << test_vector << endl;
	stock_span = getStockSpan(test_vector);
	printf("Stock span: ");
	cout << stock_span << endl;

	test_vector = {10, 30, 24, 23, 25, 29};
	// {1, 2, 1, 1, 3, 4}
	printf("\nInput array: ");
	cout << test_vector << endl;
	stock_span = getStockSpan(test_vector);
	printf("Stock span: ");
	cout << stock_span << endl;

	test_vector = {60, 10, 20, 40, 35, 30, 50, 70, 75};
	// {1, 1, 2, 3, 1, 1, 6, 8, 9}
	printf("\nInput array: ");
	cout << test_vector << endl;
	stock_span = getStockSpan(test_vector);
	printf("Stock span: ");
	cout << stock_span << endl;

	return 0;
}