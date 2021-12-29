#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> arr, int beginIdx, int endIdx) {
	int sum = 0;
	for(int i = beginIdx; i <= endIdx; i++)
		sum += arr[i];
	
	return sum;
}

int getMinimumPagesAllocation(vector<int> numPages, int numStudents) {
	int totalBooks = numPages.size();
	vector<vector<int>> allocatedPages(numStudents + 1, vector<int>(totalBooks + 1, 0));

	for(int bookIdx = 1; bookIdx <= totalBooks; bookIdx++) // Base case: Only single person to read all books
		allocatedPages[1][bookIdx] = allocatedPages[1][bookIdx - 1] + numPages[bookIdx - 1];
	
	for(int studentIdx = 1; studentIdx <= numStudents; studentIdx++)
		allocatedPages[studentIdx][1] = numPages[0]; // Base case: only single book to be read by all the students
	
	for(int studentIdx = 2; studentIdx <= numStudents; studentIdx++) {
		for(int bookIdx = 2; bookIdx <= totalBooks; bookIdx++) {

			int currAllocation = INT_MAX;
			for(int k = 1; k < bookIdx; k++)
				currAllocation = min( max(allocatedPages[studentIdx-1][k],
									  sum(numPages, k, bookIdx - 1)),
									  currAllocation);
			allocatedPages[studentIdx][bookIdx] = currAllocation;
		}
	}

	return allocatedPages[numStudents][totalBooks];
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_arr_1 = {20, 20, 40, 40};
    vector<int> test_arr_2 = {10, 20, 30};
    vector<int> test_arr_3 = {10, 5, 30, 1, 2, 5, 10, 10};
    vector<int> test_arr_4 = {40, 20, 10, 13};
    int numStudents;

    numStudents = 2;
    printf("\nPages in the book: ");
    printArray(test_arr_1);
    printf("For all the permutations of page allocation, minimum of the maximum number of pages any "
            "of the %d students can read so that all the books are read: %d\n", numStudents, 
            getMinimumPagesAllocation(test_arr_1, numStudents));

    numStudents = 2;
    printf("\nPages in the book: ");
    printArray(test_arr_2);
    printf("For all the permutations of page allocation, minimum of the maximum number of pages any "
            "of the %d students can read so that all the books are read: %d\n", numStudents, 
            getMinimumPagesAllocation(test_arr_2, numStudents));

    numStudents = 3;
    printf("\nPages in the book: ");
    printArray(test_arr_3);
    printf("For all the permutations of page allocation, minimum of the maximum number of pages any "
            "of the %d students can read so that all the books are read: %d\n", numStudents, 
            getMinimumPagesAllocation(test_arr_3, numStudents));


    numStudents = 2;
    printf("\nPages in the book: ");
    printArray(test_arr_4);
    printf("For all the permutations of page allocation, minimum of the maximum number of pages any "
            "of the %d students can read so that all the books are read: %d\n", numStudents, 
            getMinimumPagesAllocation(test_arr_4, numStudents));

    return 0;
}