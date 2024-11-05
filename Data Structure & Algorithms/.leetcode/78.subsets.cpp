/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> v;
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                    v.push_back(nums[j]);
            ans.push_back(v);
        }

        return ans;
    }
};
// @lc code=end
