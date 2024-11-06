/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 */

// @lc code=start
class Solution
{
public:
    int lastRemaining(int n)
    {
        return n == 1 ? 1 : 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};
// @lc code=end
