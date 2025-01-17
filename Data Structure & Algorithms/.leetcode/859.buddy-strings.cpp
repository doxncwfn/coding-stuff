/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        if (s == goal)
        {
            set<char> freq(s.begin(), s.end());
            return freq.size() < s.size();
        }
        int i = 0;
        int j = s.size() - 1;

        while (i < j && s[i] == goal[i])
            i++;
        while (j >= 0 && s[j] == goal[j])
            j--;

        if (i < j)
            swap(s[i], s[j]);

        return s == goal;
    }
};
// @lc code=end
