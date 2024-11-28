/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long ans = 0;
        while (a >= b)
        {
            long long temp = b, m = 1;
            while (a >= (temp << 1))
            {
                temp <<= 1;
                m <<= 1;
            }
            a -= temp;
            ans += m;
        }
        return (dividend < 0) ^ (divisor < 0) ? -ans : ans;
    }
};
// @lc code=end

