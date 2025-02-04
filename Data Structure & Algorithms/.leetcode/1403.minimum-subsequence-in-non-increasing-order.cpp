/*
 * @lc app=leetcode id=1403 lang=cpp
 *
 * [1403] Minimum Subsequence in Non-Increasing Order
 */

// @lc code=start
class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        int index = 0;
        for (int i = 1; i < nums.size(); i++)
            prefix[i] = prefix[i - 1] + nums[i];
        for (int i = 0; i < nums.size(); i++)
            if (prefix[i] >= prefix[nums.size() - 1] - prefix[i])
            {
                index = i;
                break;
            }
        vector<int> result;
        for (int i = nums.size() - 1; i >= index; i--)
            result.push_back(nums[i]);
        return result;
    }
};
// @lc code=end
