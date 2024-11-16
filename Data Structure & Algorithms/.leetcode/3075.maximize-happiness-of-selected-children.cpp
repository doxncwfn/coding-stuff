/*
 * @lc app=leetcode id=3075 lang=cpp
 *
 * [3075] Maximize Happiness of Selected Children
 */

// @lc code=start
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), [](int a, int b)
             { return a > b; });

        long long result = 0;
        for (int i = 1; i <= k; i++)
            result += max(happiness[i - 1] - (i - 1), 0);

        return result;
    }
};
// @lc code=end

