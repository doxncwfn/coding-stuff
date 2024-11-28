/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        int ans = 1;
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        while (j < n)
        {
            if (mp.find(s[j]) != mp.end())
                i = max(i, mp[s[j]] + 1);
            mp[s[j]] = j;
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
// @lc code=end
