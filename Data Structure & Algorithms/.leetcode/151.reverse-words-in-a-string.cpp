/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s)
    {
        istringstream is(s);
        string res, tmp;
        while (is >> tmp)
            res = tmp + " " + res;
        if (!res.empty())
            res.pop_back();
        return res;
    }
};
// @lc code=end

