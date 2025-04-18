// https://leetcode.com/problems/count-elements-with-maximum-frequency/

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        vector<int> frequencies(101, 0);
        for (int element: nums)
            frequencies[element]++;

        int max_frequency = *std::max_element(frequencies.begin(), frequencies.end());
        int max_frequency_sum = 0;
        for (int frequency: frequencies)
        {
            if (frequency == max_frequency)
                max_frequency_sum += frequency;
        }

        return max_frequency_sum;
    }
};