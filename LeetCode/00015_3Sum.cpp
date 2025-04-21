// https://leetcode.com/problems/3sum

// Very slow O(N^2 log(K)) solution, K -> number of triplets inserted into the set
class Solution
{
private:
    vector<pair<int, int>> two_sum(vector<int> &nums, int k, int left_ptr, int right_ptr)
    {
        vector<pair<int, int>> solution_pairs;

        while (left_ptr < right_ptr)
        {
            if (nums[left_ptr] + nums[right_ptr] == k)
            {
                solution_pairs.push_back({nums[left_ptr], nums[right_ptr]});
                left_ptr++, right_ptr--;
            }
            else if (nums[left_ptr] + nums[right_ptr] < k)
                left_ptr++;
            else
                right_ptr--;
        }

        return solution_pairs;
    }

public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int num_elements = nums.size();
        set<vector<int>> solution_triplets_set;
        for (int i = 0; i < num_elements - 2; i++)
        {
            int current_element = nums[i];
            vector<pair<int, int>> two_sum_solutions = two_sum(nums, -current_element, i + 1, num_elements - 1);

            if (!two_sum_solutions.empty())
            {
                for (const pair<int, int> &two_sum_pairs: two_sum_solutions)
                    solution_triplets_set.insert({current_element, two_sum_pairs.first, two_sum_pairs.second});
            }
        }

        vector<vector<int>> solution_triplets;
        for (vector<int> solution: solution_triplets_set)
            solution_triplets.emplace_back(solution);

        return solution_triplets;
    }
};