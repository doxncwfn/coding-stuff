/*
 * @lc app=leetcode id=3074 lang=cpp
 *
 * [3074] Apple Redistribution into Boxes
 */

// @lc code=start
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity)
    {
        int count = 0;
        int result = 0;
        for (int &x : apple)
            count += x;
        sort(capacity.begin(), capacity.end(), [](int a, int b) { return a > b; });
        do
        {
            result++;
            count -= capacity[0];
            capacity.erase(capacity.begin());
        } while (count > 0);

        return result;
    }
};
// @lc code=end