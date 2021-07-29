#include <bits/stdc++.h>
using namespace std;

int getLargestRectangularArea(vector<int> hist_bars)
{
	vector<int> prev_smaller_pos, next_smaller_pos;
	stack<int> prev_small_stack, next_small_stack;
	int size = hist_bars.size();

	prev_small_stack.push(0);
	prev_smaller_pos.emplace_back(-1);

	next_small_stack.push(size-1);
	next_smaller_pos.emplace_back(size);

	for(int i=1; i<size; i++) {
		while(prev_small_stack.empty() == false && \
				hist_bars[prev_small_stack.top()] >= hist_bars[i])
			prev_small_stack.pop();

		int prev_pos = prev_small_stack.empty() ? -1 : prev_small_stack.top();
		prev_smaller_pos.emplace_back(prev_pos);
		prev_small_stack.push(i);

		while(next_small_stack.empty() == false && \
				hist_bars[next_small_stack.top()] >= hist_bars[size - (i+1)])
			next_small_stack.pop();
		
		int next_pos = next_small_stack.empty() ? size : next_small_stack.top();
		next_smaller_pos.emplace_back(next_pos);
		next_small_stack.push(size - (i+1));
	}
	reverse(next_smaller_pos.begin(), next_smaller_pos.end());

	int curr_area = INT_MIN, max_area = INT_MIN;
	for(int i=0; i<size; i++) {
		curr_area = hist_bars[i];
		curr_area += (i - prev_smaller_pos[i] - 1) * hist_bars[i];
		curr_area += (next_smaller_pos[i] - i - 1) * hist_bars[i];
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