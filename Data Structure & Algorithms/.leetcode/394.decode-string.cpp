/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> n;
        stack<string> strs;
        string res;

        int num = 0;
        for (char c : s)
        {
            if (isdigit(c))
                num = num * 10 + c - '0';
            else if (isalpha(c))
                res.push_back(c);
            else if (c == '[')
            {
                n.push(num);
                strs.push(res);
                num = 0;
                res.clear();
            }
            else // ']'
            {
                string temp = res;
                for (int i = 1; i < n.top(); i++)
                    res += temp;
                res = strs.top() + res;
                n.pop();
                strs.pop();
            }
        }
        return res;
    }
};
// @lc code=end
