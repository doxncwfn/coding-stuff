/*
 * @lc app=leetcode id=546 lang=cpp
 *
 * [546] Remove Boxes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeBoxes(vector<int> &boxes)
    {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));
        return dfs(boxes, 0, n - 1, 0, dp);
    }
    int dfs(vector<int> &boxes, int i, int j, int k, vector<vector<vector<int>>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j][k] > 0)
            return dp[i][j][k];
        dp[i][j][k] = dfs(boxes, i, j - 1, 0, dp) + (k + 1) * (k + 1);
        for (int m = i; m < j; m++)
            if (boxes[m] == boxes[j])
                dp[i][j][k] = max(dp[i][j][k], dfs(boxes, i, m, k + 1, dp) + dfs(boxes, m + 1, j - 1, 0, dp));
        return dp[i][j][k];
    }
};
// @lc code=end
