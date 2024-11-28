/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n = height.size();
        int i = 0, j = n - 1;
        int ans = 0;
        while (i < j)
        {
            ans = max(ans, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};
// @lc code=end

