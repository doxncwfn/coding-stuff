/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int n, int k)
    {
        int cur = 1;
        k--;
        while (k)
        {
            int steps = 0;
            long long first = cur, last = cur + 1;
            while (first <= n)
            {
                steps += min((long long)n + 1, last) - first;
                first *= 10;
                last *= 10;
            }
            if (steps <= k)
            {
                cur++;
                k -= steps;
            }
            else
            {
                cur *= 10;
                k--;
            }
        }

        return cur;        
    }
};
// @lc code=end