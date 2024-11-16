/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        for (int i = 0, j = s.length(); i < j; i++, j--)
        {
            while (i < j && !isVowel(s[i]))
                i++;
            while (i < j && !isVowel(s[j]))
                j--;

            if (i < j)
                swap(s[i], s[j]);
        }

        return s;
    }

    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};
// @lc code=end

