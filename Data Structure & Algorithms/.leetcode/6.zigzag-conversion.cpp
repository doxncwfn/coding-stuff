/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (n == 1)
            return s;

        vector<string> ans(n);
        bool flag = false;
        int i = 0;

        for (auto ch : s)
        {
            ans[i] += ch;
            if (i == 0 || i == n - 1)
                flag = !flag;
            flag ? i++ : i--;
        }

        string zigzag = "";
        for (auto str : ans)
            zigzag += str;
        return zigzag;
    }
};
// @lc code=end
