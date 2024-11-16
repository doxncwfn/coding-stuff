/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        for (int i = 1; i <= s.size() / 2; i++)
        {
            if (s.size() % i == 0)
            {
                string sub = s.substr(0, i);
                string temp = "";
                for (int j = 0; j < s.size() / i; j++)
                    temp += sub;
                if (temp == s)
                    return true;
            }
        }

        return false;
    }
};
// @lc code=end

