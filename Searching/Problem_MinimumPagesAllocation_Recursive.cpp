#include<bits/stdc++.h>
using namespace std;

int getMinimumPagesAllocation(vector<int> &arr, int numElements, int numStudents)
{
    /*
        We have to allocate how many pages a student must read so that all the books are read
        given the following constrains
         - The page allocation should be such that the maximum pages allocated
            to a student must be minimum of the maximum of all the possible permuatations of page
            allocation (minimize the maximum pages allocated).
         - Only contihous pages can be allocated to any student.
    */

    if(numStudents==1)
        return accumulate(arr.begin(), arr.begin()+numElements, 0);
    if(numElements == 1)
        return arr[0];
    
    int minMaxPages = INT_MAX;
    for(int partitionCutIdx=1; partitionCutIdx<numElements; partitionCutIdx++)
        minMaxPages = min(minMaxPages, 
                            max(getMinimumPagesAllocation(arr, partitionCutIdx, numStudents-1), 
                                accumulate(arr.begin()+partitionCutIdx, arr.begin()+numElements, 0)));
    
    return minMaxPages;
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
            getMinimumPagesAllocation(test_arr_1, test_arr_1.size(), numStudents));

    numStudents = 1;
    printf("\nPages in the book: ");
    printArray(test_arr_2);
    printf("For all the permutations of page allocation, minimum of the maximum number of pages any "
            "of the %d students can read so that all the books are read: %d\n", numStudents, 
            getMinimumPagesAllocation(test_arr_2, test_arr_2.size(), numStudents));

    numStudents = 3;
    printf("\nPages in the book: ");
    printArray(test_arr_3);
    printf("For all the permutations of page allocation, minimum of the maximum number of pages any "
            "of the %d students can read so that all the books are read: %d\n", numStudents, 
            getMinimumPagesAllocation(test_arr_3, test_arr_3.size(), numStudents));


    numStudents = 2;
    printf("\nPages in the book: ");
    printArray(test_arr_4);
    printf("For all the permutations of page allocation, minimum of the maximum number of pages any "
            "of the %d students can read so that all the books are read: %d\n", numStudents, 
            getMinimumPagesAllocation(test_arr_4, test_arr_4.size(), numStudents));
    return 0;

}