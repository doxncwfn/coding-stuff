/*
 * @lc app=leetcode id=2860 lang=cpp
 *
 * [2860] Happy Students
 */

// @lc code=start
class Solution
{
public:
    int countWays(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 0;

        if (nums[0] > 0)
            count++;
        for (int i = 1; i < (int)nums.size(); i++)
            if (i > nums[i - 1] && i < nums[i])
                count++;
        if (nums[nums.size() - 1] < (int)nums.size())
            count++;

        return count;
    };
};
// @lc code=end
// 0 2 3 3 6 6 7 7