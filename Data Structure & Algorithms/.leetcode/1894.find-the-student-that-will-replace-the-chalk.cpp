/*
 * @lc app=leetcode id=1894 lang=cpp
 *
 * [1894] Find the Student that Will Replace the Chalk
 */

// @lc code=start
class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        long long sum = 0;
        for (long long x : chalk)
            sum += x;
        k %= sum;
        for (int i = 0; i < chalk.size(); i++)
        {
            if (k < chalk[i])
                return i;
            k -= chalk[i];
        }
        return 0;
    }
};
// @lc code=end
