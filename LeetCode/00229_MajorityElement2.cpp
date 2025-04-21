// https://leetcode.com/problems/majority-element-ii

class Solution
{
public:
    // Naive solution, O(N log(N))
    vector<int> majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int curr_count = 1, candidate_element = nums[0], num_elements = nums.size();
        vector<int> majority_elements;

        for (int i = 1; i < num_elements; i++)
        {
            if (nums[i] == candidate_element)
                curr_count++;
            else
            {
                if (curr_count > (num_elements / 3))
                    majority_elements.push_back(candidate_element);

                candidate_element = nums[i];
                curr_count = 1;
            }
        }

        if (curr_count > (num_elements / 3))
            majority_elements.push_back(candidate_element);
        return majority_elements;
    }
};