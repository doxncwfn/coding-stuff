/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &p, int start, int end)
    {
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        for (int i = 0; i < n - 1; ++i)
        {
            bool updated = false;
            for (int j = 0; j < edges.size(); ++j)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = p[j];

                if (maxProb[u] * prob > maxProb[v])
                {
                    maxProb[v] = maxProb[u] * prob;
                    updated = true;
                }
                if (maxProb[v] * prob > maxProb[u])
                {
                    maxProb[u] = maxProb[v] * prob;
                    updated = true;
                }
            }
            if (!updated)
                break;
        }

        return maxProb[end];
    }
};
// @lc code=end
