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

int getLargestRectangle(vector<vector<int>> binaryMatrix)
{
	// Consider each row as base of the histogram, all the ones in the column would be the height of the histogram bar
	// Get area for histograms created for each row
	int result = INT_MIN;
	int numRows = binaryMatrix.size(), numCols = binaryMatrix[0].size();
	vector<int> rowHistogram(numCols);

		for(int rowIdx = 0; rowIdx < numRows; rowIdx++) {
			for(int colIdx = 0; colIdx < numCols; colIdx++)
				if(binaryMatrix[rowIdx][colIdx] == 0)
					rowHistogram[colIdx] = 0;
				else
					rowHistogram[colIdx] += binaryMatrix[rowIdx][colIdx];

			result = max(getLargestRectangularArea(rowHistogram), result);
		}
	return result;
}

std::ostream& operator<<(std::ostream& out, std::vector<std::vector<int>> arr)
{
	for(int i=0; i<arr.size(); i++) {
		for(int j=0; j<arr[i].size(); j++)
			out << arr[i][j] << " ";
		out << std::endl;
	}

	return out;
}

int main() {
	vector<vector<int>> test_vector;
	int largestRectangleof1s;

	test_vector = { {0, 1, 1, 0},
					{1, 1, 1, 1},
					{1, 1, 1, 1},
					{1, 1, 0, 0}
				};
	cout << "\nInput matrix" << endl;
	cout << test_vector;
	largestRectangleof1s = getLargestRectangle(test_vector);
	cout << "Largest rectangle with all 1s: " << largestRectangleof1s << endl;


	test_vector = { {0, 1, 1},
					{1, 1, 1},
					{0, 1, 1}
				};
	cout << "\nInput matrix" << endl;
	cout << test_vector;
	largestRectangleof1s = getLargestRectangle(test_vector);
	cout << "Largest rectangle with all 1s: " << largestRectangleof1s << endl;


	test_vector = { {0, 0},
					{0, 0}
				};
	cout << "\nInput matrix" << endl;
	cout << test_vector;
	largestRectangleof1s = getLargestRectangle(test_vector);
	cout << "Largest rectangle with all 1s: " << largestRectangleof1s << endl;


	test_vector = { {1, 1, 1},
				};
	cout << "\nInput matrix" << endl;
	cout << test_vector;
	largestRectangleof1s = getLargestRectangle(test_vector);
	cout << "Largest rectangle with all 1s: " << largestRectangleof1s << endl;

	return 0;
}