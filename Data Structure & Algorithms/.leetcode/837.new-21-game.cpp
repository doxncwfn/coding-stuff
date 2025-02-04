/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 */

// @lc code=start
class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (k == 0 || n >= k + maxPts)
            return 1;
        vector<double> dp(n + 1);
        dp[0] = 1;
        double W = 1.0 / maxPts;
        double sum = 1;
        double res = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = sum * W;
            if (i < k)
                sum += dp[i];
            else
                res += dp[i];
            if (i - maxPts >= 0)
                sum -= dp[i - maxPts];
        }
        return res;
    }
};
// @lc code=end
