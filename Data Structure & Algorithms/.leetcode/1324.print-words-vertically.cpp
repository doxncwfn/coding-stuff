/*
 * @lc app=leetcode id=1324 lang=cpp
 *
 * [1324] Print Words Vertically
 */

// @lc code=start
class Solution
{
public:
    vector<string> printVertically(string s)
    {
        vector<string> words;
        stringstream ss(s);
        string word;
        int max_len = 0;
        while (ss >> word)
        {
            words.push_back(word);
            max_len = max(max_len, (int)word.size());
        }

        vector<string> res(max_len, string(words.size(), ' '));
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < max_len; j++)
                if (j < words[i].size())
                    res[j][i] = words[i][j];
                else
                    res[j][i] = ' ';

        for (int i = 0; i < res.size(); i++)
            while (res[i].back() == ' ')
                res[i].pop_back();

        return res;
    }
};
// @lc code=end