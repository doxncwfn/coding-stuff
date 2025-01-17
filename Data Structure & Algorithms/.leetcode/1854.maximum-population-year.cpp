/*
 * @lc app=leetcode id=1854 lang=cpp
 *
 * [1854] Maximum Population Year
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        int n = logs.size();
        vector<int> years(101, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = logs[i][0]; j < logs[i][1]; j++)
                years[j - 1950]++;
        }

        int max = 0;
        int year = 0;
        for (int i = 0; i < 101; i++)
        {
            if (years[i] > max)
            {
                max = years[i];
                year = i + 1950;
            }
        }

        return year;
    }
};
// @lc code=end