/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution
{
public:
    string simplifyPath(string path)
    {
        string result = "";
        vector<string> stack;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/'))
        {
            if (token == "" || token == ".")
                continue;
            if (token == ".." && !stack.empty())
                stack.pop_back();
            else if (token != "..")
                stack.push_back(token);
        }

        for (string s : stack)
            result += "/" + s;

        return result.empty() ? "/" : result;
    }
};
// @lc code=end

