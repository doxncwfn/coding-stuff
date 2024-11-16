/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        vector<vector<int>> res;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < points.size(); i++)
        {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.emplace(dist, i);
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty())
        {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }

        return res;
    }
};
// @lc code=end

