/*
 * @lc app=leetcode id=2706 lang=cpp
 *
 * [2706] Buy Two Chocolates
 */

// @lc code=start
class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        sort(prices.begin(), prices.end());
        int n = prices.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int idx = lower_bound(prices.begin() + i + 1, prices.end(), money - prices[i]) - prices.begin();
            if (idx < n)
                ans = max(ans, prices[i] + prices[idx]);
        }
        return ans;
    }
};
// @lc code=end
