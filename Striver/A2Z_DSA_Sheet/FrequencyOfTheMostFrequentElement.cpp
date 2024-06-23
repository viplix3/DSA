// https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        std::sort(nums.begin(), nums.end());

        int start_idx = 0, end_idx = 1;
        int max_frequency = 1;

        while (end_idx < nums.size())
        {
            long long update_ops = static_cast<long long>(nums[end_idx] - nums[end_idx - 1]) * (end_idx - start_idx);

            if (update_ops <= k)
            {
                k -= update_ops;
                end_idx++;
            }
            else
            {
                k += (nums[end_idx - 1] - nums[start_idx]);
                start_idx++;
            }

            max_frequency = max((end_idx - start_idx), max_frequency);
        }

        return max_frequency;
    }
};

int main()
{
    int num_tests;
    cin >> num_tests;

    Solution sol_obj;

    while (num_tests--)
    {
        int arr_size;
        cin >> arr_size;

        vector<int> nums(arr_size);
        for (int i = 0; i < arr_size; i++)
            cin >> nums[i];

        int k;
        cin >> k;

        cout << sol_obj.maxFrequency(nums, k) << endl;
    }

    return 0;
}