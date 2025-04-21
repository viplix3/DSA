// https://leetcode.com/problems/3sum

// Very slow O(N^2 log(K)) solution, K -> number of triplets inserted into the set
class Solution_Shit
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
                {
                    vector<int> triplets = {current_element, two_sum_pairs.first, two_sum_pairs.second};
                    solution_triplets_set.insert({current_element, two_sum_pairs.first, two_sum_pairs.second});
                }
            }
        }

        vector<vector<int>> solution_triplets(solution_triplets_set.begin(), solution_triplets_set.end());
        return solution_triplets;
    }
};


// O(N^2) time
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
                pair<int, int> solution = {nums[left_ptr], nums[right_ptr]};
                solution_pairs.push_back(solution);
                left_idx++, right_idx--;// Need this explicitly to handle the case when there are no duplicates

                // Move until you're not at the same value
                while (left_ptr < right_ptr && nums[left_ptr] == solution.first)
                    left_ptr++;
                while (left_ptr < right_ptr && nums[right_ptr] == solution.second)
                    right_ptr--;
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
        vector<vector<int>> solution_triplets;
        int prev_element = INT_MIN;
        for (int i = 0; i < num_elements - 2; i++)
        {
            if (nums[i] == prev_element)
                continue;

            int current_element = nums[i];
            vector<pair<int, int>> two_sum_solutions = two_sum(nums, -current_element, i + 1, num_elements - 1);
            if (!two_sum_solutions.empty())
                for (const pair<int, int> &two_sum_pairs: two_sum_solutions)
                    solution_triplets.push_back({current_element, two_sum_pairs.first, two_sum_pairs.second});

            prev_element = current_element;
        }

        return solution_triplets;
    }
};