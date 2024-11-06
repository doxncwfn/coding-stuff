/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        set<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back)
                if (nums[front] + nums[back] < target)
                    front++;
                else if (nums[front] + nums[back] > target)
                    back--;
                else
                {
                    res.insert({nums[i], nums[front], nums[back]});
                    front++;
                    back--;
                }
        }
        vector<vector<int>> result(res.begin(), res.end());
        return result;
    }
};
// @lc code=end
