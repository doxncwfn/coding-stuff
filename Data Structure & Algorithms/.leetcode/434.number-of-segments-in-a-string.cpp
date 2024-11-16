/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s)
    {
        int count = 0;
        stringstream ss(s);
        string word;
        while (ss >> word)
            count++;

        return count;
    }
};
// @lc code=end

