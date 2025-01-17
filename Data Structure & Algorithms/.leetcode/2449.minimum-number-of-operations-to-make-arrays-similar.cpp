/*
 * @lc app=leetcode id=2449 lang=cpp
 *
 * [2449] Minimum Number of Operations to Make Arrays Similar
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    long long makeSimilar(vector<int> &nums, vector<int> &target)
    {
        long long result = 0;
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        vector<int> odd, even;
        for (auto &x : nums)
            x % 2 == 0 ? even.push_back(x) : odd.push_back(x);

        int k = 0, j = 0;
        for (auto &x : target)
            x % 2 == 0 ? result += (abs(x - even[k++])) / 2 : result += (abs(x - odd[j++])) / 2;

        return result / 2;
    }
};
// @lc code=end
