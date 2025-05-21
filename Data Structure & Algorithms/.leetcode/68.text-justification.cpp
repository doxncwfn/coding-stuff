/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> res;
        int i = 0;

        while (i < words.size())
        {
            int j = i;
            int lineLength = 0;
            while (j < words.size() && lineLength + words[j].size() + (j > i ? 1 : 0) <= maxWidth)
            {
                lineLength += words[j].size() + (j > i ? 1 : 0);
                j++;
            }
            int wordCount = j - i;
            int spaces = maxWidth - (lineLength - (wordCount > 1 ? wordCount - 1 : 0));
            string line = "";
            if (j == words.size() || wordCount == 1)
            {
                for (int k = i; k < j - 1; k++)
                    line += words[k] + " ";
                line += words[j - 1];

                line += string(maxWidth - line.size(), ' ');
            }
            else
            {
                int spacesPerGap = wordCount > 1 ? spaces / (wordCount - 1) : spaces;
                int extraSpaces = wordCount > 1 ? spaces % (wordCount - 1) : 0;
                for (int k = i; k < j - 1; k++)
                {
                    line += words[k];
                    int currentSpaces = spacesPerGap + (k - i < extraSpaces ? 1 : 0);
                    line += string(currentSpaces, ' ');
                }
                line += words[j - 1];
                if (wordCount == 1)
                    line += string(spaces, ' ');
            }
            res.push_back(line);
            i = j;
        }

        return res;
    }
};
// @lc code=end