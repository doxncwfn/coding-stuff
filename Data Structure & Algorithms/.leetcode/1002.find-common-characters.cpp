/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<vector<int>> cnt(words.size(), vector<int>(26, 0));
        for (int i = 0; i < words.size(); i++)
            for (auto &c : words[i])
                cnt[i][c - 'a']++;
        vector<string> ans;
        for (int i = 0; i < 26; i++)
        {
            int min = INT_MAX;
            for (int j = 0; j < words.size(); j++)
                if (cnt[j][i] < min)
                    min = cnt[j][i];
            for (int j = 0; j < min; j++)
                ans.push_back(string(1, i + 'a'));
        }
        return ans;
    }
};
// @lc code=end
