/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty())
            return res;

        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
                res.push_back(matrix[top][i]);
            for (int i = top + 1; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            if (top < bottom && left < right)
            {
                for (int i = right - 1; i >= left; i--)
                    res.push_back(matrix[bottom][i]);
                for (int i = bottom - 1; i > top; i--)
                    res.push_back(matrix[i][left]);
            }
            top++;
            bottom--;
            left++;
            right--;
        }
        return res;
    }
};
// @lc code=end