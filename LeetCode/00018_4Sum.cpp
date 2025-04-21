// https://leetcode.com/problems/4sum/description/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int num_elements = nums.size();
        vector<vector<int>> quadruplets;
        for (int quad_primary_idx = 0; quad_primary_idx < num_elements; quad_primary_idx++)
        {
            // To avoid duplicates
            if (quad_primary_idx > 0 && nums[quad_primary_idx] == nums[quad_primary_idx - 1])
                continue;

            for (int quad_secondary_idx = quad_primary_idx + 1; quad_secondary_idx < num_elements; quad_secondary_idx++)
            {
                // To avoid duplicates
                if (quad_secondary_idx > (quad_primary_idx + 1) &&
                    nums[quad_secondary_idx] == nums[quad_secondary_idx - 1])
                    continue;

                int left_idx = quad_secondary_idx + 1, right_idx = num_elements - 1;
                while (left_idx < right_idx)
                {
                    long long current_value = static_cast<long long>(nums[quad_primary_idx]) +
                                              static_cast<long long>(nums[quad_secondary_idx]) +
                                              static_cast<long long>(nums[left_idx]) +
                                              static_cast<long long>(nums[right_idx]);

                    if (current_value == target)
                    {
                        quadruplets.push_back(
                                {nums[quad_primary_idx], nums[quad_secondary_idx], nums[left_idx], nums[right_idx]});
                        left_idx++, right_idx--;

                        // To avoid using duplicate values in solution formation
                        while (left_idx < right_idx && nums[left_idx] == nums[left_idx - 1])
                            left_idx++;
                        while (left_idx < right_idx && nums[right_idx] == nums[right_idx + 1])
                            right_idx--;
                    }
                    else if (current_value < target)
                        left_idx++;
                    else
                        right_idx--;
                }
            }
        }

        return quadruplets;
    }
};