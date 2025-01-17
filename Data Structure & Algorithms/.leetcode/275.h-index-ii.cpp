/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (citations[mid] == n - mid)
                return n - mid;
            else if (citations[mid] < n - mid)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return n - l;
    }
};
// @lc code=end
