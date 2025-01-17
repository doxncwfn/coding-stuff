/*
 * @lc app=leetcode id=2017 lang=cpp
 *
 * [2017] Grid Game
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        // int n = grid[0].size();
        // int cells = n + 1;
        // vector<vector<int>> dp(2, vector<int>(cells, 0));
        // dp[0][0] = grid[0][0];
        // for (int r = 0; r < 2; r++)
        //     for (int c = 0; c < n; c++)
        //         {
        //             if (c == 0 && r == 0)
        //                 continue;
        //             else if (c == 0)
        //                 dp[r][c] = dp[r - 1][c] + grid[r][c];
        //             else if (r == 0)
        //                 dp[r][c] = dp[r][c - 1] + grid[r][c];
        //             else
        //                 dp[r][c] = max(dp[r][c - 1], dp[r - 1][c]) + grid[r][c];
        //         }

        // vector<pair<int, int>> route(cells);
        // route[0] = {0, 0};
        // int r = 0, c = 0;
        // for (int i = 2; i <= cells; i++)
        // {
        //     if (c < n && dp[r][c + 1] > dp[r + 1][c])
        //         c++;
        //     else if (r < 1)
        //         r++;
        //     route[i - 1] = {r, c};
        // }
        // for (auto cell : route)
        //     grid[cell.first][cell.second] = 0;
        long long top = accumulate(begin(grid[0]), end(grid[0]), 0ll),
                  bottom = 0, ans = LLONG_MAX;
        for (int i = 0; i < grid[0].size(); i++)
        {
            top -= grid[0][i];
            ans = min(ans, max(top, bottom));
            bottom += grid[1][i];
        }
        return ans;
    }
};
// @lc code=end
