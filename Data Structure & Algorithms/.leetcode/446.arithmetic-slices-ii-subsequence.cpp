/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        int res = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                long long diff = (long long)nums[i] - nums[j];
                dp[i][diff] += 1;
                if (dp[j].find(diff) != dp[j].end())
                {
                    dp[i][diff] += dp[j][diff];
                    res += dp[j][diff];
                }
        }

        return res;
    }
};
// @lc code=end