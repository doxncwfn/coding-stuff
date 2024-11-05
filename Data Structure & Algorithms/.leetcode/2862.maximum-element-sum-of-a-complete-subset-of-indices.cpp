/*
 * @lc app=leetcode id=2862 lang=cpp
 *
 * [2862] Maximum Element-Sum of a Complete Subset of Indices
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    long long maximumSum(vector<int> &nums)
    {
        const int n = nums.size();
        int64_t answer = 0;

        for (int i = 1; i <= n; ++i)
        {
            int64_t value = nums[i - 1];
            if (value < 0) // not a key.
                continue;
            for (int j = 2; true; ++j)
            {
                int index = i * j * j;
                if (index > n)
                    break;
                value += nums[index - 1];
                nums[index - 1] = -1; // mark not key
            }
            answer = max(answer, value);
        }
        return answer;
    }
};
// @lc code=end
