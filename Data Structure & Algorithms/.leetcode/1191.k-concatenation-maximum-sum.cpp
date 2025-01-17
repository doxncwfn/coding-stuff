/*
 * @lc app=leetcode id=1191 lang=cpp
 *
 * [1191] K-Concatenation Maximum Sum
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
    const int MOD = 1e9 + 7;

public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        int n = arr.size();
        long long pre = arr[0], sum1 = arr[0];
        for (int i = 1; i < n; i++)
        {
            sum1 += arr[i];
            pre = max(pre, sum1);
        }

        long long total = sum1;

        long long suf = arr[n - 1], sum2 = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            sum2 += arr[i];
            suf = max(suf, sum2);
        }

        long long sub = arr[0], sum3 = arr[0];
        for (int i = 1; i < n; i++)
        {
            sum3 += arr[i];
            sub = max(sub, sum3);
            if (sum3 < 0)
                sum3 = 0;
        }

        if (n == 1 && k == 1 && arr[0] < 0)
            return 0;

        if (k == 1)
            return sub % MOD;

        long long result = 0;
        if (total > 0)
            result = (result + total * max(0, k - 2)) % MOD;
        if (pre > 0)
            result = (result + pre) % MOD;
        if (suf > 0)
            result = (result + suf) % MOD;
        return max({result, sub, pre + suf}) < 0 ? 0 : max({result, sub, pre + suf}) % MOD;
    }
};
// @lc code=end