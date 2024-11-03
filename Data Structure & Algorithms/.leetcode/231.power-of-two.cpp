/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (!n)
            return false;
        while (n)
        {
            if (n == 1)
                return true;
            if (n % 2)
                return false;
            n /= 2;
        };
        return true;
    }
};
// @lc code=end
