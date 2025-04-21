// https://leetcode.com/problems/majority-element-ii

class Solution
{
private:
    // Naive solution, O(N log(N)), O(1) space
    // Same can be done using hashmap, that would be O(N) time, O(1) space
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


private:
    // Optimal solution: O(N) time and O(1) space
    vector<int> get_majority_element_candidates(vector<int> &nums)
    {
        /* To have a majority element, it should appear more than floor(N / 3) times, i.e. floor(N / 3) + 1 times
         *  where N is the size of the array.
         *
         * How many majority elements can exists?
         * There can be atmost of 2 majority element. Why?
         * Let's try and proove it by induction. Assume there are 3 majority elements
         * 
         * In order to have 3 majority elements, each elememnt should occur floor(N / 3) + 1
         * Given this, the total number of elements in the array should be (floor(N / 3) + 1) * 3
         *  ((N / 3) + 1) * 3
         *   N + 3 > N (number of elements in the array)
         * 
         * Hence, we can never have more than 2 majority elements, if the majority elements
         *  are the ones occuring more than floor(N / 3) times
         * 
         * Why 2?
         *  Let do the same induction for 2 elements, now the total elements in array should be
         *      (floor(N / 3) + 1) * 2
         *      (2N / 3) + 2 < N (number of elements in the array)
         * 
         * Given the above observation, we can modity Moore's voting algorithm with minor modifications to 
         *  get majority elements with occurence greater than floor(N / 3)
        */

        int candidate_1 = INT_MIN, candidate_2 = INT_MIN;
        int candidate_1_occurence_count = 0, candidate_2_occurence_count = 0;
        int num_elements = nums.size();

        for (int i = 0; i < num_elements; i++)
        {
            if (candidate_1_occurence_count == 0 && nums[i] != candidate_2)
            {
                candidate_1 = nums[i];
                candidate_1_occurence_count = 1;
            }
            else if (candidate_2_occurence_count == 0 && nums[i] != candidate_1)
            {
                candidate_2 = nums[i];
                candidate_2_occurence_count = 1;
            }
            else if (nums[i] == candidate_1)
                candidate_1_occurence_count++;
            else if (nums[i] == candidate_2)
                candidate_2_occurence_count++;
            else
            {
                candidate_1_occurence_count--;
                candidate_2_occurence_count--;
            }
        }

        return {candidate_1, candidate_2};
    }

public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> majority_element_candidates = get_majority_element_candidates(nums);

        // Verify that candidates are majority elements as we can have a single majority element as well
        int majority_threshold = nums.size() / 3;
        int occurence_count_1 = 0, occurence_count_2 = 0;
        for (int element: nums)
        {
            if (element == majority_element_candidates[0])
                occurence_count_1++;
            else if (element == majority_element_candidates[1])
                occurence_count_2++;
        }

        vector<int> majority_elements;
        if (occurence_count_1 > majority_threshold)
            majority_elements.push_back(majority_element_candidates[0]);
        if (occurence_count_2 > majority_threshold)
            majority_elements.push_back(majority_element_candidates[1]);

        return majority_elements;
    }
};