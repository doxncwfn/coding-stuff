/*
 * @lc app=leetcode id=1792 lang=cpp
 *
 * [1792] Maximum Average Pass Ratio
 */

// @lc code=start
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int s)
    {
        priority_queue<pair<double, int>> pq;
        int i = 0;
        for (auto v : classes)
        {
            double ans = ((v[0] + 1 * 1.0) / (v[1] + 1 * 1.0)) - (v[0] * 1.0 / v[1] * 1.0);
            pq.push({ans, i++});
        }
        while (s != 0 && !pq.empty())
        {
            auto [val, index] = pq.top();
            pq.pop();
            classes[index][0]++;
            classes[index][1]++;
            double ans = (classes[index][0] + 1 * 1.0) / (classes[index][1] + 1 * 1.0) - (classes[index][0] * 1.0 / classes[index][1] * 1.0);
            pq.push({ans, index});
            s--;
        }
        double result = 0;
        for (auto v : classes)
            result += (v[0] * 1.0 / v[1] * 1.0);
        return result / classes.size();
    }
};
// @lc code=end
