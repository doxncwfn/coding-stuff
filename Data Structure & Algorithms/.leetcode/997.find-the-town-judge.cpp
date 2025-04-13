/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<pair<int, int>> freq(n + 1, {0, 0});
        for (auto t : trust)
        {
            freq[t[0]].first++;
            freq[t[1]].second++;
        }
        for (int i = 1; i <= n; i++)
            if (freq[i].first == 0 && freq[i].second == n - 1)
                return i;

        return -1;
    }
};
// @lc code=end
