// https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/

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
