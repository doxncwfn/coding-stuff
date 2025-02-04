/*
 * @lc app=leetcode id=2042 lang=cpp
 *
 * [2042] Check if Numbers Are Ascending in a Sentence
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    bool areNumbersAscending(string s)
    {
        int prev = -1;
        int num = 0;
        for (int i = 0; i < s.size(); i++)
            if (isdigit(s[i]))
                num = num * 10 + (s[i] - '0');
            else if (num > 0)
            {
                if (num <= prev)
                    return false;
                prev = num;
                num = 0;
            }
        return num == 0 || num > prev;
    }
};
// @lc code=end
