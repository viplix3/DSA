#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>> matrix)
{
	int rows = matrix.size(), cols = matrix[0].size();

	// Find matrix min and max to define the search range
	int matrix_min = matrix[0][0], matrix_max = matrix[0][0];

	// As matrix is row-wise sorted, the min element would be one of the entries on 0th column
	// and max element would be one of the entries of the last column
	for(int i=0; i<rows; i++) {
		matrix_min = min(matrix_min, matrix[i][0]);
		matrix_max = max(matrix_max, matrix[i][cols - 1]);
	}

	// Get median position on the basis of number of elements in the matrix
	// It has been assumed that array is having odd number of elements and all elements are distinct
	// TODO: Generalize
	int median_position = (rows * cols + 1) / 2;

	while(matrix_min < matrix_max) {
		// This is our current candidate for median
		// This will be a median when its position in unrolled and sorted matrix is same as median
		int matrix_mid = (matrix_min + matrix_max) / 2;
		int matrix_mid_position = 0;

		// Calculating the matrix_mid position when the matirx is unrolled into a 1D array
		// This is done by checking number of elements smaller than matrix_mid in each row
		for(int i=0; i<rows; i++) // We can apply binary seach for each row as matrix is row wise sorted
			// Upper bound here will return the number of elements <= matrix_mid in each row
			// matrix_mid_position will be addition of all these numbers
			matrix_mid_position += upper_bound(matrix[i].begin(), matrix[i].end(), matrix_mid) - matrix[i].begin();

		// If the matrix_mid_position is less than the median position, we would skip the 1st half of the unrolled 1D array
		// We need to include mid in one of the cases as we might end up with an element which isn't there in the matrix
		if(matrix_mid_position < median_position)
			matrix_min = matrix_mid + 1;
		else
			matrix_max = matrix_mid; 
	}
	return matrix_min;
}

void print2DArray(vector<vector<int>> &arr)
{
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

int main() {
    vector<vector<int>> testArray1 = {{5, 10, 20, 30, 40},
                                      {1, 2, 3, 4, 6},
                                      {11, 13, 15, 17, 19}};

    vector<vector<int>> testArray2 = {{1, 10, 20},
                                      {15, 25, 35},
                                      {5, 30, 40}};

    vector<vector<int>> testArray3 = {{2, 4, 5, 8, 10},
                                      {1, 3, 5, 7, 9},
                                      {100, 200, 400, 500, 800}};

    printf("\nContents of the original array\n");
    print2DArray(testArray1);
    printf("Median of the provided row-wise sorted array is: %d\n", findMedian(testArray1));

    printf("\nContents of the original array\n");
    print2DArray(testArray2);
    printf("Median of the provided row-wise sorted array is: %d\n", findMedian(testArray2));

	printf("\nContents of the original array\n");
    print2DArray(testArray3);
    printf("Median of the provided row-wise sorted array is: %d\n", findMedian(testArray3));

	return 0;
}