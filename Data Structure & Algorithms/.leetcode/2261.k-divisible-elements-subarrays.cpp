/*
 * @lc app=leetcode id=2261 lang=cpp
 *
 * [2261] K Divisible Elements Subarrays
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        int n = nums.size();
        set<vector<int>> ans;

        int i, j;
        for (i = 0; i < n; i++)
        {
            vector<int> sub;
            int count = 0;
            for (j = i; j < n; j++)
            {
                sub.push_back(nums[j]);
                if (nums[j] % p == 0)
                    ++count;
                if (count > k)
                    break;
                ans.insert(sub);
            }
        }
        return ans.size();
    }
};
// @lc code=end