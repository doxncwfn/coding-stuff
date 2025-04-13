/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
        if (q.size() == 0 || q.size() == n * n)
            return -1;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            for (auto [dx, dy] : dirs)
            {
                int x = i + dx, y = j + dy;
                if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] > dist[i][j] + 1)
                {
                    dist[x][y] = dist[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dist[i][j]);
        return ans;
    }
};
// @lc code=end
