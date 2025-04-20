// https://leetcode.com/problems/rotate-image/

class Solution
{
private:
    void transpose(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
            for (int j = i; j < matrix[i].size(); j++)
                swap(matrix[i][j], matrix[j][i]);
    }

    void reverse_rows(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }

public:
    void rotate(vector<vector<int>> &matrix)
    {
        transpose(matrix);
        reverse_rows(matrix);
    }
};