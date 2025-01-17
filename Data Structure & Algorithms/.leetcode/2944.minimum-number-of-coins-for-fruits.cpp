/*
 * @lc app=leetcode id=2944 lang=cpp
 *
 * [2944] Minimum Number of Coins for Fruits
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    int minimumCoins(vector<int> &p)
    {
        vector dp(p.size() + 1, INT_MAX);
        dp[0] = 0;
        for (int i{}; i < p.size(); ++i)
            for (int j{i}; j < min<int>(p.size(), 2 * i + 2); ++j)
                dp[j + 1] = std::min(dp[j + 1], p[i] + dp[i]);
        return dp[p.size()];
    }
};
// @lc code=end
