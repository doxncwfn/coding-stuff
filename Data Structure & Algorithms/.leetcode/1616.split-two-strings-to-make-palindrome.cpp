/*
 * @lc app=leetcode id=1616 lang=cpp
 *
 * [1616] Split Two Strings to Make Palindrome
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j && s[i] == s[j])
        {
            i++;
            j--;
        }
        return i >= j;
    }
    bool check(string a, string b)
    {
        int i = 0, j = a.size() - 1;
        while (i < j && a[i] == b[j])
        {
            i++;
            j--;
        }
        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }
    bool checkPalindromeFormation(string a, string b)
    {
        return check(a, b) || check(b, a);
    }
};
// @lc code=end
