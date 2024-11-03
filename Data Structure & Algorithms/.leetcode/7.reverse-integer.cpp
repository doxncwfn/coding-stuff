/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        long long result = 0;
        while (x != 0)
        {
            int temp = x % 10;
            x /= 10;
            result = result * 10 + temp;
        }
        return result;
    }
};
// @lc code=end
