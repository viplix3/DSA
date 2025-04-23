// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

class Solution
{
public:
    // Using array as hashmap
    vector<int> findTwoElement(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            int val = arr[i] % (n + 1);
            arr[val - 1] += (n + 1);
        }

        int missing = -1, repeating = -1;

        for (int i = 0; i < n; i++)
        {
            int count = arr[i] / (n + 1);

            if (count == 0)
                missing = i + 1;
            else if (count == 2)
                repeating = i + 1;
        }

        return {repeating, missing};
    }


public:
    // Using array elements to mark visited
    vector<int> findTwoElement(vector<int> &arr)
    {
        int n = arr.size();

        int missing, repeating;
        for (int i = 0; i < n; i++)
        {
            int val = abs(arr[i]);

            if (arr[val - 1] < 0)
                // Already visited that's why it is negative
                repeating = val;
            else
                // Mark as visited
                arr[val - 1] = -arr[val - 1];
        }

        // Second pass to find missing number
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                missing = i + 1;
                break;
            }
        }

        return {repeating, missing};
    }
};