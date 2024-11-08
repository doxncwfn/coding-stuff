/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN, area = 0;
        unordered_set<string> st;
        for (auto &rect : rectangles)
        {
            x1 = min(x1, rect[0]);
            y1 = min(y1, rect[1]);
            x2 = max(x2, rect[2]);
            y2 = max(y2, rect[3]);
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            string s1 = to_string(rect[0]) + " " + to_string(rect[1]);
            string s2 = to_string(rect[0]) + " " + to_string(rect[3]);
            string s3 = to_string(rect[2]) + " " + to_string(rect[3]);
            string s4 = to_string(rect[2]) + " " + to_string(rect[1]);
            if (!st.insert(s1).second)
                st.erase(s1);
            if (!st.insert(s2).second)
                st.erase(s2);
            if (!st.insert(s3).second)
                st.erase(s3);
            if (!st.insert(s4).second)
                st.erase(s4);
        }
        if (st.size() != 4 || !st.count(to_string(x1) + " " + to_string(y1)) || !st.count(to_string(x1) + " " + to_string(y2)) || !st.count(to_string(x2) + " " + to_string(y1)) || !st.count(to_string(x2) + " " + to_string(y2)))
            return false;
        return area == (x2 - x1) * (y2 - y1);
    }
};
// @lc code=end