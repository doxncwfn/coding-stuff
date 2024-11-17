/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution
{
public:
    int countSubstrings(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
            for (int j = i; j < s.size(); j++)
                if (isPalindrome(s.substr(i, j - i + 1)))
                    count++;

        return count;
    }

    bool isPalindrome(string s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
            if (s[i] != s[n - i - 1])
                return false;
        return true;
    }
};
// @lc code=end