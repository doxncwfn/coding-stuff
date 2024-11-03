/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);

        int l = 0;
        int r = n;
        while (l <= r)
        {
            int i = (l + r) / 2;
            int j = (n + m + 1) / 2 - i;
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == n) ? INT_MAX : nums1[i];
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == m) ? INT_MAX : nums2[j];
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
            {
                if ((n + m) % 2 == 0)
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                else
                    return max(maxLeft1, maxLeft2);
            }
            else if (maxLeft1 > minRight2)
                r = i - 1;
            else
                l = i + 1;
        }
        return 0.0;
    }
};
// @lc code=end
