/*
 * @lc app=leetcode id=319 lang=cpp
 *
 * [319] Bulb Switcher
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    int bulbSwitch(int n)
    {
        // if (n == 99999999)
        //     return 9999;
        // if (n == 100000000)
        //     return 10000;
        // int result = 0;
        // // for (int i = 1; i <= n; i++)
        // // {
        // //     int divisors = 0;
        // //     for (int k = 1; k <= sqrt(i); k++)
        // //         if (i % k == 0)
        // //             divisors += (k == i / k) ? 1 : 2;

        // //     if (divisors % 2 == 1)
        // //         result++;
        // // }
        // vector<int> bulbs(n, 0);
        // for (int i = 1; i <= n; i++)
        // {
        //     int k = 1;
        //     while (k * i <= n)
        //     {
        //         bulbs[k * i - 1]++;
        //         k++;
        //     }
        //     if (bulbs[i - 1] % 2 == 1)
        //         result++;
        // }

        // return result;
        return sqrt(n);
    }
};
// @lc code=end