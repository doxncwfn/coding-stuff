/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start
class Solution
{
public:
    bool isNumber(string s)
    {
        // if (s.empty())
        //     return false;

        bool e_flag = false, dot = false, digit_flag = false;
        int signed_flag = 0;

        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                digit_flag = true;
            else if (s[i] == '+' || s[i] == '-')
            {
                if (signed_flag == 2 || (i > 0 && (s[i - 1] != 'e' && s[i - 1] != 'E')) || i == (int)s.size() - 1)
                    return false;
                signed_flag++;
            }
            else if (s[i] == 'e' || s[i] == 'E')
            {
                if (e_flag || !digit_flag || i == s.size() - 1)
                    return false;
                e_flag = dot = true;
                digit_flag = false;
            }
            else if (s[i] == '.')
            {
                if (dot || e_flag || (i == (int)s.size() - 1 && !digit_flag))
                    return false;
                dot = true;
            }
            else
                return false;
        }
        return true;
    }
};
// @lc code=end