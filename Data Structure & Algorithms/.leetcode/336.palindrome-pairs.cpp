/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words.size(); j++)
            {
                if (i == j)
                    continue;
                string s = words[i] + words[j];
                if (isPalindrome(s))
                    res.push_back({i, j});
            }
        return res;
    }

private:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
// @lc code=end