/*
 * @lc app=leetcode id=2570 lang=cpp
 *
 * [2570] Merge Two 2D Arrays by Summing Values
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> result;
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            int n1 = nums1[i][0], n2 = nums2[j][0];
            if (n1 == n2)
            {
                result.push_back({n1, nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }

            else if (n1 < n2)
            {
                result.push_back({n1, nums1[i][1]});
                i++;
            }

            else
            {
                result.push_back({n2, nums2[j][1]});
                j++;
            }
        }

        while (i < n)
        {
            result.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }

        while (j < m)
        {
            result.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }

        return result;
    }
};
// @lc code=end