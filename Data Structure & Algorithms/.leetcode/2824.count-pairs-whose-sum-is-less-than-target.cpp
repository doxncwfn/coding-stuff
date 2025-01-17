/*
 * @lc app=leetcode id=2824 lang=cpp
 *
 * [2824] Count Pairs Whose Sum is Less than Target
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = (int)nums.size() - 1;
        int result = 0;
        while (left < right)
        {
            if (nums[left] + nums[right] < target)
            {
                result += right - left;
                left++;
            }
            else if (nums[left] + nums[right] >= target)
                right--;
        }
        return result;
    }
};
// @lc code=end
