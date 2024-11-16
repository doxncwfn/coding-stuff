/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word)
    {
        for (int i = 1; i < word.size(); i++)
            if (isupper(word[1]) != isupper(word[i]) || islower(word[0]) && isupper(word[i]))
                return false;

        return true;
    }
};
// @lc code=end

