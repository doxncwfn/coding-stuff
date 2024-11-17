/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (count == n)
                return true;

            bool before = i == 0 ? 0 : flowerbed[i - 1];
            bool after = i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1];
            if (flowerbed[i] == 0 && !before && !after)
            {
                flowerbed[i] = 1;
                count++;
            }
        }

        return count == n;
    }
};
// @lc code=end