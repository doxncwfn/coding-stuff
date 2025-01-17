/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
class Solution {
public:
    int maximum69Number (int num)
    {
        vector<int> digits;
        while (num)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] == 6)
            {
                digits[i] = 9;
                break;
            }
        }
        int res = 0;
        for (int i = digits.size() - 1; i >= 0; i--)
            res = res * 10 + digits[i];

        return res;
    }
};
// @lc code=end

