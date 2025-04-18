// https://leetcode.com/problems/single-number/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // XOR of a number with itself is 0
        // xor_nums: XOR of all the numbers in the array
        // The numbers which appear twice will cancel out each other in XOR
        //  operation and result in a 0, the only thing that would remain in the array would be
        //  the number that occurs a single time
        int xor_nums = 0;
        for (int element: nums)
            xor_nums = xor_nums ^ element;

        return xor_nums;
    }
};
