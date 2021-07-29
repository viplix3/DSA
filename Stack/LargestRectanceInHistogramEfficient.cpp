#include <bits/stdc++.h>
using namespace std;

int getLargestRectangularArea(vector<int> hist_bars)
{
	stack<int> smaller_than_current;
	int size = hist_bars.size();
	int curr_area = INT_MIN, max_area = INT_MIN;

	for(int i=0; i<size; i++) {
		while(smaller_than_current.empty() == false && \
				hist_bars[smaller_than_current.top()] >= hist_bars[i]) {
			// Removing the item from the stack which is greater than the current element
			int include_idx = smaller_than_current.top();
			smaller_than_current.pop();

			// Calculating the area of the rectangle which can be formed considering the removed element as the smallest
			// Element at the index on the top of the stack is the previous smallest for the removed element
			// Element at the current loop index is the next smallest for the removed element
			curr_area = hist_bars[include_idx] * \
						(smaller_than_current.empty() ? i : (i - smaller_than_current.top() - 1));
			max_area = max(curr_area, max_area);
		}
		smaller_than_current.push(i);
	}

	// These are the elements not having any next smallest, so all the elements of the right would contribute to the area
	while(smaller_than_current.empty() == false) {
		int include_idx = smaller_than_current.top();
		smaller_than_current.pop();

		curr_area = hist_bars[include_idx] * \
					(smaller_than_current.empty() ? size : (size - smaller_than_current.top() - 1));
		max_area = max(curr_area, max_area);
	}

	return max_area;
}

std::ostream& operator<<(std::ostream& out, std::vector<int> arr)
{
	for(int i=0; i<arr.size(); i++)
		out << arr[i] << " ";
	return out;
}

int main() {
	vector<int> test_vector;
	int largestRectangularArea;

	test_vector = {6, 2, 5, 4, 1, 5, 6};
	cout << "\nHistogram bar lengths: " << test_vector << endl;
	largestRectangularArea = getLargestRectangularArea(test_vector);
	cout << "Largest rectangular area for given histogram bars (of unit width) is: "\
		<< largestRectangularArea << endl;
	
	test_vector = {2, 5, 1};
	cout << "\nHistogram bar lengths: " << test_vector << endl;
	largestRectangularArea = getLargestRectangularArea(test_vector);
	cout << "Largest rectangular area for given histogram bars (of unit width) is: "\
		<< largestRectangularArea << endl;

	return 0;
}