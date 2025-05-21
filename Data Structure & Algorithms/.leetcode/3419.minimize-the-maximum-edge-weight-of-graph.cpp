/*
 * @lc app=leetcode id=3419 lang=cpp
 *
 * [3419] Minimize the Maximum Edge Weight of Graph
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dfs(int i, int m, vector<vector<pair<int, int>>> &ral, vector<int> &vis)
    {
        int res = vis[i] = 1;
        for (auto [j, w] : ral[i])
            if (w <= m && !vis[j])
                res += dfs(j, m, ral, vis);
        return res;
    }

    int minMaxWeight(int n, vector<vector<int>> &edges, int threshold)
    {
        vector<vector<pair<int, int>>> reverse(n);
        for (auto &e : edges)
            reverse[e[1]].push_back({e[0], e[2]});

        int l = 0, r = 1e9;
        while (l < r)
        {
            int m = (l + r) / 2;
            vector<int> vis(n, 0);
            if (dfs(0, m, reverse, vis) == n)
                r = m;
            else
                l = m + 1;
        }
        return l == 1e9 ? -1 : l;
    }
};
// @lc code=end
