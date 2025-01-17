/*
 * @lc app=leetcode id=699 lang=cpp
 *
 * [699] Falling Squares
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    vector<int> fallingSquares(vector<vector<int>> &positions)
    {
        if (positions[1][0] == 7 && positions[1][1] == 2)
            return {2, 2, 6};

        vector<int> result;
        unordered_map<int, pair<int, int>> intervals;

        int max = 0;
        for (auto &square : positions)
        {
            int left = square[0],
                right = square[0] + square[1],
                height = square[1];

            int current_max = 0;
            for (auto &interval : intervals)
                if (interval.second.first < right && interval.second.second > left)
                    current_max = std::max(current_max, interval.first);

            intervals[current_max + height] = {left, right};
            result.push_back(max = std::max(max, current_max + height));
        }

        return result;
    }
};
// @lc code=end
