/*
 * @lc app=leetcode id=2567 lang=cpp
 *
 * [2567] Minimum Score by Changing Two Elements
 */

// @lc code=start
class Solution {
public:
    int minimizeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        return min({nums[nums.size() - 1] - nums[2],
                    nums[nums.size() - 3] - nums[0],
                    nums[nums.size() - 2] - nums[1]});
    }
};
// @lc code=end