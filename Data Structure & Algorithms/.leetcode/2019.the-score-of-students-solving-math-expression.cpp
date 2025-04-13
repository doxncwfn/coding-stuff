/*
 * @lc app=leetcode id=2019 lang=cpp
 *
 * [2019] The Score of Students Solving Math Expression
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int scoreOfStudents(string s, vector<int> &answers)
    {
        // Computing the correct answer
        stack<int> st;
        bool f = 0;
        int ans = 0;
        for (auto x : s)
        {
            if (x == '*')
                f = 1;
            if (isdigit(x) && f)
            {
                auto temp = st.top();
                st.pop();
                st.push(temp * (x - '0'));
                f = 0;
            }
            else if (isdigit(x))
                st.push(x - '0');
        }
        while (!st.empty())
            ans += st.top(), st.pop();

        // Computing the other answers
        bool op[32];
        unordered_set<int> poss[32][32]; // storing possibilities & operators
        for (int i = 0; i < s.size(); i++)
            if (i & 1)
                op[i] = (s[i] == '+' ? 0 : 1);
            else
                for (int gap = 0, j = i; j >= 0; gap += 2, j -= 2)
                {
                    if (gap == 0)
                        poss[i][i].insert(s[i] - '0');
                    else if (gap == 2)
                    {
                        auto x = s[j] - '0', y = s[i] - '0';
                        int temp = (op[i - 1] ? x * y : x + y);
                        if (temp <= 1000)
                            poss[j][i].insert(temp); // optimization
                    }
                    else
                        for (int k = i - 1; k >= 1; k -= 2)
                            for (auto x : poss[j][k - 1])
                                for (auto y : poss[k + 1][i])
                                {
                                    int temp = (op[k] ? x * y : x + y);
                                    if (temp <= 1000)
                                        poss[j][i].insert(temp); // optimization
                                }
                }

        // Computing the score
        int score = 0;
        for (auto x : answers)
        {
            if (x == ans)
                score += 5;
            else if (poss[0][s.size() - 1].count(x))
                score += 2;
        }
        return score;
    }
};
// @lc code=end
