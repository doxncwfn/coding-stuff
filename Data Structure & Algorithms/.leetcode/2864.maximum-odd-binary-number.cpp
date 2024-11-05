/*
 * @lc app=leetcode id=2864 lang=cpp
 *
 * [2864] Maximum Odd Binary Number
 */

// @lc code=start
class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int count = 0;
        for (char c : s)
            if (c == '1')
                count++;

        string result = "";
        for (int i = 1; i < count; i++)
            result += "1";
        for (int i = 0; i < s.size() - count; i++)
            result += "0";

        return result + "1";
    }
};
// @lc code=end
