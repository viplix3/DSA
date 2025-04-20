// https://leetcode.com/problems/pascals-triangle/

class Solution
{
public:
    vector<vector<int>> generate(int num_rows)
    {
        vector<vector<int>> pascals_triangle;
        pascals_triangle.reserve(num_rows);

        for (int row_idx = 0; row_idx < num_rows; row_idx++)
        {
            // Each row has #row number of columns
            //  this variable is created just for the sake of code readibility
            int num_columns = row_idx + 1;
            vector<int> curr_row;
            curr_row.reserve(num_columns);

            for (int j = 0; j < num_columns; j++)
            {
                // 1st and last column are always 1
                if (j == 0 || j == (num_columns - 1))
                    curr_row.push_back(1);
                else
                    // Current columns is sum of (i-1) and (i) column of previous row
                    curr_row.push_back(pascals_triangle[row_idx - 1][j - 1] + pascals_triangle[row_idx - 1][j]);
            }
            pascals_triangle.emplace_back(curr_row);
        }

        return pascals_triangle;
    }
};