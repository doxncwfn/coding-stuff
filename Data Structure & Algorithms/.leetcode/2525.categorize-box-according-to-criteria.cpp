/*
 * @lc app=leetcode id=2525 lang=cpp
 *
 * [2525] Categorize Box According to Criteria
 */

// @lc code=start
#define ll long long
class Solution
{
public:
    string categorizeBox(int l, int r, int h, int mass)
    {
        bool bulky = (ll)l * (ll)r * (ll)h >= 1e9 || std::max({l, r, h}) >= 1e4,
             heavy = mass >= 100;
        if (bulky && heavy)
            return "Both";
        else if (bulky)
            return "Bulky";
        else if (heavy)
            return "Heavy";
        else
            return "Neither";
    }
};
// @lc code=end
