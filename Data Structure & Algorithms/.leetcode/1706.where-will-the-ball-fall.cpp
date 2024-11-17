/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid)
    {
        vector<int> result;
        for (int r = 0; r < grid[0].size(); r++)
        {
            int c = r;
            for (int i = 0; i < grid.size(); i++)
            {
                if (grid[i][c] == 1)
                {
                    if (c + 1 < grid[0].size() && grid[i][c + 1] == 1)
                        c++;
                    else
                    {
                        c = -1;
                        break;
                    }
                }
                else
                {
                    if (c - 1 >= 0 && grid[i][c - 1] == -1)
                        c--;
                    else
                    {
                        c = -1;
                        break;
                    }
                }
            }
            result.push_back(c);
        }
        
        return result;
    }
};
// @lc code=end