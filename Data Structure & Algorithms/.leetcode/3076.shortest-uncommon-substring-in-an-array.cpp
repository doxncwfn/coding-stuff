/*
 * @lc app=leetcode id=3076 lang=cpp
 *
 * [3076] Shortest Uncommon Substring in an Array
 */
// @lc code=start
class Solution
{
public:
    vector<string> shortestSubstrings(vector<string>& arr)
    {
        vector<string> result;

        for (int i = 0; i < arr.size(); i++)
        {
            vector<string> substrings;
            for (int j = 1; j <= arr[i].size(); j++)
            {
                for (int start_idx = 0; start_idx + j <= arr[i].size(); start_idx++)
                {
                    string substr = arr[i].substr(start_idx, j);
                    bool uncommon = true;
                    for (int k = 0; k < arr.size(); k++)
                    {
                        if (k == i)
                            continue;
                        if (arr[k].find(substr) != string::npos)
                        {
                            uncommon = false;
                            break;
                        }
                    }
                    if (uncommon)
                    {
                        substrings.push_back(substr);
                        break;
                    }
                }
            }

            if (!substrings.empty())
            {
                sort(substrings.begin(), substrings.end());
                for (auto &x : substrings)
                    cout << x << " ";
                result.push_back(substrings[0]);
            }
            else
                result.push_back("");
        }

        return result;
    }
};
// @lc code=end