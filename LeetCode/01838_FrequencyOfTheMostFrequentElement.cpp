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
            long update_ops = static_cast<long>(nums[end_idx] - nums[end_idx - 1]) * (end_idx - start_idx);

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

    // The solution from discuss, almost the same but instead of updating k, it only updates operations
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(begin(nums), end(nums));
        uint l = 0, r = 1, incrementsRequired = 0;
        for (; r < size(nums); r++)
        {
            // increments requried to bring all nums[j] (for l <= j < r) to nums[r]
            incrementsRequired += (nums[r] - nums[r - 1]) * (r - l);
            // if increment required become greater than k, then,
            // reduce the increments required to get nums[l] to nums[r] & slide left pointer forward
            if (incrementsRequired > k)
                incrementsRequired -= (nums[r] - nums[l++]);
        }
        // finally the [l, r] window will hold the size of maximum number of elements that can be made equal
        return r - l;
    }
};
