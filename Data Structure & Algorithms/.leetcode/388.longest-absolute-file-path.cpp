/*
 * @lc app=leetcode id=388 lang=cpp
 *
 * [388] Longest Absolute File Path
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    int lengthLongestPath(string input)
    {
        int longest = 0;
        unordered_map<int, int> pathMap;
        pathMap[0] = 0;

        istringstream ss(input);
        string line;

        while (getline(ss, line))
        {
            auto namePos = line.find_last_of('\t') + 1;
            int depth = namePos;
            string name = line.substr(namePos);

            if (name.find('.') != string::npos)
                longest = max(
                    longest, pathMap[depth] + static_cast<int>(name.length()));
            else
                pathMap[depth + 1] =
                    pathMap[depth] + static_cast<int>(name.length()) + 1;
        }

        return longest;
    }
};
// @lc code=end
