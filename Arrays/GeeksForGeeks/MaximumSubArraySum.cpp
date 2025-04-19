#include <bits/stdc++.h>
using namespace std;

int getMaximumSubArraySum(int arr[], int size)
{
    int currentSubArraySum, maxSubArraySum;
    currentSubArraySum = maxSubArraySum = arr[0];

    for (int i = 1; i < size; i++)
    {
        currentSubArraySum = max(currentSubArraySum + arr[i], arr[i]);
        maxSubArraySum = max(currentSubArraySum, maxSubArraySum);
    }
    return maxSubArraySum;
}

void printMaximumSubarray(int arr[], int size)
{
    int curr_subarray_sum = 0, max_subarray_sum = INT_MIN;
    int subarray_start_idx = 0, subarray_end_idx = 0;

    for (int i = 0; i < size; i++)
    {
        if (curr_subarray_sum + arr[i] < arr[i])
        {
            // Will start a new subarray from here as carrying previous sum
            //  reduces the overall sum
            subarray_start_idx = i;
            curr_subarray_sum = arr[i];
        }
        else
            curr_subarray_sum += arr[i];

        if (curr_subarray_sum > max_subarray_sum)
        {
            // A potential subarray end index, if sum increases by including
            //  next element, subarray_end_idx will be updated again
            subarray_end_idx = i;
            max_subarray_sum = curr_subarray_sum;
        }
    }

    cout << "Maximum subarray with sum " << max_subarray_sum << " has start and end indices: [" << subarray_start_idx
         << ", " << subarray_end_idx << "]" << endl;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int test_array_1[] = {2, 3, -8, 7, -1, 2, 3};
    int test_array_2[] = {5, 8, 3};
    int test_array_3[] = {-6, -1, -8};
    int test_array_4[] = {1, -2, 3, -1, 2};

    printf("\nContents of array\n");
    printArray(test_array_1, 7);
    printf("Maximum sub-array sum for the given array: %d\n", getMaximumSubArraySum(test_array_1, 7));
    printMaximumSubarray(test_array_1, 7);

    printf("\nContents of array\n");
    printArray(test_array_2, 3);
    printf("Maximum sub-array sum for the given array: %d\n", getMaximumSubArraySum(test_array_2, 3));
    printMaximumSubarray(test_array_2, 3);

    printf("\nContents of array\n");
    printArray(test_array_3, 3);
    printf("Maximum sub-array sum for the given array: %d\n", getMaximumSubArraySum(test_array_3, 3));
    printMaximumSubarray(test_array_3, 3);

    printf("\nContents of array\n");
    printArray(test_array_4, 5);
    printf("Maximum sub-array sum for the given array: %d\n", getMaximumSubArraySum(test_array_4, 5));
    printMaximumSubarray(test_array_4, 5);

    return 0;
}