#include<bits/stdc++.h>
using namespace std;

bool isFeasible(vector<int> &arr, int numStudents, int candidateSolution)
{
    int currentSum = 0;

    for(int i=0; i<arr.size(); i++){
        if(currentSum+arr[i] > candidateSolution){
            currentSum = arr[i];
            numStudents -= 1;
        }
        else
            currentSum += arr[i];
        if(numStudents <= 0)
            return false;
    }
    return true;
}

int getMinimumPagesAllocation(vector<int> &arr, int numStudents)
{
    /*
        We have to allocate how many pages a student must read so that all the books are read
        given the following constrains
         - The page allocation should be such that the maximum pages allocated
            to a student must be minimum of the maximum of all the possible permuatations of page
            allocation (minimize the maximum pages allocated).
         - Only contihous pages can be allocated to any student.
    */
    int maxElement = 0, arrSum = 0;

    for(int i=0; i<arr.size(); i++){
        arrSum += arr[i];
        maxElement = max(maxElement, arr[i]);
    }

    int lowerBound = maxElement, upperBound = arrSum, minMaxPages = 0;
    while(lowerBound <= upperBound){
        int candidateMinMaxPages = (lowerBound + upperBound) / 2;
        
        if(isFeasible(arr, numStudents, candidateMinMaxPages)){
            minMaxPages = candidateMinMaxPages;
            upperBound = candidateMinMaxPages-1;
        }
        else
            lowerBound = candidateMinMaxPages+1;
    }
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
            getMinimumPagesAllocation(test_arr_1, numStudents));

    numStudents = 1;
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