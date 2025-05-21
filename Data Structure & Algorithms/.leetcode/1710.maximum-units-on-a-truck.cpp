/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] > b[1]; });
        int ans = 0;
        for (auto &box : boxTypes)
        {
            int num = min(box[0], truckSize);
            ans += num * box[1];
            truckSize -= num;
            if (truckSize == 0)
                break;
        }
        return ans;
    }
};
// @lc code=end
