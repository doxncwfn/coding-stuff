/*
 * @lc app=leetcode id=2870 lang=cpp
 *
 * [2870] Minimum Number of Operations to Make Array Empty
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int num : nums)
            map[num]++;
        int result = 0;
        for (auto &[num, freq] : map)
        {
            if (freq == 1)
                return -1;
            int n = freq / 3;
            int r = freq % 3;
            result += n + (r > 0);
        }
        return result;
    }
};
// @lc code=end
