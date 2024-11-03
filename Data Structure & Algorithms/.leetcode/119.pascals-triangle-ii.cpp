/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> res;
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++)
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            res.push_back(row);
        }
        return res[rowIndex];
    }
};
// @lc code=end
