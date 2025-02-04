/*
 * @lc app=leetcode id=2584 lang=cpp
 *
 * [2584] Split the Array to Make Coprime Products
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
private:
    unordered_map<int, int> getFactors(int x)
    {
        unordered_map<int, int> freq;
        int f = 2;
        while (x > 1 && f * f <= x)
        {
            while (x % f == 0)
            {
                freq[f]++;
                x /= f;
            }
            f++;
        }
        if (x != 1)
            freq[x] = 1;
        return freq;
    }

public:
    int findValidSplit(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (auto &x : nums)
            for (auto &[f, c] : getFactors(x))
                freq[f] += c;

        auto org = freq;
        int dirty = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (auto &[f, c] : getFactors(nums[i]))
            {
                if (freq[f] == org[f] && c != freq[f])
                    dirty++;
                if (freq[f] != org[f] && c == freq[f])
                    dirty--;
                freq[f] -= c;
            }

            if (dirty == 0)
                return i;
        }
        return -1;
    }
};
// @lc code=end
