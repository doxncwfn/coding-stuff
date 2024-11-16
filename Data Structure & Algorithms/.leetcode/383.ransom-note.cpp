/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        for (char c : magazine)
        {
            size_t found = ransomNote.find(c);
            if (found != string::npos)
                ransomNote.erase(found, 1);
        }

        return ransomNote.empty();
    }
};
// @lc code=end

