/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int rows = triangle.size();
        vector<int> dp(triangle.back());
        for (int i = rows - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        return dp[0];
    }
};
// @lc code=end
