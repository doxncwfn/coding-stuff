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
        unordered_map<string, int> dictionary;
        vector<vector<int>> res;

        for (int i = 0; i < (int)words.size(); i++)
        {
            string key = words[i];
            reverse(key.begin(), key.end());
            dictionary[key] = i;
        }

        if (dictionary.find("") != dictionary.end())
            for (int i = 0; i < (int)words.size(); i++)
            {
                if (i == dictionary[""])
                    continue;
                if (isPalindrome(words[i]))
                    res.push_back({dictionary[""], i});
            }

        for (int i = 0; i < (int)words.size(); i++)
            for (int j = 0;j<words[i].size();j++)
                {
                    string left = words[i].substr(0, j);
                    string right = words[i].substr(j, words[i].size() - j);

                    if (dictionary.find(left) != dictionary.end() && isPalindrome(right) && dictionary[left] != i)
                        res.push_back({i, dictionary[left]});

                    if (dictionary.find(right) != dictionary.end() && isPalindrome(left) && dictionary[right] != i)
                        res.push_back({dictionary[right], i});
                }

                return res;
    }

private:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
            if (s[i++] != s[j--])
                return false;

        return true;
    }
};
// @lc code=end