/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && len > 0)
                break;
            if (s[i] != ' ')
                len++;
        }
        return len;
    }
};
// @lc code=end