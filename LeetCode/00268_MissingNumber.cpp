// https://leetcode.com/problems/missing-number/

// Using XOR, doesn't need long
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // XOR of a number with itself is 0
        // xor_nums: XOR of all the numbers in the array
        // xor_nums_all: XOR of all the numbers from 0 to n
        // xor_nums ^ XOR_nums_all: Will cancel out the numbers in the array and the
        //  result with have only the missing number

        int xor_nums = 0, xor_nums_all = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xor_nums = xor_nums ^ nums[i];
            xor_nums_all = xor_nums_all ^ (i + 1);
        }

        int missing_num = xor_nums ^ xor_nums_all;
        return missing_num;
    }
};


// Using natural numbers summation formula, needs long as the number array elements are 1 < N < 10^5,
//  so summation would exceed 10^5
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int num_elements = nums.size();
        long summation_n = (num_elements * (num_elements + 1)) / 2;

        for (int number: nums)
            summation_n -= number;

        return summation_n;
    }
};