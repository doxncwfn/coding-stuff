/*
 * @lc app=leetcode id=2592 lang=cpp
 *
 * [2592] Maximize Greatness of an Array
 */

// @lc code=start
class Solution
{
public:
    int maximizeGreatness(vector<int> &nums)
    {
        int result = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cursor = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] > nums[cursor])
            {
                result++;
                cursor++;
            }

        return result;
    }
};
// @lc code=end
// 1 1 1 2 3 3 5