/*
 * @lc app=leetcode id=2910 lang=cpp
 *
 * [2910] Minimum Number of Groups to Create a Valid Assignment
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
private:
    int solve(int size, unordered_map<int, int> map)
    {
        int groups = 0;
        for (auto [_, value] : map)
        {
            int n = value / (size + 1);
            int r = value % (size + 1);
            if (!r)
                groups += n;
            else if (n >= size - r)
                groups += n + 1;
            else
                return -1;
        }
        return groups;
    }

public:
    int minGroupsForValidAssignment(vector<int> &balls)
    {
        unordered_map<int, int> freq;
        for (int ball : balls)
            freq[ball]++;
        int min = INT_MAX;
        for (auto [_, value] : freq)
            min = std::min(min, value);
        int result = INT_MAX;
        for (int size = 1; size <= min; size++)
        {
            int groups = solve(size, freq);
            if (groups != -1)
                result = std::min(result, groups);
        }
        return result == INT_MAX ? -1 : result;
    }
};
// @lc code=end
// 3 4 5