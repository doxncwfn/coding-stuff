/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution
{
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        vector<int> count(k, 0);
        count[0] = 1;
        int sum = 0;
        int res = 0;
        for (int num : nums)
        {
            sum = (sum + num % k + k) % k;
            res += count[sum]++;
        }
        return res;
    }
};
// @lc code=end

