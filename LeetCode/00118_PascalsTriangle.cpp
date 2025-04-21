// https://leetcode.com/problems/pascals-triangle/

class Solution
{
private:
    int get_value(int row_num, int col_num)
    {
        /*  Given row and cloumn number of the pascals triangle the
        *   value can be found using the formula nCr (combination) in O(col_num) time and O(1) space complexity
        *       n -> Row number
        *       r -> Column number
        *   When you expand this you get n!/r! * (n-r)!
        * 
        *   n * (n - 1) * (n - 2) * ... * (n - (r + 1)) * (n - r) *  (n - r - 1) * ... * 1 / (r! * (n - r)!
        *   n * (n - 1) * (n - 2) * ... * (n - (r + 1)) * (n - r)! / (r! * (n - r)!) 
        *
        *   The (n-r)! in numerator will be cancelled by denominator after simplifing for this we get
        *   n * (n - 1) * (n - 2) * ... * (n - (r + 1)) / r!
        *   (n - 0) * (n - 1) * (n - 2) * ... * (n - (r + 1)) / r!
        * 
        *   The numerator will have r terms
        */

        int value = 1;
        for (int i = 0; i < col_num; i++)
        {
            value = value * (row_num - i);// Numerator
            value = value / (i + 1);      // Denominator
        }

        return value;
    }

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