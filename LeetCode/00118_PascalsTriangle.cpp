// https://leetcode.com/problems/pascals-triangle/

class Solution
{
public:
    int get_value(int row_num, int col_num)
    {
        /*
        *   Given the row and column number of Pascal's Triangle (1-indexed),
        *   the value at that position can be found using the combination formula (nCr),
        *   where:
        *       n = row_num - 1 (0-indexed row number)
        *       r = col_num - 1 (0-indexed column number)
        * 
        *   The formula for nCr is:
        *       nCr = n! / (r! * (n - r)!)
        * 
        *   To compute this efficiently without overflow or repeated factorial computation:
        *       We use the multiplicative formula:
        *       nCr = (n * (n - 1) * ... * (n - r + 1)) / (r!)
        * 
        *   This simplifies the computation to O(r) time and O(1) space.
        */

        int n = row_num - 1;
        int r = col_num - 1;

        // Edge cases: C(n, 0) or C(n, n) = 1
        if (r == 0 || r == n)
            return 1;

        int value = 1;
        for (int i = 1; i <= r; ++i)
        {
            // Multiply the current term in the numerator: (n - i + 1)
            value *= (n - i + 1);

            // Divide by the current term in the denominator: i
            value /= i;
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