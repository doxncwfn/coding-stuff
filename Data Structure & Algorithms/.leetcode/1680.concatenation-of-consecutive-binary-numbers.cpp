/*
 * @lc app=leetcode id=1680 lang=cpp
 *
 * [1680] Concatenation of Consecutive Binary Numbers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int concatenatedBinary(int n)
    {
        long ans = 0, mod = 1e9 + 7;
        for (int i = 1; i <= n; ++i)
        {
            int len = 0;
            for (int j = i; j; j >>= 1, ++len)
                ;
            ans = ((ans << len) % mod + i) % mod;
        }
        return ans;
    }
};
// @lc code=end
