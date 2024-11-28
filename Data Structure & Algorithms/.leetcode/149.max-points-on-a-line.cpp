/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points)
    {
        int n = points.size();
        if (n < 3)
            return n;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            unordered_map<string, int> m;
            int duplicate = 0;
            int localMax = 0;
            for (int j = i + 1; j < n; ++j)
            {
                if (points[i] == points[j])
                {
                    ++duplicate;
                    continue;
                }
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = gcd(dx, dy);
                string key = to_string(dx / g) + "_" + to_string(dy / g);
                ++m[key];
                localMax = max(localMax, m[key]);
            }
            res = max(res, localMax + duplicate + 1);
        }
        return res;
    }
};
// @lc code=end

